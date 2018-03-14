/**
 * Demonstrates destructors and memory leaks.
 * 
 * To run the demo, open "top" in another window,
 * then run this program and watch the changes in the free memory.
 */

#include <iostream>
using namespace std;

class IntList {
    private:
        int* theInts;
        uint numInts;

    public:
        IntList(uint numInts) {
            cout << "construct" << endl;
            theInts = new int[numInts];
            this->numInts = numInts;
        }

        ~IntList() {
            cout << "destruct" << endl;
            delete[] theInts;
        }

        void fill(int value) {
            for (uint i=0; i<this->numInts; ++i)
                theInts[i] = value;
        }

        int get(uint index) {
            return theInts[index];
        }  

        void put(uint index, int value) {
            theInts[index] = value;
        }
};

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
    //cout << p->get(5) << endl;  // Segmentation fault

    cout << "After loop" << endl;
    this_thread::sleep_for(chrono::seconds(3));


    //IntList* listArray = new IntList[10];
    //vector<int>* a = new vector<int>[10];
    return 0;
}
