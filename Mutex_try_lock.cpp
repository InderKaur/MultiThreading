/*Few points to remember about the try_lock is as follows :
0. try_lock() Tries to lock the mutex.Returns immediately.On successful lock acquisition returns true otherwise returns false.
1. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non - blocking.
2. If try_lock is called again by the same thread which owns the mutex, the behaviour is undefined.
   It is a dead lock situation with undefined behaviour. (if you want to be able to lock the same mutex by same thread 
   more than one time the go for recursive_mutex)

There are so many try_lock function
1. std::try_lock
2. std::mutex::try_lock
3. std::shared_lock::try_lock
4. std::timed_mutex::try_lock
5. std::unique_lock::try_lock
6. std::shared_mutex::try_lock
7. std::recursive_mutex::try_lock
8. std::shared_timed_mutex::try_lock
9. std::recursive_timed_mutex::try_lock
*/


#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

using namespace std;
using namespace std::chrono;

int myAmount = 0;// Common Data
std::mutex m,m1,m2;

void modify() {
	/*m1.try_lock();
	//m2.try_lock();
	  or
	  std::try_lock(m1,m2);
	  */
	if (m.try_lock()) {
		myAmount++;  // CRITICAL SECTION
		m.unlock();
	}
}


void mutex_try_lock() {
	cout << "Mutex Start" << endl;

	thread t1(modify);
	thread t2(modify);
	t1.join();
	t2.join(); //t2 will be blocked if t1 reaches the modify function first 
	cout << myAmount << endl;
	return;
}