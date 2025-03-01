#include "date.hpp"
#include <iostream>
#include <sstream>

int main() {
    Date date(5, 7, 2024);
    Date::order = Date::Order::MonthDayYear;

    std::ostringstream output;
    date.print(output);
    std::cout << "Printed Date: " << output.str() << std::endl;  // Should be "7/5/2024\n"

    return 0;
}