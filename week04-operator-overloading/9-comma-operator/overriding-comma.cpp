/**
 * Demo of overriding the comma operator.
 * See: https://stackoverflow.com/a/18136340/827927
 * 
 * Not very useful.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-03
 */

#include <iostream>
using namespace std;

enum myint {};

class IntPair {
	int i, j;
public:
	IntPair(int ii, int jj): i(ii), j(jj) {}
	friend ostream& operator<< (ostream& out, const IntPair& pair);
};

ostream& operator<< (ostream& out, const IntPair& pair) {
	out << pair.i << "," << pair.j;
	return out;
}

IntPair operator, (myint ii, myint jj) {
	return IntPair(ii,jj);
}

int main() {
	IntPair p1(1,2) ;
	cout << "p1 = " << p1 << endl;

	cout << (myint(3),myint(4)) << endl;
	return 0;
}
