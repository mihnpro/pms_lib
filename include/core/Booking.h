#pragma once
#include "DateTime.h"
#include "Room.h"
#include "Guest.h"

class Booking {
public:
    Booking(int id, Guest guest, Room room, DateTime checkIn, DateTime checkOut);
    int getId() const;
    Guest getGuest() const;
    Room getRoom() const;
    DateTime getCheckIn() const;
    DateTime getCheckOut() const;

private:
    int id_;
    Guest guest_;
    Room room_;
    DateTime checkIn_;
    DateTime checkOut_;
};
