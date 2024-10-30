#include "PremiumRoom.h"
#include <iostream>

PremiumRoom::PremiumRoom() : Room("Premium", 2, 200.0), hasBalcony(true), hasSeaView(true) {}

PremiumRoom::PremiumRoom(const std::string& aptClass, int beds, double price, bool balcony, bool view)
    : Room(aptClass, beds, price), hasBalcony(balcony), hasSeaView(view) {}

void PremiumRoom::displayRoomInfo() const {
    Room::displayRoomInfo();
    std::cout << "Balcony: " << (hasBalcony ? "Yes" : "No") << ", Sea View: " << (hasSeaView ? "Yes" : "No") << std::endl;
}
