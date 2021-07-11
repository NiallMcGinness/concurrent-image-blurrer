#include <string>
#include <iostream>

#include <vector>


#include <filesystem>

namespace fs = std::filesystem;

int main(){

  // std::string data_dir = "./data";

   /* std::filesystem::path data_dir_path = std::filesystem::path(data_dir);

   std::cout << "data directory found ?  " << data_dir_path.root_directory() << std::endl;

   std::cout << "data directory relative path " << data_dir_path << std::endl;

   auto abs_data_directory_path = std::filesystem::absolute(data_dir);

   std::cout << "data directory absolute path " << data_dir_path << std::endl;

*/

    fs::path project_root  = fs::current_path();
    fs::path data_dir = project_root / "data";

    bool is_dir = data_dir.is_directory();
    std::cout << "project_root " << project_root << "\n"
              << " data_dir  " << data_dir << '\n'
              << "root directory " << is_dir << '\n'
              << "relative path " << project_root.relative_path() << '\n';

}