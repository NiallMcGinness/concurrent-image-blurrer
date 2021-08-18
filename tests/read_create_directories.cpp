
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include "../src/getFiles.h"
namespace fs = std::filesystem;

int main()
{

    fs::path project_root = fs::current_path();
    GetFiles gf(project_root);

    std::cout << project_root << "\n";

    //GetFiles gf(data_dir);
    std::vector<string> fv = gf.filesInDir();

    std::cout << fv.size() << "\n";

    fs::path output_dir_path = gf.get_output_dir_path();

    std::cout << output_dir_path << "\n";

    fs::path output_dir_path2 = gf.get_output_dir_path();

    std::cout << output_dir_path2 << "\n";
}