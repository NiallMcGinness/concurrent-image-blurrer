#include <string>
#include <iostream>

#include <vector>


#include <filesystem>

namespace fs = std::filesystem;


std::string help_message(){
      std::string help = "\nThis program expects there to be a directory called 'input'\n"
                         "in the directory you are running the program from\n" 
                         "which contains the filesto be processed\n"
                         "once processed an output directory will be created containing the processed files";
                
    return help;
}

int main(){



    fs::path project_root  = fs::current_path();
    fs::path input_dir = project_root / "input";

    bool input_dir_exists = fs::is_directory(input_dir);


    if (!input_dir_exists){


        std::cout << "\nError : no 'input' directory found in " << project_root << "\n";

        std::cout <<  help_message() << "\n";

        return 0;
    }

    std::cout << "\nproject_root dir : " << project_root << "\n";

    fs::path output_dir = project_root / "output";

    bool output_dir_exists = fs::is_directory(output_dir);


    if (!output_dir_exists){

        fs::create_directory(output_dir);
        std::cout << "\noutput dir created : " << output_dir << "\n";
    }



}