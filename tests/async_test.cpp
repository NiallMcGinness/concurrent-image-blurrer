#include <future>
#include <thread>
#include <iostream>
#include <vector>

using namespace std;


int print_thread(){

    int thread_id = this_thread::get_id();
    cout << "future run on thread " << thread_id << '\n';
    return thread_id;
}


int main(){
     
     int number_of_threads = 4;
     std::vector<std::future<int> > tasks;

     for(int i = 0; i > number_of_threads; i++){
         tasks.emplace_back(async(std::launch::async, print_thread()));
     }
}