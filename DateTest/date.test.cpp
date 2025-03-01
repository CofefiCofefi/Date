#include "gtest/gtest.h"
#include "date.hpp"
TEST(DefaultCtor, assignsCorrectDefaultValues) {
	Date test(1, 2, 2020);
	EXPECT_EQ(test.day(), 1);
    EXPECT_EQ(test.month(), 2);
    EXPECT_EQ(test.year(), 2020);
}
TEST(ValueCtor, assignsCorrectCustomValues) {
	Date test;
	EXPECT_EQ(test.day(), 1);
    EXPECT_EQ(test.month(), 1);
    EXPECT_EQ(test.year(), 1970);
}
TEST(ValueCtor, checkForValidDate)
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
TEST(Setters, catchInvalidDaySetter)
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
TEST(Setters, catchInvalidMonthSetter)
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
TEST(Props, correctMonthName) {
    Date test(3, 4, 2025);
    EXPECT_EQ(test.monthName(), "April");
}
TEST(Props, correctDayName) {
    Date test(28, 2, 2025);
    EXPECT_EQ(test.dayName(), "Friday");
}
TEST(Advance, correctDefaultAdvance) {
    Date test(28, 2, 2025);
    test.advance();
    EXPECT_EQ(test.day(), 1);
    test.advance();
    EXPECT_EQ(test.day(), 2);
}
TEST(Advance, correctCustomAdvance) {
    Date test(28, 2, 2025);
    test.advance(2);
    EXPECT_EQ(test.day(), 2);
    test.advance(-4);
    EXPECT_EQ(test.day(), 26);
}
TEST(Now, checkCurrentTime) {
    Date test = Date::now();

    tm date;
    time_t seconds = time(nullptr);
    date = *localtime(&seconds);

    EXPECT_EQ(test.day(), date.tm_mday);
    EXPECT_EQ(test.month(), date.tm_mon + 1);
    EXPECT_EQ(test.year(), date.tm_year + 1900);
}
