#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "logic.h"
#include <string>
using namespace std;

TEST_CASE("Silver Category")
{
    REQUIRE(getSeatCategory(10) == "Silver");
}

TEST_CASE("Gold Category")
{
    REQUIRE(getSeatCategory(40) == "Gold");
}

TEST_CASE("Platinum Category")
{
    REQUIRE(getSeatCategory(60) == "Platinum");
}

TEST_CASE("Valid Card")
{
    REQUIRE(validCardNumber("1234567890123456"));
}

TEST_CASE("Invalid Card")
{
    REQUIRE_FALSE(validCardNumber("12345"));
}

TEST_CASE("Valid CVV")
{
    REQUIRE(validCVV("123"));
}

TEST_CASE("Invalid CVV")
{
    REQUIRE_FALSE(validCVV("12"));
}

TEST_CASE("Valid Month")
{
    REQUIRE(validExpiryMonth(12));
}

TEST_CASE("Invalid Month")
{
    REQUIRE_FALSE(validExpiryMonth(13));
}

TEST_CASE("Enough Cash")
{
    REQUIRE(sufficientCash(1000,800));
}

TEST_CASE("Not Enough Cash")
{
    REQUIRE_FALSE(sufficientCash(500,800));
}


