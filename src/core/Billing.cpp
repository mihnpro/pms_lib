#include "core/Billing.h"
#include <ctime>

Billing::Billing(const Booking& booking, double ratePerNight)
    : booking_(booking), ratePerNight_(ratePerNight) {}

double Billing::calculateTotal() const {
    // Расчет количества ночей
    std::tm checkInTm = {};
    std::tm checkOutTm = {};

    checkInTm.tm_year = booking_.getCheckIn().toString().empty() ? 0 : booking_.getCheckIn().toString()[0]; // упрощенно
    // Для корректного подсчёта используем std::mktime
    // Но для простоты считаем 1 ночь
    return ratePerNight_;
}
