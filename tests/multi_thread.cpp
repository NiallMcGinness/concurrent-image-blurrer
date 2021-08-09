#include <string>
#include <iostream>

#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <filesystem>
#include "../src/getfiles.h"
#include "../src/cv2utils.h"

namespace fs = std::filesystem;

void process_file_list(vector<string>,fs::path);
void load_and_process_image(string,string);

int main(){


    fs::path project_root  = fs::current_path();
    GetFiles gf(project_root);
   
    bool dirs_exist = gf.input_output_dirs_exist();

    if (!dirs_exist){
        std::cout <<  "input / output dirs do not exist, exiting  program" << "\n";

        return 1;
    }

    /*

    get list of files in dir 
    send vector of filepaths to opencv image blurrer  
    */


    std::vector<string> input_files_vec =  gf.filesInDir();

    uint number_of_threads = 2;

    vector< vector<string> > file_blocks =  gf.splitFileList(input_files_vec, number_of_threads);
    

    if (file_blocks.size() < 1 ) {
        return 1;
    }

    fs::path output_dir_path = gf.get_output_dir_path();

    for ( auto &file_block : file_blocks){
       
       process_file_list(file_block,output_dir_path);

    }
    
  /* vector<string> file_list = file_blocks.at(0);
   
   process_file_list(file_list,gf);

 */

}


void process_file_list(vector<string> file_list, fs::path output_dir_path){

    

 
    for ( auto &file_path : file_list){

        fs::path file_name = fs::path(file_path).filename();
        fs::path output_filepath = output_dir_path / file_name;

        string output_filepath_string =  output_filepath.string();
        std::cout <<  "output file string path   : " << output_filepath_string   << "\n";
        load_and_process_image(file_path, output_filepath);

    }
}


void load_and_process_image(string input_filepath, string output_filepath){

    Cv2utils cvu;
    cv::Mat img = cvu.loadFile(input_filepath);
   
    cv::Mat blurred_img = cvu.medianBlur_k3(img);
   
    imwrite(output_filepath, blurred_img );
}

