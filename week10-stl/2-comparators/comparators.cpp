#include <cassert>
#include <iostream>
#include <set>
using namespace std;

struct SederYored {
	bool operator()(int x, int y) {return x>y;}
};

int main() {
	//set<int> s1;
	set<int,SederYored> s1;
	//set<int,greater<int>> s1;
	s1.emplace(5);
	s1.emplace(7);
	s1.emplace(3);
	for (auto s: s1)
		cout << s << endl;
}
