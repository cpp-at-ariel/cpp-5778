class Point {
	int x, y;
	virtual void f() {}
	virtual void g() {}
	virtual void h() {}
};

int main() {
	Point* array = new Point[1000];
	return 0;
}
