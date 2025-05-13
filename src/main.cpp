#include "core/DateTime.h"
#include "core/Room.h"
#include "core/Guest.h"
#include "core/Booking.h"
#include "core/Billing.h"
#include "core/Resource.h"
#include "core/Housekeeping.h"
#include "utils/Logger.h"
#include "utils/ConfigParser.h"
#include <vector>
#include <memory>

int main() {
    Logger::info("\n=== Запуск PMS системы ===");

    // Загрузка конфигурации
    try {
        ConfigParser config("config/settings.ini");
        Logger::info("Загружены настройки отеля: " + config.get("hotel_name", "Unknown Hotel"));
    } catch (const std::exception& e) {
        Logger::error("Ошибка загрузки конфигурации: " + std::string(e.what()));
    }

    // Создание гостей
    Guest guest1(1, "Иван Иванов");
    Guest guest2(2, "Мария Петрова");
    Guest guest3(3, "Алексей Смирнов");

    // Инициализация номеров
    std::vector<Room> rooms = {
        Room(101, "Стандарт"),
        Room(102, "Люкс"),
        Room(201, "Семейный"),
        Room(202, "Бизнес-класс")
    };

    // Демонстрация статуса номеров
    rooms[1].setAvailable(false);
    Logger::info("\nСтатус номеров:");
    for (const auto& room : rooms) {
        Logger::info("Номер " + std::to_string(room.getNumber()) + 
                   " (" + room.getType() + "): " + 
                   (room.isAvailable() ? "Свободен" : "Занят"));
    }

    // Бронирование 1
    DateTime checkIn1(2025, 5, 12);
    DateTime checkOut1(2025, 5, 15);
    Booking booking1(1, guest1, rooms[0], checkIn1, checkOut1);
    rooms[0].setAvailable(false);

    // Бронирование 2
    DateTime checkIn2(2025, 5, 16);
    DateTime checkOut2(2025, 5, 19);
    Booking booking2(2, guest2, rooms[1], checkIn2, checkOut2);
    rooms[1].setAvailable(false);

    // Расчет стоимости
    Billing billing1(booking1, 150.0);
    Logger::info("\nДетали бронирования #" + std::to_string(booking1.getId()));
    Logger::info("Гость: " + booking1.getGuest().getName());
    Logger::info("Тариф: $" + std::to_string(billing1.calculateTotal()) + "/ночь");
    Logger::info("Итого за 3 ночи: $" + std::to_string(billing1.calculateTotal() * 3));

    // Расчет стоимости
    Billing billing2(booking2, 200.0);
    Logger::info("\nДетали бронирования #" + std::to_string(booking2.getId()));
    Logger::info("Гость: " + booking2.getGuest().getName());
    Logger::info("Тариф: $" + std::to_string(billing2.calculateTotal()) + "/ночь");
    Logger::info("Итого за 3 ночи: $" + std::to_string(billing2.calculateTotal() * 3));
    
    // Управление ресурсами
    Resource towels(1, "Полотенца", 50);
    Resource shampoo(2, "Шампунь", 100);
    towels.setQuantity(45);
    
    Logger::info("\nОстатки ресурсов:");
    Logger::info(towels.getName() + ": " + std::to_string(towels.getQuantity()));
    Logger::info(shampoo.getName() + ": " + std::to_string(shampoo.getQuantity()));

    // Уборка номера
    Housekeeping cleaningTask(1, rooms[0].getNumber(), "В процессе");
    Logger::info("\nСтатус уборки номера " + std::to_string(rooms[0].getNumber()) + 
               ": " + cleaningTask.getStatus());
    
    cleaningTask.setStatus("Завершено");
    Logger::info("Обновленный статус: " + cleaningTask.getStatus());

    // Список предстоящих бронирований
    std::vector<std::unique_ptr<Booking>> bookings;
    bookings.emplace_back(std::make_unique<Booking>(3, guest3, rooms[2], 
        DateTime(2025, 6, 1), 
        DateTime(2025, 6, 5)));

    Logger::info("\nПредстоящие бронирования:");
    for (const auto& b : bookings) {
        Logger::info("Гость " + b->getGuest().getName() + 
                   " → Номер " + std::to_string(b->getRoom().getNumber()) +
                   " (" + b->getCheckIn().toString() + " - " + 
                   b->getCheckOut().toString() + ")");
    }

    Logger::info("\n=== Работа системы завершена ===");
    return 0;
}
