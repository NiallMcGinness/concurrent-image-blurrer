#include "getFiles.h"
#include <filesystem>
#include <iostream>
#include <set>
#include <string>
#include <vector>

namespace fs = std::filesystem;

GetFiles::GetFiles(fs::path directory_path)
{
  this->directory_path = directory_path;
  this->input_dir_path = fs::path(directory_path / "input");
  this->output_dir_path = fs::path(directory_path / "output");
}

fs::path GetFiles::get_output_dir_path() { return this->output_dir_path; }

std::vector<std::string> GetFiles::filesInDir()
{

  std::vector<string> fv;
  auto fs_obj = fs::directory_iterator(this->input_dir_path);

  set<std::string> accepted_file_ext = {".png", ".jpeg", ".jpg"};

  for (auto &p : fs_obj)
  {

    auto p_obj = p.path();

    auto file_ext = p_obj.extension();

    bool file_ext_ok = accepted_file_ext.contains(file_ext);

    if (!file_ext_ok)
      continue;

    string abs = fs::canonical(p).string();

    fv.push_back(abs);
  }

  return fv;
}

vector<vector<std::string>> GetFiles::splitFileList(vector<std::string> fv,
                                                    uint number_of_threads)
{

  std::vector<std::vector<std::string>> c;

  uint number_of_files = fv.size();

  if (number_of_files < 1)
    return c;

  if (number_of_threads < 1)
    number_of_threads = 1;

  if (number_of_threads > number_of_files)
    number_of_threads = number_of_files;

  uint files_per_thread = number_of_files / number_of_threads;

  while (fv.size() > 0)
  {

    if (fv.size() > files_per_thread)
    {
      std::vector<string> sl(fv.begin(), fv.begin() + files_per_thread);

      c.push_back(sl);
      fv.erase(fv.begin(), fv.begin() + files_per_thread);
    }

    else
    {

      c.push_back(fv);
      fv.clear();
    }
  }

  return c;
}

bool GetFiles::input_output_dirs_exist()
{

  fs::path project_root_dir = this->directory_path;

  bool input_dir_exists = fs::is_directory(this->input_dir_path);

  if (!input_dir_exists)
  {

    std::cout << "\nError : no 'input' directory found in "
              << this->input_dir_path << "\n";

    std::string help =
        "\nThis program expects there to be a directory called 'input'\n"
        "in the directory you are running the program from\n"
        "which contains the filesto be processed\n"
        "once processed an output directory will be created containing the "
        "processed files";

    std::cout << help << "\n";

    return false;
  }

  bool output_dir_exists = fs::is_directory(this->output_dir_path);

  if (!output_dir_exists)
  {

    fs::create_directory(this->output_dir_path);
  }

  return (fs::is_directory(this->input_dir_path) &&
          fs::is_directory(this->output_dir_path));
}