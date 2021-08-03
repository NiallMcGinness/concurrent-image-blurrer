#include <string>
#include <iostream>

#include <vector>


#include <filesystem>
#include "../src/getfiles.h"

namespace fs = std::filesystem;


int main(){


    fs::path project_root  = fs::current_path();
    GetFiles gf(project_root);
   
    bool dirs_exist = gf.input_output_dirs_exist();

    if (!dirs_exist){
        std::cout <<  "input / output dirs do not exist, exiting  program" << "\n";

        return 1;
    }

     std::cout <<  project_root << "\n";
    /*

    get list of files in dir 
    send vector of filepaths to opencv image blurrer  
    */


    std::vector<string> input_files_vec =  gf.filesInDir();

    uint number_of_threads = 1;

    vector< vector<string> > file_blocks =  gf.splitFileList(input_files_vec, number_of_threads);
    

    if (file_blocks.size() < 1 ) {
        return 1;
    }
    
    for ( auto &fb : file_blocks){

        std::cout <<  "file_blocks : " << fb.at(0) << "\n";


    }

}


/*

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

*/