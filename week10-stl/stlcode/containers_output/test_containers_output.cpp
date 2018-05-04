#include "containers_output.hpp"
#include <sstream>
#include "gtest/gtest.h"

static int nums[]= {1,5,2,3,4};
static const int SIZE= sizeof(nums)/sizeof(nums[0]);

TEST(testContainersOutput, testVectorEmpty) {
	std::vector<int> vec;
	std::stringstream s;
	s << vec;
	EXPECT_EQ("[  ]", s.str() );
}

TEST(testContainersOutput, testVector) {
	std::vector<int> vec(nums,nums+SIZE);
	std::stringstream s;
	s << vec;
	EXPECT_EQ("[ 1 5 2 3 4 ]", s.str() );
}

TEST(testContainersOutput, testForwardListEmpty) {
    std::forward_list<int> l;
	std::stringstream s;
	s << l;
	EXPECT_EQ("{  }", s.str() );
}

TEST(testContainersOutput, testForwardList) {
	std::forward_list<int> l(nums,nums+SIZE);
	std::stringstream s;
	s << l;
	EXPECT_EQ("{ 1->5->2->3->4 }", s.str() );
}

TEST(testContainersOutput, testForwardListOfVectors) {
    std::list< std::vector<int> > lv;
    lv.emplace_back(2,3);
    lv.emplace_front(2,1);
    lv.insert(++lv.begin(),std::vector<int>(1,2));
	std::stringstream s;
	s << lv;
	EXPECT_EQ("{ [ 1 1 ]<=>[ 2 ]<=>[ 3 3 ] }", s.str() );
}

