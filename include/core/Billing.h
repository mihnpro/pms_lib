#pragma once
#include "Booking.h"

class Billing {
public:
    Billing(const Booking& booking, double ratePerNight);
    double calculateTotal() const;

private:
    Booking booking_;
    double ratePerNight_;
};
