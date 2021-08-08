#include <string>
#include <iostream>

#include <vector>


#include <filesystem>
#include "../src/getfiles.h"

namespace fs = std::filesystem;

void process_file_list(vector<string>,GetFiles);
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

    uint number_of_threads = 1;

    vector< vector<string> > file_blocks =  gf.splitFileList(input_files_vec, number_of_threads);
    

    if (file_blocks.size() < 1 ) {
        return 1;
    }

    /*

    multithreaded  versionwill have one block of files per thread
    in this case we're just testing one thread so the vector of fileblcoks shouldonly have one element 
    */
    
   vector<string> file_list = file_blocks.at(0);
   
   process_file_list(file_list,gf);

}


void process_file_list(vector<string> file_list, GetFiles gf){

    fs::path output_dir_path = gf.get_output_dir_path();

    std::cout <<  "output_dir_path  : " << output_dir_path << "\n";
    for ( auto &file_path : file_list){



        std::cout <<  "file_path  : " << file_path << "\n";
        fs::path file_name = fs::path(file_path).filename();
        std::cout <<  "input file_name   : " << file_name  << "\n";

        fs::path output_filepath = output_dir_path / file_name;

        std::cout <<  "output file psth  : " << output_filepath  << "\n";
        string output_filepath_string =  output_filepath.string();
        std::cout <<  "output file string path   : " << output_filepath_string   << "\n";




    }
}


void load_and_process_image(string input_filepath, string output_filepath){

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



 
    for ( auto &fb : file_blocks){

        std::cout <<  "file_blocks : " << fb.at(0) << "\n";


    }

*/