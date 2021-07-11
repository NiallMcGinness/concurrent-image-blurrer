#include <string>
#include <iostream>

#include <vector>


#include <filesystem>


int main(){

   std::string data_dir = "data";

   auto data_dir_path = std::filesystem::path(data_dir);

   std::cout << "data directory relative path " << data_dir_path << std::endl;

   auto abs_data_directory_path = std::filesystem::absolute(data_dir);

   std::cout << "data directory absolute path " << data_dir_path << std::endl;

}