#include "core/Booking.h"

Booking::Booking(int id, Guest guest, Room room, DateTime checkIn, DateTime checkOut)
    : id_(id), guest_(guest), room_(room), checkIn_(checkIn), checkOut_(checkOut) {}

int Booking::getId() const {
    return id_;
}

Guest Booking::getGuest() const {
    return guest_;
}

Room Booking::getRoom() const {
    return room_;
}

DateTime Booking::getCheckIn() const {
    return checkIn_;
}

DateTime Booking::getCheckOut() const {
    return checkOut_;
}
