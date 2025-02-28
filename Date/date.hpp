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

    const int day();
    const int month();
    const int year();
    void day(int day);
    void month(int month);
    void year(int year);

private:
    time_t _t;
    tm _date;
};