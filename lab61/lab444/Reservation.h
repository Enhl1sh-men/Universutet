// Reservation.h
#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <iostream>

class Reservation {
public:
    virtual void displayRequest() const = 0; // чисто віртуальна функція для відображення
    virtual ~Reservation() {} // віртуальний деструктор
};

#endif // RESERVATION_H
