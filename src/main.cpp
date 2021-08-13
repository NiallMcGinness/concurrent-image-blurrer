#include "cli.h"
#include "cxxopts.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {

  cli::cli_values cli_vals = cli::parse_cli(argc, argv);

  cout << "cli vals\nthreads : " << cli_vals.threads
       << "\ncycles : " << cli_vals.cycles << endl;
}