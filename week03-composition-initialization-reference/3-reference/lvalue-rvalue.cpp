
void test() {
	int a = 5;

	//7 = a; // expression must be a modifiable lvalue

	//int& rint = 5; //  initial value of reference to non-const must be an lvalue

	const int& crint = 5;  // OK!
}
