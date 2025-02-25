//Instructions at https://cs.harding.edu/gfoust/classes/comp3450/projects/date
#define _CRT_SECURE_NO_WARNINGS
#include "date.hpp"
#include "iostream"

Date::Date() : _day(1), _month(1), _year(1970) {}

Date::Date(int d, int m, int y) { // Make this check if the date enterd is valid and if it is not throw Date::Invalid
	_day = d;
	_month = m;
	_year = y;
};

int Date::day() {
	return _day;
};

int Date::month() {
	return _month;
};

int Date::year() {
	return _year;
};

void Date::day(int day) {	//If setting the field to the required value would result in an invalid date,
	_day = day;				// throw an Date::Invalid exception containing the values your date would have
};							// had. Setters should have a strong exception guarantee. (FOR ALL 3 SETTERS)

void Date::month(int month) {
	_month = month;
};

void Date::year(int year) {
	_year = year;
};

