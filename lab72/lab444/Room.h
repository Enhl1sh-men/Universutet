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

    Room();  // 4 ����� ����������� ��� ���������
    Room(const std::string& aptClass, int beds, double price);  // ����������� � �����������
    Room(const Room& other);  // ����������� ���������
    Room& operator=(const Room& other);  // �������� ���������
    virtual void displayRoomInfo() const;  //5����� ³�������� ������� ��� ����������� ����������
    virtual ~Room();  // ³��������� ����������

    static int getTotalRooms();  // ��������� ����� ��� ��������� ������� ��������� ��'���� Room 9

private:
    static int totalRooms;  // �������� ����� ��� ��������� ��'���� Room 9
};

#endif // ROOM_H
