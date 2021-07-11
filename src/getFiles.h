

#include <string>
#include <iostream>
#include <vector>

#ifndef GETFILES_H_INCLUDED
#define GETFILES_H_INCLUDED

using namespace std;

class GetFiles {

    public:

        GetFiles(string);
        vector<string> filesInDir();
        vector< vector<string> > splitFileList(vector<string>, uint);

    private:
     string directory_path;

};

#endif