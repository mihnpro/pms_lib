#pragma once
#include <string>

class Room {
public:
    Room(int number, const std::string& type);
    int getNumber() const;
    std::string getType() const;
    bool isAvailable() const;
    void setAvailable(bool available);

private:
    int number_;
    std::string type_;
    bool available_;
};
