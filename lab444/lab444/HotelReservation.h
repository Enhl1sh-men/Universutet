#ifndef HOTELRESERVATION_H
#define HOTELRESERVATION_H

#include "Client.h"
#include "Room.h"
#include <vector>
#include <string>

class HotelReservation {
public:
    Client client;
    Room room;
    static int totalReservations;

    HotelReservation();
    HotelReservation(const Client& client, Room& room);
    HotelReservation(const HotelReservation& other);
    HotelReservation& operator=(const HotelReservation& other);
    static int getTotalReservations();
    virtual void displayRequest() const;
    virtual ~HotelReservation();

protected:
    double totalAmount;
    bool requestApproved;
    std::vector<std::string> additionalServices;
};

#endif // HOTELRESERVATION_H
