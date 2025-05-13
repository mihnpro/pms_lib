#pragma once
#include <string>

class Guest {
public:
    Guest(int id, const std::string& name);
    int getId() const;
    std::string getName() const;

private:
    int id_;
    std::string name_;
};
