/**
 * Demonstrates that memory usage in C++ is accurate.
 * @author erelsgl
 */

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

constexpr int SIZE=125*1000*1024; // 125000 KB

class Point {
	private:
		int x;
		int y;
	public:
		Point() { x = y = 0; }	
};

int main() {
	cout << "Before new" << endl;
	this_thread::sleep_for(chrono::seconds(3));

	Point* p = new Point[SIZE];
	for (int  i=0; i<SIZE; ++i)
		p[i] = Point();

	cout << "After new" << endl;
	// The free memory should drop by a million KB.

	this_thread::sleep_for(chrono::seconds(5));
}
