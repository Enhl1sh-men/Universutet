#ifndef HOTELRESERVATION_H
#define HOTELRESERVATION_H

#include "Client.h"
#include "Room.h"
#include <vector>
#include <string>

class HotelReservation {
public:
    Client client;
    Room room;

    static int totalReservations;

    double totalAmount;  // Загальна сума для резервування
    bool requestApproved;  // Статус затвердження запиту
    std::vector<std::string> additionalServices;  // Додаткові послуги

    HotelReservation();  // Конструктор без параметрів
    HotelReservation(const Client& client, Room& room);  // Конструктор з параметрами
    HotelReservation(const HotelReservation& other);  // Конструктор копіювання
    HotelReservation& operator=(const HotelReservation& other);  // Оператор присвоєння
    static int getTotalReservations();  // Статичний метод для отримання кількості резервувань
    static void viewTotalReservations();  // Метод для відображення загальної кількості резервувань
    virtual void displayRequest() const;  // Віртуальна функція для виведення деталей резервування
    virtual void cancelReservation();  // Віртуальна функція для скасування резервування
    virtual ~HotelReservation();  // Віртуальний деструктор
};

#endif // HOTELRESERVATION_H
