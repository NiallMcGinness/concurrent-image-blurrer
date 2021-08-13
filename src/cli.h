#include "cxxopts.h"
#include <fstream>
#include <iostream>
#include <string>

namespace cli {

struct cli_values {
  int threads;
  int cycles;
};

cli_values parse_cli(int argc, char *argv[]) {
  cli_values cli_vals = {1, 1};

  try {
    cxxopts::Options options("concurrent image blurrer", "cli flag parser");
    options.add_options()("t,threads", "number of threads to run program",
                          cxxopts::value<int>())(
        "c,cycles", "number of cycles to run", cxxopts::value<int>());

    const auto result = options.parse(argc, argv);

    if (result.count("threads")) {
      int threads_flag = result["threads"].as<int>();

      cli_vals.threads = threads_flag;
    }

    if (result.count("cycles")) {
      int cycles_flag = result["cycles"].as<int>();

      cli_vals.cycles = cycles_flag;
    }
  } catch (std::exception &e) {
    std::cerr << e.what();
    return cli_vals;
  }

  return cli_vals;
}

} // namespace cli