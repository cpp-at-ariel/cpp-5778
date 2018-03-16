/**
 * Demonstrates memory leaks.
 * 
 * To run the demo, open "top" in another window,
 * then run this program and watch the changes in the free memory.
 * 
 * @author Erel Segal-Halevi
 * @since  2018-03
 */
#include "units/IntList.hpp"

#include <iostream>
using namespace std;

#include <thread>
#include <chrono>
#include <vector>
constexpr int SIZE=100000*1024; // 100000 KB


int main() {
    cout << "Before loop" << endl;
    this_thread::sleep_for(chrono::seconds(3));

    IntList* p;
    for (uint i=0; i<20; ++i) {
        cout << "Before list construction" << endl;
        this_thread::sleep_for(chrono::seconds(3));

        IntList list(SIZE);
        p = &list;
        cout << list.get(5) << endl;
        list.fill(9);
        cout << list.get(5) << endl;
        list.put(5, 100);
        cout << list.get(5) << endl;

        cout << "After list construction" << endl;
        this_thread::sleep_for(chrono::seconds(3));
    }

    cout << "After loop" << endl;
    this_thread::sleep_for(chrono::seconds(3));

    //IntList* listArray = new IntList[10];
    //vector<int>* a = new vector<int>[10];
    return 0;
}
