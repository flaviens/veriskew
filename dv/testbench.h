// Copyright Flavien Solt, ETH Zurich.
// Licensed under the General Public License, Version 3.0, see LICENSE for details.
// SPDX-License-Identifier: GPL-3.0-only

#include "Variane_tiny_soc.h"
#include "verilated.h"
#include "Variane_tiny_soc___024root.h"
#include "Variane_tiny_soc__Syms.h"

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

  // Must be called once at the end of the recording.
  void save_recording(const std::string &recording_filename = "") {
    std::ofstream recording_stream;
    recording_stream.open(recording_filename.c_str());
    recording_stream << recording_strings.size() << '\n';
    for (auto recording_line: recording_strings) {
      for (auto line_token: recording_line)
        recording_stream << line_token << " ";
      recording_stream << "\n";
    }
    recording_stream.close();
  }

  void record_step() {
    std::vector<uint64_t> curr_line;
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.clk_i));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.rst_ni));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.icache_data_req_i));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.dcache_data_req_i));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.icache_data_i));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.dcache_data_i[0]));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.dcache_data_i[1]));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.dcache_data_i[2]));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.dcache_data_i[3]));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.dcache_data_i[4]));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.axi_resp_i[0]));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.axi_resp_i[1]));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.axi_resp_i[2]));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.icache_data_req_i_t0));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.dcache_data_req_i_t0));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.icache_data_i_t0));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.dcache_data_i_t0[0]));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.dcache_data_i_t0[1]));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.dcache_data_i_t0[2]));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.dcache_data_i_t0[3]));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.dcache_data_i_t0[4]));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.axi_resp_i_t0[0]));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.axi_resp_i_t0[1]));
    curr_line.push_back(((uint64_t) module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.axi_resp_i_t0[2]));
    recording_strings.push_back(curr_line);
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
      printf("--Tick %d--\n", tick_count_);

      tick_count_++;

      record_step();

      module_->clk_i = 0;
      // if (module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_0672 | module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_1154)
      //   printf("Before eval 0 - 0672:%lx, 1154:%lx.\n", module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_0672, module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_1154);
      module_->eval();
      // if (module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_0672 | module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_1154)
      //   printf("After  eval 0 - 0672:%lx, 1154:%lx.\n", module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_0672, module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_1154);

#if VM_TRACE
      trace_->dump(5 * tick_count_ - 1);
#endif // VM_TRACE

      record_step();

      module_->clk_i = !false_tick;
      // if (module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_0672 | module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_1154)
      //   printf("Before eval 1 - 0672:%lx, 1154:%lx.\n", module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_0672, module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_1154);
      module_->eval();
      // if (module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_0672 | module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_1154)
      //   printf("After  eval 1 - 0672:%lx, 1154:%lx.\n", module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_0672, module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_1154);

#if VM_TRACE
      trace_->dump(5 * tick_count_);
#endif // VM_TRACE

      record_step();

      module_->clk_i = 0;
      // if (module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_0672 | module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_1154)
      //   printf("Before eval 2 - 0672:%lx, 1154:%lx.\n", module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_0672, module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_1154);
      module_->eval();
      // if (module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_0672 | module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_1154)
      //   printf("After  eval 2 - 0672:%lx, 1154:%lx.\n", module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_0672, module_->rootp->vlSymsp->TOP__ariane_tiny_soc__i_ariane_mem_top__i_ariane__i_cva6__i_cache_subsystem__i_adapter.signal_1154);

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
