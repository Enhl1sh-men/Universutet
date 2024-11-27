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

    double totalAmount;  // �������� ���� ��� ������������
    bool requestApproved;  // ������ ������������ ������
    std::vector<std::string> additionalServices;  // �������� �������

    HotelReservation();  // ����������� ��� ���������
    HotelReservation(const Client& client, Room& room);  // ����������� � �����������
    HotelReservation(const HotelReservation& other);  // ����������� ���������
    HotelReservation& operator=(const HotelReservation& other);  // �������� ���������
    static int getTotalReservations();  // ��������� ����� ��� ��������� ������� �����������
    static void viewTotalReservations();  // ����� ��� ����������� �������� ������� �����������
    virtual void displayRequest() const;  // ³�������� ������� ��� ��������� ������� ������������
    virtual void cancelReservation();  // ³�������� ������� ��� ���������� ������������
    virtual ~HotelReservation();  // ³��������� ����������
};

#endif // HOTELRESERVATION_H
