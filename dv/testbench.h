// Copyright Flavien Solt, ETH Zurich.
// Licensed under the General Public License, Version 3.0, see LICENSE for details.
// SPDX-License-Identifier: GPL-3.0-only

#include "Variane_tiny_soc.h"
#include "verilated.h"

#if VM_TRACE
#include <verilated_fst_c.h>
#endif // VM_TRACE

#include <iostream>
#include <fstream>
#include <stdlib.h>

#ifndef TESTBENCH_H
#define TESTBENCH_H

typedef Variane_tiny_soc Module;

// This class implements elementary interaction with the design under test.
class Testbench {
 public:
  Testbench(const std::string &trace_filename = "")
      : module_(new Module), tick_count_(0l) {
#if VM_TRACE
    trace_ = new VerilatedFstC;
    module_->trace(trace_, 6);
    trace_->open(trace_filename.c_str());
#endif // VM_TRACE
  }

  ~Testbench(void) { close_trace(); }

  void reset(void) {
    module_->rst_ni = 1;
    this->tick(1);
    module_->rst_ni = 0;
    this->tick(5);
    module_->rst_ni = 1;
  }

  void close_trace(void) {
#if VM_TRACE  
    trace_->close();
#endif // VM_TRACE
  }

  /**
   * Performs one or multiple clock cycles.
   *
   * @param num_ticks the number of ticks to perform.
   */
   // @return false.
  bool tick(int num_ticks = 1, bool false_tick = false) {
    for (size_t i = 0; i < num_ticks || num_ticks == -1; i++) {
      tick_count_++;

      module_->clk_i = 0;
      module_->eval();

#if VM_TRACE
      trace_->dump(5 * tick_count_ - 1);
#endif // VM_TRACE

      module_->clk_i = !false_tick;
      module_->eval();

#if VM_TRACE
      trace_->dump(5 * tick_count_);
#endif // VM_TRACE

      module_->clk_i = 0;
      module_->eval();

#if VM_TRACE
      trace_->dump(5 * tick_count_ + 2);
      trace_->flush();
#endif // VM_TRACE
    }
    return false;
  }

  std::unique_ptr<Module> module_;
  std::vector<std::vector<uint64_t>> recording_strings;
 private:
  vluint32_t tick_count_;

#if VM_TRACE
  VerilatedFstC *trace_;
#endif // VM_TRACE

  // Masks that contain ones in the corresponding fields.
  uint32_t id_mask_;
  uint32_t content_mask_;
};

#endif // TESTBENCH_H
