//g++ call_from.cpp -lpthread -o call_from.exe
#include <iostream>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;
using std::thread;

//Mutex for critical section
std::mutex mtx;

// Initial function for each thread
void call_from(int tid) {
  mtx.lock();
  cout << "Launched by thread " << tid << endl;
  mtx.unlock();
}

int main() {
  // Create an array of 10 thread objects
  thread t[10];

  // Launch 10 threads with initial function "call_from(...)"
  for (int i = 0; i < 10; i++) {
    t[i] = thread(call_from, i);
  }

    //Print from main function
    mtx.lock();
    cout << "Launched from main " << endl;
    mtx.unlock();

  // Wait for all threads to complete (in order)
  for (int i = 0; i < 10; i++) {
    t[i].join();
  }

  return 0;
}