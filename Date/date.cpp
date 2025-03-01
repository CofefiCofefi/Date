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
}

void Date::month(int month) {
	tm dateCpy = _date;
	int originalMonth = month;
	dateCpy.tm_mon = month - 1;

	time_t t = mktime(&dateCpy);

	if (dateCpy.tm_mday != _date.tm_mday || dateCpy.tm_mon != originalMonth - 1 || dateCpy.tm_year != _date.tm_year) {
		throw Date::Invalid{ _date.tm_mday, originalMonth, _date.tm_year + 1900 };
	}

	_date.tm_mon = originalMonth - 1;
}

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

