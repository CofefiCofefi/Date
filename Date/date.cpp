//Instructions at https://cs.harding.edu/gfoust/classes/comp3450/projects/date
#define _CRT_SECURE_NO_WARNINGS
#include "date.hpp"
#include "iostream"

Date::Date() {
	time(&_t);
	_date = *localtime(&_t);

	_date.tm_mday = 1;
	_date.tm_mon = 0;
	_date.tm_year = 1970 - 1900;

}

Date::Date(int d, int m, int y) { // Make this check if the date enterd is valid and if it is not throw Date::Invalid
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

const int Date::day() {
	return _date.tm_mday;
};

const int Date::month() {
	return (_date.tm_mon + 1);
};

const int Date::year() {
	return (_date.tm_year + 1900);
};

void Date::day(int day) {	//If setting the field to the required value would result in an invalid date,
	_date.tm_mday = day;	// throw an Date::Invalid exception containing the values your date would have
};							// had. Setters should have a strong exception guarantee. (FOR ALL 3 SETTERS)

void Date::month(int month) {
	_date.tm_mon = (month - 1);
};

void Date::year(int year) {
	_date.tm_year = (year - 1900);
};

