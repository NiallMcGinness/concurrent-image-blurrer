#include <string>
#include <iostream>

#include <vector>


#include <filesystem>

namespace fs = std::filesystem;


std::string help_message(){
    //std::string  help = "this program expects there to be a directory called 'data' in the directory you are running the program from\nand a subdirectory called 'input' containing the files to be processed\n";
      std::string help = "This string will be printed as three\n"
                "lines. You can include as many lines\n"
                "as you wish. They will be concatenated\n";
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


    if (!data_dir_exists){

       auto hm = help_message();

       std::string s1 = "This string will be printed as the"
                " one. You can include as many lines"
                "as you wish. They will be concatenated";

        std::cout << hm << "\n";
    }

}