#define BOOST_TEST_MODULE CinemaBookingTests

#include <boost/test/included/unit_test.hpp>
#include "logic.h"

BOOST_AUTO_TEST_CASE(SilverSeat)
{
    BOOST_CHECK(getSeatCategory(10) == "Silver");
}

BOOST_AUTO_TEST_CASE(GoldSeat)
{
    BOOST_CHECK(getSeatCategory(40) == "Gold");
}

BOOST_AUTO_TEST_CASE(PlatinumSeat)
{
    BOOST_CHECK(getSeatCategory(60) == "Platinum");
}

BOOST_AUTO_TEST_CASE(ValidCard)
{
    BOOST_CHECK(validCardNumber("1234567890123456"));
}

BOOST_AUTO_TEST_CASE(InvalidCard)
{
    BOOST_CHECK(!validCardNumber("12345"));
}

BOOST_AUTO_TEST_CASE(ValidCVV)
{
    BOOST_CHECK(validCVV("123"));
}

BOOST_AUTO_TEST_CASE(InvalidCVV)
{
    BOOST_CHECK(!validCVV("12"));
}

