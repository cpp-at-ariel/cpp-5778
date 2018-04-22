/**
 * Demo of the Functor objects.
 * 
 * @author Erel Segal-Halevi
 * @since 2017
 */

#include <iostream>
#include <vector>

using namespace std;

class MyFunctor {
		char _x;
	public:
		MyFunctor(char x='*') { _x = x; }
		MyFunctor(int x) {  }
		void operator() () { cout << _x; }
		bool operator() (int x) { return x > 0; }
};

void repeat(int n, MyFunctor action) {
	for (int i=0; i<n; ++i)
		action();
}

void filter(vector<int> v, MyFunctor condition) {
	for (int i=0; i<v.size(); ++i)
		if (condition(v[i]))
		// equivalent to: if (condition.operator()(v[i]))
			cout << v[i] << " ";
}

int main() {
	MyFunctor f;
	f(); cout << endl; // prints a star
	cout << endl << f(5) << " " << f(-5) << endl;

	repeat(10, f); cout << endl; // print 10 stars
	repeat(10, MyFunctor('^'));    cout << endl;

	vector<int> v {-5,4,-3,2,-1,0};
	filter(v, f);  // prints 4, 2
}
