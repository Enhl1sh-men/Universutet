#ifndef HOTELRESERVATION_H
#define HOTELRESERVATION_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "Client.h"
#include "Room.h"

class HotelReservation {
public:
    Client client;
    Room room;

    // �������� ���� ��� ��������� ������� ����������
    static int totalReservations;

    // ����������� �� �������������
    HotelReservation();
    // ����������� � �����������
    HotelReservation(const Client& client, Room& room);
    // ����������� ���������
    HotelReservation(const HotelReservation& other);

    HotelReservation& operator=(const HotelReservation& other);

    static int getTotalReservations();

    void displayRequest() const;
    void approveRequest(); // ������� �� ������� �� �����
    void reserveRoom(double amount);
    void reserveRoom(double amount, const std::string& paymentMethod);
    void addService(const std::string& service);
    void writeToFile(const std::string& filename) const;
    static HotelReservation readFromFile(const std::string& filename);

private:
    double totalAmount;
    bool requestApproved;
    std::vector<std::string> additionalServices;

    void sortServices();
};

#endif // HOTELRESERVATION_H
