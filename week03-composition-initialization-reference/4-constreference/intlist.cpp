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
            theInts = new int[numInts];
            this->numInts = numInts;
        }

        ~IntList() {
             delete[] theInts;
        }

        void fill(int value) {
            for (uint i=0; i<this->numInts; ++i)
                theInts[i] = value;
        }

        int get(uint index) const {
            cout << "C";
            return theInts[index];
        }

        int& get(uint index) {
            cout << "R";
            return theInts[index];
        }
};

int main() {
    IntList list(10);
    list.fill(1);

    cout << list.get(5) << endl;

    const IntList clist(10);
    //clist.fill(1);  // won't compile
    cout << clist.get(5) << endl;

    list.get(5) = list.get(4) + list.get(6);
    cout << list.get(5) << endl;

    //clist.get(5) = clist.get(4) + clist.get(6);  // won't compile
    list.get(5) = clist.get(4) + clist.get(6); 
    cout << clist.get(5) << endl;

    return 0;
}
