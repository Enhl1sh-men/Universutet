#include <iostream>
#include <fstream>
#include <memory>  // For smart pointers
#include "HotelReservation.h"
#include "Client.h"
#include "Room.h"
#include "ReservationWithServices.h"
#include "AdditionalServices.h"
#include "PremiumRoom.h"

void calculateTotalCost(const HotelReservation& reservation, int nights);
HotelReservation createReservation(const std::string& clientName, const std::string& roomClass, int beds, double price);
void Service(const HotelReservation& reservation);

// Функція для відображення меню
void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Show static reservation\n";
    std::cout << "2. Show(add) dynamic reservation\n";
    std::cout << "3. View total reservations\n";
    std::cout << "4. Remove dynamic reservation\n";
    std::cout << "5. View services\n";
    std::cout << "6. Perform file operations\n";
    std::cout << "0. Exit\n";
}

// Основний код з використанням меню
int main() {
    int choice;
    bool exit = false;

    Room roomStatic("Suite", 2, 150.0);
    HotelReservation reservationStatic(Client("Ivan"), roomStatic);

    // Smart pointers for dynamic objects
    std::unique_ptr<Room> roomDynamic = nullptr;
    std::unique_ptr<HotelReservation> reservationDynamic = nullptr;

    while (!exit) {
        displayMenu();
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "Static Reservation created for Ivan in Suite\n";
            reservationStatic.displayRequest();
            break;
        }
        case 2: {
            try {
                roomDynamic = std::make_unique<Room>("Economy", 1, 80.0);
                reservationDynamic = std::make_unique<HotelReservation>(Client("Oleg"), *roomDynamic);
                std::cout << "Dynamic Reservation created for Oleg in Economy\n";
                reservationDynamic->displayRequest();
            }
            catch (const std::exception& e) {
                std::cerr << "Error creating reservation: " << e.what() << std::endl;
            }
            break;
        }
        case 3: {
            std::cout << "Total Reservations: " << HotelReservation::getTotalReservations() << std::endl;
            break;
        }
        case 4: {
            reservationDynamic.reset();
            roomDynamic.reset();
            std::cout << "Dynamic reservation removed.\n";
            break;
        }
        case 5: {
            AdditionalServices services;
            services.addService("Breakfast");
            services.addService("Airport Shuttle");
            services.displayServices();
            services.removeServiceIfLessThan(9);  // Remove services with short names
            services.displayServices();
            break;
        }
        case 6: {
            Service(reservationStatic);
            break;
        }
        case 0: {
            exit = true;
            break;
        }
        default: {
            std::cout << "Invalid option. Try again.\n";
            break;
        }
        }
    }

    std::cout << "Exiting program...\n";
    return 0;
}

// Функція для розрахунку загальної вартості
void calculateTotalCost(const HotelReservation& reservation, int nights) {
    double totalCost = reservation.room.pricePerNight * nights;
    std::cout << "Total cost for " << nights << " nights: $" << totalCost << std::endl;
}

// Функція для створення резервування
HotelReservation createReservation(const std::string& clientName, const std::string& roomClass, int beds, double price) {
    if (clientName.empty()) {
        throw std::invalid_argument("Client name cannot be empty.");
    }
    if (beds < 1) {
        throw std::invalid_argument("Room must have at least one bed.");
    }
    if (price < 50.0) {
        throw std::invalid_argument("Price per night cannot be less than the minimum allowed.");
    }

    Client client(clientName);
    Room room(roomClass, beds, price);
    HotelReservation reservation(client, room);
    return reservation;
}

// Функція для роботи з файлами
void Service(const HotelReservation& reservation) {
    try {
        std::ofstream outFile("reservation_data.txt");
        if (!outFile.is_open()) {
            throw std::ios_base::failure("Failed to open file for writing.");
        }

        outFile << reservation.client.getClientName() << std::endl;
        outFile << reservation.room.apartmentClass << std::endl;
        outFile << reservation.room.numberOfBeds << std::endl;
        outFile << reservation.room.pricePerNight << std::endl;
        outFile.close();

        std::ifstream inFile("reservation_data.txt");
        if (!inFile.is_open()) {
            throw std::ios_base::failure("Failed to open file for reading.");
        }

        std::string clientName, roomClass;
        int beds;
        double price;

        inFile >> clientName >> roomClass >> beds >> price;
        if (inFile.fail()) {
            throw std::runtime_error("Error reading data from file.");
        }
        inFile.close();

        std::cout << "Read data from file successfully:\n"
            << "Client Name: " << clientName << "\n"
            << "Room Class: " << roomClass << "\n"
            << "Beds: " << beds << "\n"
            << "Price per Night: $" << price << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "File operation error: " << e.what() << std::endl;
    }
}
