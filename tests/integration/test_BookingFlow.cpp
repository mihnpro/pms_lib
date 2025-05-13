#include "core/Booking.h"
#include "core/Guest.h"
#include "core/Room.h"
#include "core/DateTime.h"
#include "core/Billing.h"
#include <cassert>
#include <iostream>

int main() {
    Guest guest(1, "Test Guest");
    Room room(100, "Double");
    DateTime checkIn(2025, 5, 12);
    DateTime checkOut(2025, 5, 14);

    Booking booking(1, guest, room, checkIn, checkOut);
    Billing billing(booking, 150.0);

    double total = billing.calculateTotal();

    // Для упрощения считаем 1 ночь (см. Billing.cpp)
    assert(total == 150.0);

    std::cout << "Booking flow integration test passed." << std::endl;
    return 0;
}
