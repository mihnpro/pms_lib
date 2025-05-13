#pragma once
#include <string>
#include <ctime>

class DateTime {
public:
    DateTime();
    DateTime(int year, int month, int day);
    std::string toString() const;
    bool operator<(const DateTime& other) const;

private:
    std::tm time_;
};
