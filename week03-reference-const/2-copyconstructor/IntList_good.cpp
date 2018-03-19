/**
 * Demonstrates a correct copy constructor.
 * @author Erel Segal-Halevi
 * @since  2018-03
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
    IntList list1{10};
    cout << "list1.get(5) = " << list1.get(5) << endl;
    list1.fill(1);
    cout << "list1.get(5) = " << list1.get(5) << endl;
    list1.get(5) = list1.get(4) + list1.get(6);
    cout << "list1.get(5) = " << list1.get(5) << endl;

    cout << endl << "B. Test the const method: " << endl;
    const IntList& clist = list1;
    //clist.fill(1);  // won't compile
    cout << "clist.get(5) = " << clist.get(5) << endl;
    //clist.get(5) = clist.get(4) + clist.get(6);  // won't compile
    cout << "clist.get(5) + clist.get(6) = " << clist.get(5) + clist.get(6) << endl;

    cout << endl << "C. Test copy constructor:" << endl;
    IntList list2 = list1;  
    // IntList list2 {list1};  // Same as above! 
    cout << "list1.get(5) = " << list1.get(5) << endl;
    cout << "list2.get(5) = " << list2.get(5) << endl;

    list2.get(5)=7;
    cout << "list1.get(5) = " << list1.get(5) << endl;
    cout << "list2.get(5) = " << list2.get(5) << endl;

    return 0;
}
