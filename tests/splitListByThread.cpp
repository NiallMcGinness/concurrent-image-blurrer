#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include "../src/getfiles.h"
namespace fs = std::filesystem;


std::vector< std::vector<string> > loop(std::vector<string> fv) {
   uint number_of_files =  fv.size();

   std::cout << number_of_files << std::endl;

   uint number_of_threads = 4;
   uint files_per_thread = number_of_files / number_of_threads;
 
   std::vector< std::vector<string> > c;
   while (fv.size() > 0) {

       std::cout << fv.size() << std::endl;
       if (fv.size() > files_per_thread ) {
            std::vector<string> sl(fv.begin(), fv.begin() + files_per_thread);
            //dummy_func(sl);
            c.push_back(sl);
            fv.erase(fv.begin(), fv.begin() + files_per_thread);

       }
       
       else {
          // dummy_func(fv);
           c.push_back(fv);
           fv.clear();
       }

   }

   return c;

}

int main(){

   std::string data_dir = "../data/";

   GetFiles gf(data_dir);
   std::vector<string> fv = gf.filesInDir();
   std::cout << fv.size() << std::endl;
    uint number_of_threads = 12;
    std::vector< std::vector<string> >  ci = gf.splitFileList(fv,number_of_threads);
    std::cout << ci.size() << std::endl;

}