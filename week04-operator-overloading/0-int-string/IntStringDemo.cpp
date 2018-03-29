/**
 * Demonstrates operator overloading in C++.
 * @author Erel Segal-Halevi
 * @since 2018-03
 */

#include <iostream>
using namespace std;

string operator* (int n, string s){ 
    string result = s;
    for (int i=1; i<n; ++i)
        result += s;
    return result;
}


// string operator* (string s, int n) {
//     return n*s;
// }

int main() {
    string x="abc";
    cout << (3 * x) << endl;
    //cout << (x * 3) << endl;
    return 0;
}
