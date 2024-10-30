#include "Room.h"

Room::Room() : minPrice(50.0), apartmentClass("Standard"), numberOfBeds(1), pricePerNight(100.0) {}

Room::Room(const std::string& aptClass, int beds, double price)
    : minPrice(50.0), apartmentClass(aptClass), numberOfBeds(beds), pricePerNight(price) {}

Room::Room(const Room& other)
    : minPrice(other.minPrice), apartmentClass(other.apartmentClass),
    numberOfBeds(other.numberOfBeds), pricePerNight(other.pricePerNight) {}

void Room::displayRoomInfo() const {
    std::cout << "Room Class: " << apartmentClass << ", Beds: " << numberOfBeds
        << ", Price per Night: $" << pricePerNight << std::endl;
}

Room::~Room() {
    std::cout << "Room destructor called\n";
}
