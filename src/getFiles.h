

#include <string>
#include <iostream>
#include <vector>
#include <filesystem>

#ifndef GETFILES_H_INCLUDED
#define GETFILES_H_INCLUDED

using namespace std;

class GetFiles {

    public:

        GetFiles(filesystem::path);
        vector<string> filesInDir();
        vector< vector<string> > splitFileList(vector<string>, uint);
        bool input_output_dirs_exist();
        filesystem::path get_output_dir_path();
        
    private:
     filesystem::path directory_path;
     filesystem::path input_dir_path;
     filesystem::path output_dir_path;

};

#endif