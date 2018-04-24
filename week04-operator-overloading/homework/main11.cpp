#include <iostream>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "CircularInt.hpp"
#include "catch.hpp"

std::string cirToString(const CircularInt &circularInt)
{
    std::stringstream ss;
    ss << circularInt ;
    return ss.str();
}

TEST_CASE("division","/=")
{

    REQUIRE(cirToString(hour2)=="1"||cirToString(hour2)== "3" ||cirToString(hour2)== "5"||cirToString(hour2)== "7"||cirToString(hour2)== "9"  );
}
