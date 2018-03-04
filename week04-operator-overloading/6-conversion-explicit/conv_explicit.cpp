/**
 * @author Ofir Pele
 * @since 2017
 */
/*
#include <iostream> 
using namespace std;

struct A {
   
   explicit A(int) { 
      cout << "In ctor" << endl; 
   }
   
   A(const A& a) { 
      cout << "In copy ctor" << endl; 
   }
   
   A& operator=(const A& a) { 
      cout << "In operator=" << endl; 
      return *this;
   }
   
};

void f (A a) {
   cout << "In f" << endl;
}

int main() {   
   A a1 = 37; // won't compile
   cout << "-------------------" << endl;
   
   A a2(37);  // compile ok
   cout << "-------------------" << endl;
   
   a1= 67; // won't compile
   cout << "-------------------" << endl;
   
   f(77); // won't compile
   cout << "-------------------" << endl;

   return 0;
}
*/

