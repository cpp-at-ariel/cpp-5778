namespace abc{
	int x = 2;
};

namespace def{
	int x = 3;
};

#include <iostream>


int main() {
	std::cout << abc::x << std::endl;
	std::cout << def::x << std::endl;
}
