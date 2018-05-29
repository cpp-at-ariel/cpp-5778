#include "gtest/gtest.h"
#include "dice.hpp"

template <typename T>
void test_one_sided_cube_helper(T i) {
	dice<T> d(i,i);
	for (size_t t= 0; t<42; ++t) {
		EXPECT_EQ(i, d());
	}
}

template <typename T>
void test_one_sided_cube() {
	// for signed
	for (T i= -42; i<0; ++i) {
		test_one_sided_cube_helper(i);
	}
	// for signed and unsigned
	for (T i= 0; i<42; ++i) {
		test_one_sided_cube_helper(i);
	}
}

TEST(testDice, testOneSidedCube) {
	test_one_sided_cube<int>();
	test_one_sided_cube<unsigned char>();
}

TEST(testDice, testSeveralSides) {
	for (int a=-10; a<10; ++a) {
		for (int b=a+1; b<10; ++b) {

			dice<> d(a,b);
			std::vector<long double> should_be_uniform(b-a+1, 0.0);
			const long double TIMES= 10000;
			for (size_t t=0; t<TIMES; ++t) {
				++should_be_uniform[d()-a];
			}

			for (const auto& v:should_be_uniform) {
				EXPECT_NEAR(1.0/(b-a+1), v/TIMES , 0.1)
					<< "This can actually fail because of randomness. See:"
					<< "http://search.dilbert.com/comic/Random%20Number%20Generator"
					<< std::endl;
			}

		} //b
	} // a
	
	//dice<> d(1,6);
	//for (size_t t=0; t<6; ++t) std::cout << d() << std::endl;
}
