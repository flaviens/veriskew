// Copyright Flavien Solt, ETH Zurich.
// Licensed under the General Public License, Version 3.0, see LICENSE for details.
// SPDX-License-Identifier: GPL-3.0-only

#include "testbench.h"
#include "ticks.h"

// Stops when zero data is written to address 0, or if the PC is auxed (if applicable)
#define RUNMORETICKS_AFTER_STOP 50 // Run a bit longer in case something interesting still happens
static inline long tb_run_ticks_stoppable(Testbench *tb, int simlen, bool reset = false) {
  if (reset)
    tb->reset();

  bool got_stop_req = false;
  bool got_pc_auxed = false;
  int remaining_before_stop = RUNMORETICKS_AFTER_STOP;

  auto start = std::chrono::steady_clock::now();
  for (size_t step_id = 0; step_id < simlen; step_id++) {
    tb->tick();

    if (step_id == simlen-1)
      std::cout << "Reached simulation length (" << simlen << " cycles). Stopping." << std::endl;
  }
  auto stop = std::chrono::steady_clock::now();
  long ret = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
  return ret;
}

/**
 * Runs the testbench.
 *
 * @param tb a pointer to a testbench instance
 * @param simlen the number of cycles to run
 */
static unsigned long run_test(Testbench *tb, int simlen, bool reset) {
    return tb_run_ticks_stoppable(tb, simlen, reset);
}

int main(int argc, char **argv, char **env) {

  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(VM_TRACE);

  ////////
  // Get the env vars early to avoid Verilator segfaults.
  ////////

  int simlen = 60;

  ////////
  // Initialize testbench.
  ////////

  Testbench *tb = new Testbench(cl_get_tracefile());

  ////////
  // Run the testbench.
  ////////

  unsigned int duration = run_test(tb, simlen, true);

  ////////
  // Save the recording.
  ////////

  tb->save_recording(cl_get_recordingfile());

  ////////
  // Display the results.
  ////////
  std::cout << "Testbench complete!" << std::endl;
  std::cout << "Elapsed time: " << std::dec << duration << "." << std::endl;

  delete tb;
  exit(0);
}
