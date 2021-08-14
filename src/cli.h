#include "cxxopts.h"
#include <fstream>
#include <iostream>
#include <string>

namespace cli
{

  struct cli_values
  {
    uint threads;
    uint cycles;
  };

  std::string help_message()
  {

    std::string msg = "This program scans png or jpeg files in a directory called 'input', processes each file, blurring the image before saving the resultto an output folder\n"
                      "It can accept two flags, --threads and --cycles\n"
                      "if no flags are enterted both values default to 1\n";

    return msg;
  }

  cli_values parse_cli(int argc, char *argv[])
  {
    cli_values cli_vals = {1, 1};

    try
    {
      cxxopts::Options options("concurrent image blurrer", "cli flag parser");
      options.add_options()("t,threads", "number of threads to run program",
                            cxxopts::value<uint>())(
          "c,cycles", "number of cycles to run", cxxopts::value<uint>())("h,help", "Print usage");

      const auto result = options.parse(argc, argv);

      if (result.count("help"))
      {
        cli_vals.threads = 0;
        cli_vals.cycles = 0;

        std::string help_msg = help_message();
        std::cout << help_msg << std::endl;
      }

      if (result.count("threads"))
      {
        uint threads_flag = result["threads"].as<uint>();

        cli_vals.threads = threads_flag;
      }

      if (result.count("cycles"))
      {
        uint cycles_flag = result["cycles"].as<uint>();

        cli_vals.cycles = cycles_flag;
      }
    }
    catch (std::exception &e)
    {
      std::cerr << e.what();
      return cli_vals;
    }

    return cli_vals;
  }

} // namespace cli