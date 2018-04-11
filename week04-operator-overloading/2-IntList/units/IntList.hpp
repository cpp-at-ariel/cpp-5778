#pragma once

#include <iostream>
using namespace std;

class IntList {
    private:
        int* theInts;
        uint numInts;

    public:
        IntList(uint numInts) {
            cout << "construct(" << numInts << ")" << endl;
            theInts = new int[numInts];
            this->numInts = numInts;
        }

        ~IntList() {
            cout << "destruct" << endl;
            delete[] theInts;
        }

        void operator=(int value);
        int operator[](uint index) const;
        int& operator[](uint index);
};
