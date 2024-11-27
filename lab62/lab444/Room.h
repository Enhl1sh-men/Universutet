#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>

class Room {
public:
    int numberOfBeds;
    const double minPrice;
    double pricePerNight;
    std::string apartmentClass;

    Room();  // Конструктор без параметрів
    Room(const std::string& aptClass, int beds, double price);  // Конструктор з параметрами
    Room(const Room& other);  // Конструктор копіювання
    Room& operator=(const Room& other);  // Оператор присвоєння
    virtual void displayRoomInfo() const;  // Віртуальна функція для відображення інформації
    virtual ~Room();  // Віртуальний деструктор

    // Перевантаження операторів
    Room operator+(const Room& other) const;
    Room operator-(const Room& other) const;

    static int getTotalRooms();  // Статичний метод для отримання кількості створених об'єктів Room

private:
    static int totalRooms;  // Статична змінна для підрахунку об'єктів Room
};

#endif // ROOM_H
