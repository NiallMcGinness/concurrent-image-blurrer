#include <string>
#include <iostream>

#include <vector>


#include <filesystem>
#include "../src/getfiles.h"


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
    GetFiles gf(project_root);
   
    bool dirs_exist = gf.input_output_dirs_exist();

    if (!dirs_exist){
         std::cout <<  help_message() << "\n";

        return 1;
    }

    std::cout <<  dirs_exist  << "\n";

}