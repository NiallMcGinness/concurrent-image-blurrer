
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include "../src/getfiles.h"
namespace fs = std::filesystem;

int main(){

   std::string data_dir = "test_data/input_10_items";

   std::cout<< data_dir << "\n";


   GetFiles gf(data_dir);
   std::vector<string> fv = gf.filesInDir();

   std::cout<< fv.size() << "\n";


}