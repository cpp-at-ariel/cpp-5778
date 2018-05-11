#include <cassert>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

template <typename T, int n> class array {
	T vals[n];
public:
	int& operator[](int i) {
		assert(i<n);
		return vals[i];
	}
	int operator[](int i) const {
		assert(i<n);
		return vals[i];
	}
};

template <typename T, int n> ostream& operator<< (ostream& out, const array<T,n>& thearray) {
	for (int i=0; i<n; ++i)
		out << thearray[i] << " ";
	return out;
}


int main() {
	array<int,5> array5;
	cout << array5 << endl;
	array5[0] = 99999;
	cout << array5 << endl << endl;

	array<int,3> array3;     // a different class!
	cout << array3 << endl;  // a different operator<<!
	array3[0] = 99999;
	cout << array3 << endl<< endl;
}
