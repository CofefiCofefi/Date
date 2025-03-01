#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>

class Date {
public:

    Date();                             
    Date(int day, int month, int year);

    struct Invalid {
        int day, month, year;
    };

    enum class Order {
        MonthDayYear,
        DayMonthYear,
        YearMonthDay
    };
    static Order order;
    static char separator;

    const int day();
    const int month();
    const int year();
    void day(int day);
    void month(int month);
    void year(int year);
    const std::string monthName();
    const std::string dayName();
    void advance();
    void advance(int numOfDays);
    const void print(std::ostream&);
    static Date now();

private:
    time_t _t;
    tm _date;
};