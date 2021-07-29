#include <future>
#include <thread>
#include <iostream>
#include <vector>

using namespace std;


thread::id print_thread(int run_number){

    thread::id thread_id = this_thread::get_id();
    cout << "thread id" << thread_id << "run number " << run_number <<'\n';
    return thread_id;
}


int main(){
     
     int number_of_threads = 4;
     std::vector<std::future<thread::id> > tasks;
    {
        for(int i = 0; i > number_of_threads; i++){
            tasks.emplace_back(async(std::launch::async, print_thread,i));
        }

    }

    for (auto& task : tasks){
        cout << " taskresult  " << task.get() << "\n";
    }

     cout << " prog run  " << endl;
}