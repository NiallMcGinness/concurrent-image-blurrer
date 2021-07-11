

#include "getfiles.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;


GetFiles::GetFiles(string directory_path){
    this->directory_path = directory_path;
}

std::vector<string> GetFiles::filesInDir(){

   std::vector<string> fv;
   auto fs_obj = fs::directory_iterator(this->directory_path);

   for (auto & p : fs_obj){
        //fv.push_back(p);
        auto p_obj = p.path();
        auto abs = fs::canonical(p).string();
        //std::cout << "class instance " << abs  << "\n";
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