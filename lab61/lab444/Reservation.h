// Reservation.h
#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <iostream>

class Reservation {
public:
    virtual void displayRequest() const = 0; // ����� ��������� ������� ��� �����������
    virtual ~Reservation() {} // ���������� ����������
};

#endif // RESERVATION_H
