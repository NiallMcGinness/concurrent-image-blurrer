#include <experimental/filesystem>
#include <iostream>
#include <math.h>
#include <string>
namespace fs = std::experimental::filesystem;
// clang++ ex_read_dir.cpp -lstdc++fs -std=c++17 -o rd.app
std::vector<std::string> get_file_paths(std::string data_dir);
std::vector<std::vector<std::string>>
get_subsections(std::vector<std::string> fp_vect, int number_of_threads);
// clang++ split_dir.cpp -lstdc++fs -std=c++17 -o sd.app

int main() {

  std::string data_dir = "../test_data/10Items";
  std::string file_name, file_extension;
  std::vector<std::string> fp_vect = get_file_paths(data_dir);
  std::cout << fp_vect.size() << "\n";

  uint number_of_threads = 4;

  std::vector<std::vector<std::string>> vs = get_subsections(fp_vect, number_of_threads);
}

std::vector<std::string> get_file_paths(std::string data_dir) {
  std::vector<std::string> fp_vect;

  for (auto &p : fs::directory_iterator(data_dir)) {

    std::string file_path = p.path();
    fp_vect.push_back(file_path);
  }
  return fp_vect;
}

std::vector<std::vector<std::string>>
get_subsections(std::vector<std::string> fp_vect, int number_of_threads) {
  uint vs = fp_vect.size();
  uint section = vs / number_of_threads;

  int section_iter = 0;

  std::vector<std::vector<std::string>> container;
  for (int i = 0; i < number_of_threads; ++i) {
    section_iter = i * section;
    //

    std::cout << "subsection point : " << section_iter << "\n";
    std::vector<std::string>::const_iterator first =
        fp_vect.begin() + section_iter;
    std::vector<std::string>::const_iterator last;
    int end_section = section_iter + section;

    // if the next section end point is less than
    // two sections in length then it should be the last run
    if ((end_section + section) < vs) {
      last = fp_vect.begin() + (section_iter + section);
    } else {
      last = fp_vect.end();
    }

    try {
      std::vector<std::string> v(first, last);
      std::cout << "sebsection vector size : " << v.size() << "\n";
      container.push_back(v);

    } catch (const std::exception &e) {
      std::cout
          << "can't create subsection from filepath vector in this thread";
    }
  }

  return container;
}
