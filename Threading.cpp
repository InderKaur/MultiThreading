// Threading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<chrono>
#include<thread>
#include "WaysToCreateThreads.cpp"
#include "Join_Detach_Joinable.cpp"
#include "Mutex.cpp"

using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;
void findOddSum(ull start, ull end) {
	//ull oddSum = 0;
	for (ull i = 1; i < end; i += 2) {
		oddSum += i;
	}
//	return oddSum;
}
void findEvenSum(ull start, ull end) {
	//ull evenSum = 0;
	for (ull i = 2; i < end; i += 2) {
		evenSum += i;
	}
	//return evenSum;
}
int main()
{
	/*ull start = 0;
	ull end = 190000000;

	auto start_time = high_resolution_clock::now();
	std::thread t1(findOddSum,start,end);
	std::thread t2(findEvenSum,start,end);

	t1.join();
	t2.join();
	//oddSum = findOddSum();
	//evenSum = findEvenSum();	
	auto end_time = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end_time - start_time);

	cout << "Odd Sum :" << oddSum << endl;
	cout << "Even Sum :" << evenSum << endl;
	cout << "Total Time " << duration.count()/ 10000 << endl;
	*/
	//	waysToCreateThread();
	// join_detach_joinable();
	 mutex_func();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
