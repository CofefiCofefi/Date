#include "gtest/gtest.h"
#include "date.hpp"
#include <sstream>
const TEST(DefaultCtor, assignsCorrectDefaultValues) {
	Date test(1, 2, 2020);
	EXPECT_EQ(test.day(), 1);
    EXPECT_EQ(test.month(), 2);
    EXPECT_EQ(test.year(), 2020);
}
const TEST(ValueCtor, assignsCorrectCustomValues) {
	Date test;
	EXPECT_EQ(test.day(), 1);
    EXPECT_EQ(test.month(), 1);
    EXPECT_EQ(test.year(), 1970);
}
const TEST(ValueCtor, checkForValidDate)
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
const TEST(Setters, catchInvalidDaySetter)
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
const TEST(Setters, catchInvalidMonthSetter)
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
const TEST(Props, correctMonthName) {
    Date test(3, 2, 2025);
    EXPECT_EQ(test.monthName(), "February");
}
const TEST(Props, correctDayName) {
    Date test(3, 3, 2025);
    EXPECT_EQ(test.dayName(), "Monday");
}

const TEST(Advance, correctDefaultAdvance) {
    Date test(28, 2, 2025);
    test.advance();
    EXPECT_EQ(test.day(), 1);
    test.advance();
    EXPECT_EQ(test.day(), 2);
}
const TEST(Advance, correctCustomAdvance) {
    Date test(28, 2, 2025);
    test.advance(2);
    EXPECT_EQ(test.day(), 2);
    test.advance(-4);
    EXPECT_EQ(test.day(), 26);
}
const TEST(Now, checkCurrentTime) {
    Date test = Date::now();

    tm date;
    time_t seconds = time(nullptr);
    date = *localtime(&seconds);

    EXPECT_EQ(test.day(), date.tm_mday);
    EXPECT_EQ(test.month(), date.tm_mon + 1);
    EXPECT_EQ(test.year(), date.tm_year + 1900);
}

const TEST(Print, PrintFormatsCorrectly) {
    Date date(5, 7, 2024);
    Date::order = Date::Order::MonthDayYear;

    std::ostringstream output;
    date.print(output);

    EXPECT_EQ(output.str(), "7/5/2024");
}

const TEST(Print, PrintFormatsCorrectly2) {
    Date date(5, 7, 2024);
    Date::order = Date::Order::DayMonthYear;

    std::ostringstream output;
    output.str("");
    date.print(output);

    EXPECT_EQ(output.str(), "5/7/2024");
}

const TEST(Print, PrintFormatsCorrectly3) {
    Date date(5, 7, 2024);
    Date::order = Date::Order::YearMonthDay;

    std::ostringstream output;
    output.str("");
    date.print(output);

    EXPECT_EQ(output.str(), "2024/7/5");
}

