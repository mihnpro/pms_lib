#include "core/DateTime.h"
#include <iomanip>
#include <sstream>

DateTime::DateTime() {
    std::time_t t = std::time(nullptr);
    time_ = *std::localtime(&t);
}

DateTime::DateTime(int year, int month, int day) {
    time_ = {};
    time_.tm_year = year - 1900;
    time_.tm_mon = month - 1;
    time_.tm_mday = day;
}

std::string DateTime::toString() const {
    std::ostringstream oss;
    oss << std::put_time(&time_, "%Y-%m-%d");
    return oss.str();
}

bool DateTime::operator<(const DateTime& other) const {
    return std::mktime(const_cast<std::tm*>(&time_)) < std::mktime(const_cast<std::tm*>(&other.time_));
}
