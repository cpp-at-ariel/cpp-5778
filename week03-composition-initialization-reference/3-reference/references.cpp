/**
 * Demonstrates references in C++.
 * @author Erel Segal-Halevi
 * @since 2018-02
 */

#include <iostream>
using namespace std;


int f11() {
    return 11;
}

int globalnum = 12;

int& f12() {
    return globalnum;
}

int main() {
    int num = 1;
    int x = 2; 

    // int* pnum = &num;
    // cout << pnum << " " << *pnum << " " << num << endl;
    // (*pnum) = 2;
    // cout << pnum << " " << *pnum << " " << num << endl;

    int& rnum = num;
    cout << &rnum << " " << rnum << " " << num << endl;
    rnum = 3;
    cout << &rnum << " " << rnum << " " << num << endl;
    rnum = x;
    cout << &rnum << " " << rnum << " " << num << endl;

    // int othernum = 4;
    // rnum = othernum;
    // rnum = 5;
    // cout << &rnum << " " << rnum << " " << num << " " << othernum << endl;

    //int& rnum2 = 10; // error
    //int& rnum2 = f1(); // error
    const int& crnum1 = 6; // OK
    const int& crnum2 = f11(); // OK
    const int& crnum3 = f12(); // OK
    //crnum1 = 7; // error: expression must be a modifiable lvalue

    cout << &crnum1 << " " << crnum1 << " " 
         << &crnum2 << " " << crnum2 << " " 
         << &crnum3 << " " << crnum3 << " " 
         << endl;

    int& rnum2 = f12(); // OK
    rnum2 = 13; // changes globalnum
    cout << &rnum2 << " " << rnum2 << " " << globalnum << endl;

    //int* nullnumptr = nullptr;
    //int& nullnumref = *nullnumptr;
    //cout << nullnumptr << endl << &nullnumref << endl << (*nullnumptr) << endl << nullnumref << endl; // segmentation fault
}
