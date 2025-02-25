//Instructions at https://cs.harding.edu/gfoust/classes/comp3450/projects/date
#define _CRT_SECURE_NO_WARNINGS
#include "date.hpp"
#include "iostream"

Date::Date() : day(1), month(1), year(1970) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

