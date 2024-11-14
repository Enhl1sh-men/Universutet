#include "ReservationWithServices.h"
#include <iostream>
#include <iostream>

ReservationWithServices::ReservationWithServices() : HotelReservation() {}

ReservationWithServices::ReservationWithServices(const Client& client, Room& room)
    : HotelReservation(client, room) {}

void ReservationWithServices::addSpecialService(const std::string& service) {
    addService(service);
}

void ReservationWithServices::showAllServices() const {
    displayServices();
}

ReservationWithServices::~ReservationWithServices() {
    std::cout << "ReservationWithServices destructor called\n";
}