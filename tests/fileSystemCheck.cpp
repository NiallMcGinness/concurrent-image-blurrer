#include <string>
#include <iostream>

#include <vector>
#include "../src/getfiles.h"
#include "../src/cv2utils.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <filesystem>


int main(){

   std::string data_dir = "../test_data/input_10_items";

   GetFiles gf(data_dir);
   std::vector<string> fv = gf.filesInDir();
   std::cout << fv.size() << std::endl;
    uint number_of_threads = 5;
    std::vector< std::vector<string> >  ci = gf.splitFileList(fv,number_of_threads);
    std::cout << ci.size() << std::endl;
     dummy(ci.at(0));
}