#include <string>
#include <iostream>

#include <vector>


#include <filesystem>

namespace fs = std::filesystem;


std::string help_message(){
      std::string help = "\nThis program expects there to be a directory called 'data'\n"
                         "in the directory you are running the program from\n" 
                         "and a subdirectory called 'input' containing the files to be processed\n";
                
    return help;
}

int main(){



    fs::path project_root  = fs::current_path();
    fs::path data_dir = project_root / "data";

    bool data_dir_exists = fs::is_directory(data_dir);


    if (!data_dir_exists){


        std::cout << help_message() << "\n";
    }

   
     
    fs::path input_dir = project_root / "data" / "input";

    bool input_dir_exists = fs::is_directory(input_dir);

    if (!input_dir_exists){


        std::cout << help_message() << "\n";
    }

     std::cout << "project_root " << project_root << "\n"
              << "data_dir  " << data_dir << '\n'
              << "data dir found ?  " << data_dir_exists  << '\n'
              << "relative path " << project_root.relative_path() << '\n';


}