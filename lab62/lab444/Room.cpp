#include "Room.h"

int Room::totalRooms = 0;  // Ініціалізація статичної змінної

Room::Room()
    : minPrice(50.0), apartmentClass("Standard"), numberOfBeds(1), pricePerNight(100.0) {
    totalRooms++;
}

Room::Room(const std::string& aptClass, int beds, double price)
    : minPrice(50.0), apartmentClass(aptClass), numberOfBeds(beds), pricePerNight(price) {
    totalRooms++;
}

Room::Room(const Room& other)
    : minPrice(other.minPrice), apartmentClass(other.apartmentClass),
    numberOfBeds(other.numberOfBeds), pricePerNight(other.pricePerNight) {
    totalRooms++;
}

Room& Room::operator=(const Room& other) {
    if (this != &other) {
        apartmentClass = other.apartmentClass;
        numberOfBeds = other.numberOfBeds;
        pricePerNight = other.pricePerNight;
    }
    return *this;
}

Room Room::operator+(const Room& other) const {
    return Room(apartmentClass, numberOfBeds + other.numberOfBeds, pricePerNight + other.pricePerNight);
}

Room Room::operator-(const Room& other) const {
    return Room(apartmentClass, numberOfBeds - other.numberOfBeds, pricePerNight - other.pricePerNight);
}

void Room::displayRoomInfo() const {
    std::cout << "Room Class: " << apartmentClass << ", Beds: " << numberOfBeds
        << ", Price per Night: $" << pricePerNight << std::endl;
}

Room::~Room() {
    totalRooms--;
    std::cout << "Room destructor called\n";
}

int Room::getTotalRooms() {
    return totalRooms;
}
