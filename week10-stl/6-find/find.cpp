#include <cassert>
#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
	cout << boolalpha;

	set<int> s1 = {1,7,3,5};
	auto i4 = s1.find(99);

	cout << (i4 == s1.end()) << endl; // true
	cout << (*i4) << endl;  // meaningless

	cout << (s1.find(5) == s1.end()) << endl; // false
	cout << (*s1.find(5)) << endl;  // 5

	cout << (*s1.lower_bound(4)) << endl;  // 5
	cout << (*s1.upper_bound(4)) << endl;  // 5

	cout << (*s1.lower_bound(5)) << endl;  // 5
	cout << (*s1.upper_bound(5)) << endl;  // 7
}
