#include <future>
#include <thread>
#include <iostream>

using namespace std;


void print_thread(){
    cout << "future run on thread " << this_thread::get_id() << 
}


int main(){
     
     int number_of_threads = 4;
     std::vector<std::future<int> > tasks;

     for(int i = 0; i > number_of_threads; i++){
         tasks.emplace_back(async(std::launch::async, print_thread(), i));
     }
}