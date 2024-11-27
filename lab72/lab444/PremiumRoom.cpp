#include "PremiumRoom.h"
#include <iostream>

int PremiumRoom::totalPremiumRooms = 0;

PremiumRoom::PremiumRoom() : Room("Premium", 2, 200.0), hasBalcony(true), hasSeaView(true) {
    totalPremiumRooms++;
}

PremiumRoom::PremiumRoom(const std::string& aptClass, int beds, double price, bool balcony, bool view)
    : Room(aptClass, beds, price), hasBalcony(balcony), hasSeaView(view) {
    totalPremiumRooms++;
}

void PremiumRoom::displayRoomInfo() const {
    Room::displayRoomInfo();
    std::cout << "Balcony: " << (hasBalcony ? "Yes" : "No") << ", Sea View: " << (hasSeaView ? "Yes" : "No") << std::endl;
}

int PremiumRoom::getTotalPremiumRooms() {
    return totalPremiumRooms;
}

void PremiumRoom::viewTotalPremiumRooms() {
    std::cout << "Total Premium Rooms: " << totalPremiumRooms << std::endl;
}
