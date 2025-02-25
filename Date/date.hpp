#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>

class Date {
public:

    Date();                             //Default constructor
    Date(int day, int month, int year); //Value constructor

    struct Invalid {
        int day, month, year;
    };

    enum class Order {
        MonthDayYear,
        DayMonthYear,
        YearMonthDay
    };

private:
	
    int day, month, year;

};