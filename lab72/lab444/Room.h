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

    Room();  // 4 пункт Конструктор без параметрів
    Room(const std::string& aptClass, int beds, double price);  // Конструктор з параметрами
    Room(const Room& other);  // Конструктор копіювання
    Room& operator=(const Room& other);  // Оператор присвоєння
    virtual void displayRoomInfo() const;  //5пункт Віртуальна функція для відображення інформації
    virtual ~Room();  // Віртуальний деструктор

    static int getTotalRooms();  // Статичний метод для отримання кількості створених об'єктів Room 9

private:
    static int totalRooms;  // Статична змінна для підрахунку об'єктів Room 9
};

#endif // ROOM_H
