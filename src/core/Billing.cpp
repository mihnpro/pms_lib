#include "core/Billing.h"
#include <ctime>

Billing::Billing(const Booking& booking, double ratePerNight)
    : booking_(booking), ratePerNight_(ratePerNight) {}

double Billing::calculateTotal() const {
    std::tm checkInTm = {};
    std::tm checkOutTm = {};

    checkInTm.tm_year = booking_.getCheckIn().toString().empty() ? 0 : booking_.getCheckIn().toString()[0]; 
    return ratePerNight_;
}
