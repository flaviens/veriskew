// Copyright Flavien Solt, ETH Zurich.
// Licensed under the General Public License, Version 3.0, see LICENSE for details.
// SPDX-License-Identifier: GPL-3.0-only

#include "testbench.h"
#include "ticks.h"

int main(int argc, char **argv, char **env) {

  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(VM_TRACE);

  ////////
  // Initialize testbench.
  ////////

  Testbench *tb = new Testbench(cl_get_tracefile());

  ////////
  // Run the testbench.
  ////////

  tb->reset();

  int simlen = 60;  
  tb->tick(simlen);

  ////////
  // Display the results.
  ////////
  std::cout << "Testbench complete!" << std::endl;
  std::cout << "Elapsed time: " << std::dec << duration << "." << std::endl;

  delete tb;
  exit(0);
}
