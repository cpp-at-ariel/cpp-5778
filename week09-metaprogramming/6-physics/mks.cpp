#include <cassert>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

template <int m, int k, int s> 
struct mks {
	double val;
public:
	mks(double val): val(val) {}
};

template <int m, int k, int s> 
auto operator+(mks<m,k,s> a, mks<m,k,s> b) {
	return mks<m,k,s>(a.val+b.val);
}

template <int m, int k, int s> 
ostream& operator<<(ostream& out, mks<m,k,s> a) {
	return (out << a.val);
}

template <int ma, int ka, int sa, int mb, int kb, int sb> 
auto operator*(mks<ma,ka,sa> a, mks<mb,kb,sb> b) {
	return mks<ma+mb,ka+kb,sa+sb>(a.val*b.val);
}

template <int ma, int ka, int sa, int mb, int kb, int sb> 
auto operator/(mks<ma,ka,sa> a, mks<mb,kb,sb> b) {
	return mks<ma-mb,ka-kb,sa-sb>(a.val/b.val);
}

using Length=mks<1,0,0>;
using Time=mks<0,0,1>;
using Velocity=mks<1,0,-1>;

int main() {
	Length length = 15; // 15 meters
	cout << "length = " << length << endl;
	Time time   = 3;  // 3 seconds
	cout << "time = " << time << endl;
	auto velocity = length/time;
	cout << "velocity = " << velocity << endl;
	Velocity velocity2 = 4;
	cout << "velocity2 = " << velocity2 << endl;
	auto velocity_sum = velocity+velocity2;
	cout << "velocity_sum = " << velocity_sum << endl;
	//auto v_plus_l = velocity+length; // won't compile
}