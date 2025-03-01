//Instructions at https://cs.harding.edu/gfoust/classes/comp3450/projects/date
#define _CRT_SECURE_NO_WARNINGS
#include "date.hpp"
#include "iostream"
#include <string>

Date::Date() {
	time(&_t);
	_date = *localtime(&_t);

	_date.tm_mday = 1;
	_date.tm_mon = 0;
	_date.tm_year = 1970 - 1900;

};

Date::Date(int d, int m, int y) {
	time(&_t);
	_date = *localtime(&_t);

	_date.tm_mday = d;
	_date.tm_mon = (m - 1);
	_date.tm_year = (y - 1900);

	tm dateCpy = _date;
	mktime(&dateCpy);

	if (dateCpy.tm_mday != d || dateCpy.tm_mon != (m - 1) || dateCpy.tm_year != (y - 1900)){
		throw Date::Invalid{ d, m, y };
	};
};

Date::Order Date::order = Date::Order::MonthDayYear;
char Date::separator = '/';

const int Date::day() {
	return _date.tm_mday;
};

const int Date::month() {
	return (_date.tm_mon + 1);
};

const int Date::year() {
	return (_date.tm_year + 1900);
};

void Date::day(int day) {
	tm dateCpy = _date;
	int originalDay = day;
	dateCpy.tm_mday = day;

	time_t t = mktime(&dateCpy);

	if (dateCpy.tm_mday != originalDay || dateCpy.tm_mon != _date.tm_mon || dateCpy.tm_year != _date.tm_year) {
		throw Date::Invalid{ originalDay, _date.tm_mon + 1, _date.tm_year + 1900 };
	}

	_date.tm_mday = originalDay;
};

void Date::month(int month) {
	tm dateCpy = _date;
	int originalMonth = month;
	dateCpy.tm_mon = month - 1;

	time_t t = mktime(&dateCpy);

	if (dateCpy.tm_mday != _date.tm_mday || dateCpy.tm_mon != originalMonth - 1 || dateCpy.tm_year != _date.tm_year) {
		throw Date::Invalid{ _date.tm_mday, originalMonth, _date.tm_year + 1900 };
	}

	_date.tm_mon = originalMonth - 1;
};

void Date::year(int year) { //Is there such a thing as an invalid year? 
	tm dateCpy = _date;
	int originalYear = year;
    dateCpy.tm_year = year - 1900;

    time_t t = mktime(&dateCpy);

    if (dateCpy.tm_mday != _date.tm_mday || dateCpy.tm_mon != _date.tm_mon || dateCpy.tm_year != originalYear - 1900) {
        throw Date::Invalid{ _date.tm_mday, _date.tm_mon + 1, originalYear };
    }

    _date.tm_year = originalYear - 1900;
};

const std::string Date::monthName() {
	switch (_date.tm_mon + 1) {
	case 1: return "January";
	case 2: return "February";
	case 3: return "March";
	case 4: return "April";
	case 5: return "May";
	case 6: return "June";
	case 7: return "July";
	case 8: return "August";
	case 9: return "September";
	case 10: return "October";
	case 11: return "November";
	case 12: return "December";
	}
};

const std::string Date::dayName() {
	switch (_date.tm_wday + 1) {
	case 1: return "Sunday";
	case 2: return "Monday";
	case 3: return "Tuesday";
	case 4: return "Wednesday";
	case 5: return "Thursday";
	case 6: return "Friday";
	case 7: return "Saturday";
	}
};

void Date::advance() {
	time_t seconds = mktime(&_date);
	seconds += 24 * 60 * 60;
	_date = *localtime(&seconds);
};

void Date::advance(int numOfDays) {
	time_t seconds = mktime(&_date);
	seconds += (24 * 60 * 60) * numOfDays;
	_date = *localtime(&seconds);
};

const void Date::print(std::ostream& outputStream) {
	if (Date::order == Date::Order::DayMonthYear) {
		outputStream << day() << Date::separator << month() << Date::separator << year();
	}
	else if (Date::order == Date::Order::MonthDayYear) {
		outputStream << month() << Date::separator << day() << Date::separator << year();
	}
	else if (Date::order == Date::Order::YearMonthDay) {
		outputStream << year() << Date::separator << month() << Date::separator << day();
	}
};

Date Date::now() {
	tm date;
	time_t seconds = time(nullptr);
	date = *localtime(&seconds);
	Date now(date.tm_mday, date.tm_mon + 1, date.tm_year + 1900);
	return now;
};