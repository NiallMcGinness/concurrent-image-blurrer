#include <string>
#include <iostream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
//clang++ ex_read_dir.cpp -lstdc++fs -std=c++17 -o rd.app
int main()
{
    std::string data_dir = "../test_data/10Items";
    std::string file_name, file_extension;
    
    for (auto & p : fs::directory_iterator(data_dir)){
        file_name = p.path().filename();
        std::cout << file_name  << std::endl;
        //std::cout << p.path().filename() << std::endl;
        std::string file_path = p.path();
        std::cout << file_path  << std::endl;

        //fs::path pathToShow(p.path().str());
    } 
}
