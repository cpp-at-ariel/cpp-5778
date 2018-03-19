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
        IntList(uint newNumInts): 
            numInts(newNumInts), 
            theInts(new int[newNumInts]) 
            {  }

        /* Copy constructor */
        IntList(const IntList& other): IntList(other.numInts) {
            cout << "o";
            for (uint i=0; i<numInts; ++i)
                theInts[i] = other.theInts[i];
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

    cout << endl << "A. Test the non-const method: " << endl;
    IntList list{10};
    list.fill(1);
    cout << list.get(5) << endl;
    list.get(5) = list.get(4) + list.get(6);
    cout << list.get(5) << endl;

    cout << endl << "B. Test the const method: " << endl;
    const IntList& clist = list;
    //clist.fill(1);  // won't compile
    cout << clist.get(5) << endl;
    //clist.get(5) = clist.get(4) + clist.get(6);  // won't compile
    cout << clist.get(5) + clist.get(6) << endl;

    cout << endl << "C. Test the copy constructor:" << endl;
    IntList list2 {list};   // Calls the copy-constructor. Recommended syntax.
    //IntList list2(list);  // Calls the copy-constructor; but might be ambiguous in some cases (looks like a function).    //IntList list2 = list;
    //IntList list2 = IntList(list); // Calls the copy-constructor. In theory, might call it twice.
    //IntList list2 = list; // Same as above!
    cout << list2.get(5) << endl;

    list2.get(6)=3;
    cout << list2.get(6) << endl;
    cout << list.get(6) << endl;

    return 0;
}
