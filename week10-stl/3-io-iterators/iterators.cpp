#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>
using namespace std;
 
int main()
{
    istringstream str("0.12 0.2 0.3 0.4");
	/*
	istream_iterator<char> b(str);
	istream_iterator<char> e;
	for (; b!=e; ++b)
		cout << (*b) << endl;

	ostream_iterator<double> o(cout,"---");
	for (double i=0; i<10; ++i)
		(*o) = i;
	*/
    partial_sum(istream_iterator<double>(str),
            	istream_iterator<double>(),
                ostream_iterator<double>(cout, " "));
}