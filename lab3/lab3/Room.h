#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
public:
    int numberOfBeds;
    const double minPrice;
    double pricePerNight;
    std::string apartmentClass;

    // 1. Конструктор за замовчуванням
    Room();

    // 2. Конструктор з параметрами з використанням списку ініціалізації
    Room(const std::string& aptClass, int beds, double price);

    // 1. Конструктор копіювання
    Room(const Room& other);

    // 3. Заборонити оператор присвоєння, оскільки є константні поля
    Room& operator=(const Room&) = delete;
};

#endif // ROOM_H