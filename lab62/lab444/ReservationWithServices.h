// ReservationWithServices.h
#ifndef RESERVATIONWITHSERVICES_H
#define RESERVATIONWITHSERVICES_H

#include "HotelReservation.h"
#include "AdditionalServices.h"

class ReservationWithServices : public HotelReservation, public AdditionalServices {
public:
    using HotelReservation::displayRequest;

    ReservationWithServices(); // конструктор за замовчуванням
    ReservationWithServices(const Client& client, Room& room); // конструктор з параметрами
    ReservationWithServices(const ReservationWithServices& other); // конструктор копіювання
    ReservationWithServices& operator=(const ReservationWithServices& other); // оператор присвоєння

    void addSpecialService(const std::string& service); // додавання послуг
    void showAllServices() const; // показ усіх послуг
    virtual ~ReservationWithServices(); // віртуальний деструктор
};

#endif // RESERVATIONWITHSERVICES_H
