#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>

class Room {
public:
    int numberOfBeds;
    const double minPrice;
    double pricePerNight;
    std::string apartmentClass;

    Room();  // ����������� ��� ���������
    Room(const std::string& aptClass, int beds, double price);  // ����������� � �����������
    Room(const Room& other);  // ����������� ���������
    Room& operator=(const Room& other);  // �������� ���������
    virtual void displayRoomInfo() const;  // ³�������� ������� ��� ����������� ����������
    virtual ~Room();  // ³��������� ����������

    // �������������� ���������
    Room operator+(const Room& other) const;
    Room operator-(const Room& other) const;

    static int getTotalRooms();  // ��������� ����� ��� ��������� ������� ��������� ��'���� Room

private:
    static int totalRooms;  // �������� ����� ��� ��������� ��'���� Room
};

#endif // ROOM_H
