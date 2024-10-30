#ifndef PREMIUMROOM_H
#define PREMIUMROOM_H

#include "Room.h"

class PremiumRoom : public Room {
public:
    bool hasBalcony;
    bool hasSeaView;

    PremiumRoom();
    PremiumRoom(const std::string& aptClass, int beds, double price, bool balcony, bool view);

    void displayRoomInfo() const override;
};

#endif // PREMIUMROOM_H
