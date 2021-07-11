#include <string>
#include <iostream>

#include <vector>
#include "../src/getfiles.h"
#include "../src/cv2utils.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <filesystem>

namespace fs = std::filesystem;

cv::Mat loadFile(string f){

     cv::Mat img = cv::imread(f);

     return img;
    
}

string output_filepath(string input_filepath, string output_dir){
    fs::path fn = fs::path(input_filepath).filename();
   
    string t = "blurred_"  + fn.string();
    std::cout << fn << std::endl;
    fs::path dst_dir = fs::path(output_dir);

     std::cout << "Absolute path output dir " << dst_dir << " is " 
              << std::filesystem::absolute(dst_dir) << '\n';
    fs::path dst_pth = dst_dir / t;
    std::cout << "destination path is " << dst_pth << std::endl;
    std::cout << "Absolute path for " << dst_pth << " is " 
              << std::filesystem::absolute(dst_pth) << '\n';

    return dst_pth.string();

}

void dummy(std::vector<string> fl){

    std::cout << fl.size() << std::endl;
    Cv2utils cvu;
    string output_dir = "../test_data/output_10_items";
    for ( auto &f : fl) {
        std::cout << f << std::endl;
        string s = output_filepath(f,output_dir);
        
        cv::Mat img = cvu.loadFile(f);
        std::cout << img.rows << std::endl;
        cv::Mat blurred_img = cvu.medianBlur_k3(img);
        std::cout << blurred_img.cols << "\n";
        
        string output_fp = output_filepath(f,output_dir);

          std::filesystem::path p = output_fp;
        std::cout << "output filepath " << p << "\n";

         std::cout << "Absolute path for " << p << " is " 
              << std::filesystem::absolute(p) << '\n';

        imwrite(output_fp,blurred_img);
    }

} 




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