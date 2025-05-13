#include "core/Housekeeping.h"

Housekeeping::Housekeeping(int id, int roomNumber, const std::string& status)
    : id_(id), roomNumber_(roomNumber), status_(status) {}

int Housekeeping::getId() const {
    return id_;
}

int Housekeeping::getRoomNumber() const {
    return roomNumber_;
}

std::string Housekeeping::getStatus() const {
    return status_;
}

void Housekeeping::setStatus(const std::string& status) {
    status_ = status;
}
