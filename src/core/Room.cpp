#include "core/Room.h"

Room::Room(int number, const std::string& type)
    : number_(number), type_(type), available_(true) {}

int Room::getNumber() const {
    return number_;
}

std::string Room::getType() const {
    return type_;
}

bool Room::isAvailable() const {
    return available_;
}

void Room::setAvailable(bool available) {
    available_ = available;
}
