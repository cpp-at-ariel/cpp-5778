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

TEST_CASE("division","/")
{
    CircularInt hour {1, 10};
    REQUIRE_THROWS(hour/3);
    CircularInt hour2 {1, 10};
    hour2 = hour2 + 4 ;
    REQUIRE_NOTHROW(hour2/5);
    REQUIRE(cirToString(hour2)=="1"||cirToString(hour2)== "3" ||cirToString(hour2)== "5" ||cirToString(hour2)=="7" ||cirToString(hour2)=="9"  );
    CircularInt hour3 {1, 10};
    hour3 = 3 / hour3 ;
    REQUIRE(cirToString(hour3) == "3");

}
