#include <iostream>
using std::cout;
using std::endl;

template <typename T> void swap(T& a, T& b) {
	cout << "swap Ts" << endl;
	T tmp = a;
	a = b;
	b = tmp;
}

void swap (double& a, double& b) {
	cout << "swap doubles" << endl;
	a = a + b;
	b = a - b;
	a = a - b;
}

class DontCopyMe {
public:
	DontCopyMe() {}
private:
	DontCopyMe(const DontCopyMe& other) {}
};

int main() {
	{
		int a=4,b=5;
		cout << a << " " << b << endl;
		swap(a,b);
		cout << a << " " << b << endl;
	}

	{
		double a=4.1,b=5.1;
		cout << a << " " << b << endl;
		swap(a,b);
		cout << a << " " << b << endl;
		swap<double>(a,b);
		cout << a << " " << b << endl;
	}
	{
		DontCopyMe a, b;
		//swap(a,b);     // compiler error
	}
}
