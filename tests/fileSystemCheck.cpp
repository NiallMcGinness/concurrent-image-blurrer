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

fs::path p = fs::current_path();
 
    std::cout << "The current path " << p << " decomposes into:\n"
              << "root name " << p.root_name() << '\n'
              << "root directory " << p.root_directory() << '\n'
              << "relative path " << p.relative_path() << '\n';

}