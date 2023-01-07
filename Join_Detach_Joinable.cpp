/* TOPIC
*  join(), detach() , joinable()
* 
* JOIN :
*   1) Once the thread is started, we wait for it to end by using join function on thread object
*   2) Double join will terminate the project after throwing system_error (Not allowed)
*   3) If needed, we can check if thread is joinable before joining.( using joinable() function)
* 
* DETACH
* 1) Used to attach a newly created thread from parent thread	
* 2) If we have detached a thread from main thread and when main thread terminates, detached thread is suspended on it's own
  3) Check before detaching whether the thread is joinable or not. Double detaching can lead to system_error

  NOTE:
    Once created thread must be join() or detach() because while creating the object of thread, it becomes joinable 
	and when none of the above function is called on the thread, it would remain joinable only(instead of becoming
	non-joinable). Desctructor of thread would check for this. If it is joinable, it would terminate the program
 */


#include<iostream>
#include<thread>
#include<chrono>

using namespace std;
using namespace std::chrono;

void funtion(int x) {
	while (x--) {
		cout << "Running a thread" << endl;
	}
	
	cout << "Thread finished" << endl;
}
int join_detach_joinable() {

	thread t1(funtion, 10);
	/*t1.join();
	if(t1.joinable())
		t1.join();
	*/
	t1.detach();
	this_thread::sleep_for(chrono::seconds(10)); 
	cout << "After main()" << endl;
	return 0;
}