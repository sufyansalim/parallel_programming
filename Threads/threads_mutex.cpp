//g++ threads_mutex.cpp -o threads_mutex.exe -std=c++11
#include <iostream>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;
using std::thread;
using std::lock_guard;

//Our lock at global scope
std::mutex my_mutex;

void print_func(int id){
    //my_mutex.lock();
   lock_guard<std::mutex> g(my_mutex); // safe way follows RAII -- Resource Allocation is Initialization
    cout<<"Printing from threads: " << id <<endl;
    //my_mutex.unlock();
};

//This function is the entrypoint for our thread
int main(){
    //Create 4 threads an call print function
    thread t0(print_func,0);
    thread t1(print_func,1);
    thread t2(print_func,2);
    thread t3(print_func,3);

    // Wait for the threads to finish
    t0.join();
    t1.join();
    t2.join();
    t3.join();

    return 0;
}