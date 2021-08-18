#include "cli.h"
#include "cxxopts.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <filesystem>

#include "cv2utils.h"
#include "getFiles.h"
#include <chrono>
#include <future>

namespace fs = std::filesystem;

bool image_blurrer(uint);
void process_file_list(vector<std::string>, GetFiles);
void load_and_process_image(std::string, std::string);

int main(int argc, char *argv[])
{

  cli::cli_values cli_vals = cli::parse_cli(argc, argv);

  cout << "cli vals\nthreads : " << cli_vals.threads
       << "\ncycles : " << cli_vals.cycles << endl;

  for (int i = 0; i < cli_vals.cycles; i++)
  {
    bool run_success = image_blurrer(cli_vals.threads);
  }
}

bool image_blurrer(uint number_of_threads)
{
  fs::path project_root = fs::current_path();
  GetFiles gf(project_root);

  bool dirs_exist = gf.input_output_dirs_exist();

  if (!dirs_exist)
  {
    std::cout << "input / output dirs do not exist, exiting  program"
              << "\n";

    return false;
  }

  std::vector<std::string> input_files_vec = gf.filesInDir();

  std::cout << "number_of_threads   : " << number_of_threads << "\n";

  vector<vector<std::string>> file_blocks =
      gf.splitFileList(input_files_vec, number_of_threads);

  if (file_blocks.size() < 1)
  {
    return false;
  }

  fs::path output_dir_path = gf.get_output_dir_path();
  std::cout << output_dir_path << "\n";
  for (auto &file_block : file_blocks)
  {

    async(std::launch::async, process_file_list, file_block, gf);
  }

  return true;
}

void process_file_list(vector<std::string> file_list, GetFiles gf)
{

  fs::path output_dir_path = gf.get_output_dir_path();
  std::cout << "output_dir_path  : " << output_dir_path
            << "\n";
  for (auto &file_path : file_list)
  {

    fs::path file_name = fs::path(file_path).filename();
    std::cout << "output file file_name  : " << file_name
              << "\n";
    fs::path output_filepath = output_dir_path / file_name;

    std::string output_filepath_string = output_filepath.string();
    std::cout << "output file string path   : " << output_filepath_string
              << "\n";
    load_and_process_image(file_path, output_filepath);
  }
}

void load_and_process_image(std::string input_filepath,
                            std::string output_filepath)
{

  Cv2utils cvu;
  cv::Mat img = cvu.loadFile(input_filepath);

  cv::Mat blurred_img = cvu.medianBlur_k3(img);
  std::cout << "writing file to   : " << output_filepath
            << "\n";
  imwrite(output_filepath, blurred_img);
}
