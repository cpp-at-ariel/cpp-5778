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
	public:
		void operator() () { cout << "*"; }
		bool operator() (int x) { return x > 0; }
};



template <typename T> void repeat(int n, T action) {
	for (int i=0; i<n; ++i)
		action();
}

template <typename T> void filter(vector<int> v, T condition) {
	for (int i=0; i<v.size(); ++i)
		if (condition(v[i]))
			cout << v[i] << " ";
}


int main() {
	MyFunctor f;
	f(); cout << endl; // prints a star
	cout << endl << f(5) << " " << f(-5) << endl;

	repeat(10, f); cout << endl; // print 10 stars
	vector<int> v {-5,4,-3,2,-1,0};
	filter(v, f);  // prints 4, 2
}


