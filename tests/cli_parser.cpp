#include "../src/cxxopts.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  try {
    cxxopts::Options options("concurrent image blurrer", "cli flag parser");
    options.add_options()("t,threads", "number of threads to run program",
                          cxxopts::value<int>())(
        "c,cycles", "number of cycles to run", cxxopts::value<int>());

    const auto result = options.parse(argc, argv);

    if (result.count("threads")) {
      int threads_flag = result["threads"].as<int>();
      cout << "threads : " << threads_flag << "\n";
    }

    if (result.count("cycles")) {
      int cycles_flag = result["cycles"].as<int>();
      cout << "cycles : " << cycles_flag << "\n";
    }
  } catch (exception &e) {
    cerr << e.what();
    return -1;
  }
}