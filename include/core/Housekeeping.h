#pragma once
#include <string>

class Housekeeping {
public:
    Housekeeping(int id, int roomNumber, const std::string& status);
    int getId() const;
    int getRoomNumber() const;
    std::string getStatus() const;
    void setStatus(const std::string& status);

private:
    int id_;
    int roomNumber_;
    std::string status_;
};
