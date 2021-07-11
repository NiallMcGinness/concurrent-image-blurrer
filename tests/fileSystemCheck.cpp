#include <string>
#include <iostream>

#include <vector>


#include <filesystem>

namespace fs = std::filesystem;


String help_message(){
    String help = "this program expects there to be a directory called 'data' in the directory you are running the program from\nand a subdirectory called 'input' containing the files to be processed\n"

    return help;
}

int main(){

  // std::string data_dir = "./data";

   /* std::filesystem::path data_dir_path = std::filesystem::path(data_dir);

   std::cout << "data directory found ?  " << data_dir_path.root_directory() << std::endl;

   std::cout << "data directory relative path " << data_dir_path << std::endl;

   auto abs_data_directory_path = std::filesystem::absolute(data_dir);

   std::cout << "data directory absolute path " << data_dir_path << std::endl;

*/

    fs::path project_root  = fs::current_path();
    fs::path data_dir = project_root / "data3";

    bool data_dir_exists = fs::is_directory(data_dir);
    std::cout << "project_root " << project_root << "\n"
              << " data_dir  " << data_dir << '\n'
              << "data dir found ?  " << data_dir_exists  << '\n'
              << "relative path " << project_root.relative_path() << '\n';


    if !(data_dir_exists){
        std::cout << help_message() << "\n";
    }

}