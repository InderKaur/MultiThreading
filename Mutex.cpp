/*
 TOPIC: What is mutex | Why Use Mutex | Race Condition | How to Solve it | Critical Section

 MUTEX: Mutual Exclusion

 Race Condition:
	When two or more threads compete for some common data and modify that common data, this situation is known as Race Condition.
	We need a lock for such situations. Protected sections are known as critical section.

MUTEX:
  Used to avoid race condition
   use lock(), unlock() on mutex

*/


#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

using namespace std;
using namespace std::chrono;

int myAmount = 0;// Common Data
std::mutex m;

void modify() {
	m.lock();
	myAmount++;  // CRITICAL SECTION
	m.unlock();
}


void mutex_func() {
	cout << "Mutex Start" << endl;

	thread t1(modify);
	thread t2(modify);
	t1.join();
	t2.join(); //t2 will be blocked if t1 reaches the modify function first 
	cout << myAmount << endl;
	return;
}