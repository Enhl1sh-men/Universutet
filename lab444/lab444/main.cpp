#include <iostream>
#include <memory>
#include "HotelReservation.h"

// Функція для обчислення загальної вартості
void calculateTotalCost(const HotelReservation& reservation, int nights) {
    double totalCost = reservation.room.pricePerNight * nights;
    std::cout << "Total cost for " << nights << " nights: $" << totalCost << std::endl;
}

// Функція для створення об'єкта класу HotelReservation
HotelReservation createReservation(const std::string& clientName, const std::string& roomClass, int beds, double price) {
    Client client(clientName);
    Room room(roomClass, beds, price);
    HotelReservation reservation(client, room);
    return reservation;
}

int main() {
    // Масив клієнтів
    std::string clientNames[5] = { "Vitalichok", "Grisha", "Vovan", "Andriy", "Taras" };
    std::string roomClasses[5] = { "Suite", "Deluxe", "Standard", "Economy", "Presidential" };
    int beds[5] = { 2, 1, 2, 1, 3 };
    double prices[5] = { 200.0, 150.0, 100.0, 80.0, 300.0 };

    // Використання масиву для зберігання резервацій
    HotelReservation reservations[5];
    for (int i = 0; i < 5; ++i) {
        reservations[i] = createReservation(clientNames[i], roomClasses[i], beds[i], prices[i]);
    }

    // Вивід інформації про всіх клієнтів
    for (int i = 0; i < 5; ++i) {
        std::cout << "Reservation details for client: " << reservations[i].client.getClientName() << std::endl;
        reservations[i].displayRequest();
        calculateTotalCost(reservations[i], 3); // Припустимо, що ми бронюємо на 3 ночі
        std::cout << "------------------------------------" << std::endl;
    }

    // Використання статичного поля і методу
    std::cout << "Total Reservations: " << HotelReservation::getTotalReservations() << std::endl;

    return 0;
}
