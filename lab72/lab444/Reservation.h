// Reservation.h
#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <iostream>

class Reservation {// Абстрактний клас
public:
    virtual void displayRequest() const = 0; // чисто віртуальна функція для відображення
    virtual ~Reservation() {} // віртуальний деструктор
};
// Reservation.h
#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <iostream>

class Reservation { // Абстрактний клас
public:
    virtual void displayRequest() const = 0; // чисто віртуальна функція для відображення
    virtual ~Reservation() {} // віртуальний деструктор
};

// Клас для бронювання готелю
class HotelReservation : public Reservation {
private:
    std::string guestName;
    std::string hotelName;
    int nights;

public:
    HotelReservation(const std::string& guest, const std::string& hotel, int numNights)
        : guestName(guest), hotelName(hotel), nights(numNights) {}

    void displayRequest() const override {
        std::cout << "Hotel Reservation:\n"
            << "Guest: " << guestName << "\n"
            << "Hotel: " << hotelName << "\n"
            << "Nights: " << nights << "\n";
    }
};

// послуга для бронювання авіаквитків
class FlightReservation : public Reservation {
private:
    std::string passengerName;
    std::string departureCity;
    std::string destinationCity;
    std::string flightDate;

public:
    FlightReservation(const std::string& passenger, const std::string& departure,
        const std::string& destination, const std::string& date)
        : passengerName(passenger), departureCity(departure),
        destinationCity(destination), flightDate(date) {}

    void displayRequest() const override {
        std::cout << "Flight Reservation:\n"
            << "Passenger: " << passengerName << "\n"
            << "From: " << departureCity << "\n"
            << "To: " << destinationCity << "\n"
            << "Date: " << flightDate << "\n";
    }
};

// Клас для бронювання столика в ресторані
class RestaurantReservation : public Reservation {
private:
    std::string customerName;
    std::string restaurantName;
    int tableNumber;
    std::string reservationTime;

public:
    RestaurantReservation(const std::string& customer, const std::string& restaurant,
        int table, const std::string& time)
        : customerName(customer), restaurantName(restaurant),
        tableNumber(table), reservationTime(time) {}

    void displayRequest()

}
#endif // RESERVATION_H
