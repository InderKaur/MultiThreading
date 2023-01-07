/*Purpose - Creation of Threads
There are 5 different ways to create threads using callable objects
NOTE: When creating multiple threads, it doesn't guarantee which one will start first	
1. Function Pointer : Basic implementation of thread creation
2. Lambda Function : Inject lambda  at thread creation time
3. Functor : Function Object
4: Non Static member function: When you want to call a method in base class 
5: Static member function : We don't need to pass the object to the thread
*/

#include<iostream>
#include<thread>
using namespace std;

class Base {
public:
	void operator()(int x) {
		while(x--)
			cout << "Print the value " << x << endl;
	}
	void run(int x) {
		cout << " In the Run function" << endl;
		while (x--)
			cout << "Print the value " << x << endl;
	
	}
	static void runStatic(int x) {
		cout << " In the Static Run function" << endl;
		while (x--)
			cout << "Print the value " << x << endl;
	}
};
void func(int x) {
	while (x--) {
		cout << "Print the value " << x << endl;
	}
}

int waysToCreateThread() {
	//1. Function pointer
	//std::thread t1(func, 10); 
      
	//2: Lambda Function
	//A
	auto fun = [](int x) {
		while (x--)
			cout << "Print Value " << x << endl;
	};
	//std::thread t2(fun, 11);
	//B
	/*std::thread t3([](int x) {
		while (x--)
		cout << "Print Value " << x << endl;
		},20);
		*/


     //3: Functor
	// thread t4((Base()), 10);

	 //4: Non Static Function
	 //Base b;
	 //thread t5(&Base::run, &b/*We need a object to call this run function since it is a non static member function*/, 20);
	
	//5: Static Function
	thread t6(&Base::runStatic, 30);
	 
	 
	 //t1.join();
	//t2.join();
	//t3.join();
	// t4.join();
	//	t5.join();
	t6.join();
	return  0;
}