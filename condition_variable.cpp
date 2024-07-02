#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

std::condition_variable cv;
std::mutex mtx;
enum class SIGNAL{
    RED,
    YELLOW,
    GREEN
};
SIGNAL sig = SIGNAL::RED;
void signal_red(){

   // this_thread::sleep_for(chrono::seconds(5));
    cout << "SIGNAL RED" << endl;
    sig = SIGNAL::YELLOW;
    cv.notify_one();
}

void signal_yellow(){
    this_thread::sleep_for(chrono::seconds(5));
    unique_lock<mutex>lock(mtx);  
    cv.wait(lock,[]{return sig==SIGNAL::YELLOW;});
    cout << "SIGNAL YELLOW" <<endl; 

    sig = SIGNAL::GREEN;
    cv.notify_one();
}

void signal_green(){
  //  this_thread::sleep_for(chrono::seconds(5));
    unique_lock<mutex>lock(mtx);  
    cv.wait(lock,[]{return sig==SIGNAL::GREEN;});
    cout << "SIGNAL GREEN" <<endl; 
   
}


int main(){

 thread red(signal_red);
 thread yellow(signal_yellow);
 thread green(signal_green);

 red.join();
 yellow.join();
 green.join();

    return 0;
}