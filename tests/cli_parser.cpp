#include <cxxopts.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  try {
    cxxopts::Options options("concurrent image blurrer", "cli flag parser");
    options.add_options()("threads", "number of threads to run program",
                          cxxopts::value<uint>())(
        "cycles", "number of cycles to run", cxxopts::value<uint>());

    const auto result = options.parse(argc, argv);

    if (result.count("threads")) {
      uint threads_flag = result["threads"].as<uint>();
      cout << "threads" << threads_flag << "\n";
    }

    if (result.count("cycles")) {
      uint cycles_flag = result["cycles"].as<uint>();
      cout << "cycles " << cycles_flag << "\n";
    }
  } catch (exception &e) {
    cerr << e.what();
    return -1;
  }
}