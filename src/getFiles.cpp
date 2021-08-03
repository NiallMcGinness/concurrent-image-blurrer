#include "getfiles.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;


GetFiles::GetFiles(fs::path directory_path){
    this->directory_path = directory_path;
}

std::vector<string> GetFiles::filesInDir(){

   std::vector<string> fv;
   auto fs_obj = fs::directory_iterator(this->directory_path);

   for (auto & p : fs_obj){
       
        auto p_obj = p.path();
        auto abs = fs::canonical(p).string();
        
        fv.push_back(abs);
   }
       
    
    return fv;


}


 vector< vector<string> > GetFiles::splitFileList(vector<string> fv, uint number_of_threads){
     uint number_of_files =  fv.size();

   

   if (number_of_threads < 1)
            number_of_threads = 1;
   
   if ( number_of_threads > number_of_files)
            number_of_threads = number_of_files;

   uint files_per_thread = number_of_files / number_of_threads;
 
   std::vector< std::vector<string> > c;
   while (fv.size() > 0) {

       
       if (fv.size() > files_per_thread ) {
            std::vector<string> sl(fv.begin(), fv.begin() + files_per_thread);
           
            c.push_back(sl);
            fv.erase(fv.begin(), fv.begin() + files_per_thread);

       }
       
       else {
          
           c.push_back(fv);
           fv.clear();
       }

   }

   return c;
 }



bool GetFiles::input_output_dirs_exist(){
    
   fs::path project_root_dir = this->directory_path;
    
    
    fs::path input_dir = project_root_dir  / "input";

    bool input_dir_exists = fs::is_directory(input_dir);


    if (!input_dir_exists){


        std::cout << "\nError : no 'input' directory found in " << project_root_dir << "\n";

        std::string help = "\nThis program expects there to be a directory called 'input'\n"
                         "in the directory you are running the program from\n" 
                         "which contains the filesto be processed\n"
                         "once processed an output directory will be created containing the processed files";

        std::cout <<  help << "\n";
        
    
        return false;
    }

    std::cout << "\nproject_root dir : " << project_root_dir << "\n";

    fs::path output_dir = project_root_dir / "output";

    bool output_dir_exists = fs::is_directory(output_dir);


    if (!output_dir_exists){

        fs::create_directory(output_dir);
       
    }


    return ( fs::is_directory(input_dir) && fs::is_directory(output_dir) );

         

}