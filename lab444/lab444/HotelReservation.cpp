#include "HotelReservation.h"
#include <iostream>

int HotelReservation::totalReservations = 0;

HotelReservation::HotelReservation()
    : client(Client()), room(Room()), totalAmount(0), requestApproved(false) {
    totalReservations++;
}

HotelReservation::HotelReservation(const Client& client, Room& room)
    : client(client), room(room), totalAmount(0), requestApproved(false) {
    totalReservations++;
}

HotelReservation::HotelReservation(const HotelReservation& other)
    : client(other.client), room(other.room), totalAmount(other.totalAmount), requestApproved(other.requestApproved),
    additionalServices(other.additionalServices) {}

HotelReservation& HotelReservation::operator=(const HotelReservation& other) {
    if (this != &other) {
        client = other.client;
        totalAmount = other.totalAmount;
        requestApproved = other.requestApproved;
        additionalServices = other.additionalServices;
    }
    return *this;
}

int HotelReservation::getTotalReservations() {
    return totalReservations;
}

void HotelReservation::displayRequest() const {
    std::cout << "Request details for client: " << client.getClientName() << "\n"
        << "Room class: " << room.apartmentClass << ", Beds: " << room.numberOfBeds
        << ", Price per night: $" << room.pricePerNight << std::endl;
}

HotelReservation::~HotelReservation() {
    std::cout << "HotelReservation destructor called\n";
}
