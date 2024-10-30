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

    Room();
    Room(const std::string& aptClass, int beds, double price);
    Room(const Room& other);
    Room& operator=(const Room&) = delete;
    virtual void displayRoomInfo() const;
    virtual ~Room();
};

#endif // ROOM_H
