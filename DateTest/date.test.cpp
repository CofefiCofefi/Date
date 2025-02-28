#include "gtest/gtest.h"
#include "date.hpp"
TEST(constructor_tests, valueConstructor) {
	Date test(1, 2, 2020);
	EXPECT_EQ(test.day(), 1);
    EXPECT_EQ(test.month(), 2);
    EXPECT_EQ(test.year(), 2020);
}
TEST(constructor_tests, defaultConstructor) {
	Date test;
	EXPECT_EQ(test.day(), 1);
    EXPECT_EQ(test.month(), 1);
    EXPECT_EQ(test.year(), 1970);
}
TEST(errorTesting, InvalidDay)
{
    try {
        Date test(1, 200, 2020);
        FAIL() << "Expected Date::Invalid{1, 200, 2020}";
    }
    catch (const Date::Invalid& error) {
        EXPECT_EQ(error.day, 1);
        EXPECT_EQ(error.month, 200);
        EXPECT_EQ(error.year, 2020);
    }
}