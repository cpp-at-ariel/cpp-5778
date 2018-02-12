/**
 * Demonstrates destructors
 */

#include <iostream>
using namespace std;

class IntList {
    private:
        int* theInts;
        uint numInts;

    public:
        IntList(uint numInts) {
            theInts = new int[numInts];
            this->numInts = numInts;
        }

        // ~IntList() {
        //     delete[] theInts;
        // }

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
constexpr int SIZE=100000*1024; // 100000 KB

int main() {
    cout << "Before loop" << endl;
    this_thread::sleep_for(chrono::seconds(3));

    for (uint i=0; i<20; ++i) {
        cout << "Before list construction" << endl;
        this_thread::sleep_for(chrono::seconds(3));

        IntList list(SIZE);
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

    return 0;
}
