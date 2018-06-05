#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>
using namespace std;
 
int main()
{
    // istringstream str("0.12 0.2 0.3 0.4");
	// istream_iterator<float> b(str);
	// istream_iterator<float> e;
	// for (; b!=e; ++b)
	// 	cout << (*b) << endl;

	// ostream_iterator<double> o(cout,"---");
	// for (double i=0; i<10; ++i)
	// 	(*o) = i;

	int a[4] = {1,2,3,4};
	int b[4];
    //partial_sum(a, a+4,  ostream_iterator<int>(cout, ","));
	// for (int i: b) 
	// 	cout << i << endl;

    partial_sum(istream_iterator<double>(cin),
            	istream_iterator<double>(),
                ostream_iterator<double>(cout, " "));
}