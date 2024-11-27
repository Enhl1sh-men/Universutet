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

    static int getTotalPremiumRooms();  // Статичний метод для отримання кількості об'єктів PremiumRoom
    static void viewTotalPremiumRooms();  // Метод для відображення кількості PremiumRoom об'єктів

private:
    static int totalPremiumRooms;  // Статична змінна для підрахунку об'єктів PremiumRoom
};

#endif // PREMIUMROOM_H
