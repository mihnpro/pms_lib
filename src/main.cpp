#include "core/DateTime.h"
#include "core/Room.h"
#include "core/Guest.h"
#include "core/Booking.h"
#include "core/Billing.h"
#include "utils/Logger.h"
#include <iostream>

int main() {
    Logger::info("Starting PMS application");

    Guest guest(1, "Ivan Ivanov");
    Room room(101, "Single");

    DateTime checkIn(2025, 5, 12);
    DateTime checkOut(2025, 5, 13);

    Booking booking(1, guest, room, checkIn, checkOut);

    Billing billing(booking, 100.0);
    double total = billing.calculateTotal();

    Logger::info("Guest: " + guest.getName());
    Logger::info("Room: " + std::to_string(room.getNumber()));
    Logger::info("Check-in: " + checkIn.toString());
    Logger::info("Check-out: " + checkOut.toString());
    Logger::info("Total billing amount: " + std::to_string(total));

    return 0;
}
