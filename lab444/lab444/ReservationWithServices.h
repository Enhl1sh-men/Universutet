#ifndef RESERVATIONWITHSERVICES_H
#define RESERVATIONWITHSERVICES_H

#include "HotelReservation.h"
#include "AdditionalServices.h"

class ReservationWithServices : public HotelReservation, private AdditionalServices {
public:
    using HotelReservation::displayRequest;
    ReservationWithServices();
    ReservationWithServices(const Client& client, Room& room);

    void addSpecialService(const std::string& service);
    void showAllServices() const;
    virtual ~ReservationWithServices();
};

#endif // RESERVATIONWITHSERVICES_H
