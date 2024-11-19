#include <iostream>
#include <fstream>
#include <memory>  // For smart pointers
#include "HotelReservation.h"
#include "Client.h"
#include "Room.h"
#include "ReservationWithServices.h"
#include "AdditionalServices.h"
#include "PremiumRoom.h"
#include "TemplateExample.h"
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
    std::cout << "7. Demonstrate operator overloads\n";
    std::cout << "0. Exit\n";
}

// Основний код з використанням меню
int main() {

    int choice;
    bool exit = false;
    TemplateExample<int, double, std::string, char, int> example(42, 3.14, "Hello, World!", 'A', true);
        

    example.printType("Nomeriv");  // String
    example.printType(5);               // Integer
   example.printType("zalushulos");  // String
    
    Room roomStatic("Suite", 2, 150.0);
    HotelReservation reservationStatic(Client("Ivan"), roomStatic);
    AdditionalServices services1, services2;
    services1.addService("Spa");
    services1.addService("Pool Access");

    services2.addService("Breakfast");
    services2.addService("Dinner");

    // Демонстрація операторів для AdditionalServices
    services1 += "Gym";
    services1.displayServices();

    services1 -= "Pool Access";
    services1.displayServices();

    AdditionalServices combinedServices = services1 * 2;
    combinedServices.displayServices();

    try {
        std::cout << "First service: " << combinedServices[0] << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    // Демонстрація операторів для HotelReservation
    Room room3("Deluxe", 2, 120.0);
    HotelReservation reservation1(Client("Alice"), room3);
    HotelReservation reservation2(Client("Bob"), room3);

    reservation1.totalAmount = 300.0;
    reservation2.totalAmount = 200.0;

    reservation1 += reservation2;
    std::cout << "Total amount after += operation: $" << reservation1.totalAmount << std::endl;

    reservation1 -= reservation2;
    std::cout << "Total amount after -= operation: $" << reservation1.totalAmount << std::endl;

    HotelReservation multipliedReservation = reservation1 * 2;
    std::cout << "Total amount after * operation: $" << multipliedReservation.totalAmount << std::endl;

    reservation1 *= 3;
    std::cout << "Total amount after *= operation: $" << reservation1.totalAmount << std::endl;

    // Smart pointers for dynamic objects
    std::unique_ptr<Room> roomDynamic = nullptr;
    std::unique_ptr<HotelReservation> reservationDynamic = nullptr;

    // Оголошуємо клієнтів та кімнати
    Client client1("Ivan");
    Client client2("Olga");
    Room room1("Economy", 3, 100.0);
    Room room2("Suite", 4, 300.0);

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
                std::cout << "Total Reservations: " << HotelReservation::getTotalReservations() << std::endl;
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
            reservationDynamic.reset();  // Очищаємо пам'ять і викликаємо деструктор
            roomDynamic.reset();
            std::cout << "Dynamic reservation removed.\n";
            std::cout << "Total Reservations: " << HotelReservation::getTotalReservations() << std::endl;
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
        case 7: {
            // Демонстрація перевантажених операторів
            Client combinedClient = client1 + client2;
            Client reducedClient = client1 - client2;
            std::cout << "Combined Client Name: " << combinedClient.getClientName() << std::endl;
            std::cout << "Reduced Client Name: " << reducedClient.getClientName() << std::endl;

            Room combinedRoom = room1 + room2;
            Room reducedRoom = room1 - room2;
            std::cout << "Combined Room: ";
            combinedRoom.displayRoomInfo();
            std::cout << "Reduced Room: ";
            reducedRoom.displayRoomInfo();
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

    std::cout << "Exiting the program.\n";
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

        // Створюємо масив клієнтів і номерів
        std::vector<HotelReservation> reservations = {
            reservation,
            createReservation("Olga", "Deluxe", 2, 180.0),
            createReservation("Petro", "Single", 1, 70.0),
            createReservation("Anna", "Suite", 3, 250.0)
        };

        // Записуємо дані для кожного клієнта
        for (const auto& res : reservations) {
            outFile << res.client.getClientName() << "\n";
            outFile << res.room.apartmentClass << "\n";
            outFile << res.room.numberOfBeds << "\n";
            outFile << res.room.pricePerNight << "\n";
        }

        outFile.close();

        std::ifstream inFile("reservation_data.txt");
        if (!inFile.is_open()) {
            throw std::ios_base::failure("Failed to open file for reading.");
        }

        std::string clientName, roomClass;
        int beds;
        double price;

        std::cout << "Read data from file successfully:\n";
        while (inFile >> clientName >> roomClass >> beds >> price) {
            std::cout << "Client Name: " << clientName << "\n"
                << "Room Class: " << roomClass << "\n"
                << "Beds: " << beds << "\n"
                << "Price per Night: $" << price << "\n\n";
        }

        inFile.close();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
