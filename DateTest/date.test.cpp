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
TEST(errorTesting, InvalidDaySetter)
{
    try {
        Date date(28, 2, 2025);
        date.day(29);
        FAIL() << "Expected Date::Invalid{ 29, 2, 2025 }";
    }
    catch (const Date::Invalid& error) {
        EXPECT_EQ(error.day, 29);
        EXPECT_EQ(error.month, 2);
        EXPECT_EQ(error.year, 2025);
    }
}
TEST(errorTesting, InvalidMonthSetter)
{
    try {
        Date date(20, 12, 2025);
        date.month(13);
        FAIL() << "Expected Date::Invalid{ 20, 13, 2025 }";
    }
    catch (const Date::Invalid& error) {
        EXPECT_EQ(error.day, 20);
        EXPECT_EQ(error.month, 13);
        EXPECT_EQ(error.year, 2025);
    }
}
