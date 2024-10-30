#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
public:
    int numberOfBeds;
    const double minPrice;
    double pricePerNight;
    std::string apartmentClass;

    // 1. ����������� �� �������������
    Room();

    // 2. ����������� � ����������� � ������������� ������ �����������
    Room(const std::string& aptClass, int beds, double price);

    // 1. ����������� ���������
    Room(const Room& other);

    // 3. ���������� �������� ���������, ������� � ��������� ����
    Room& operator=(const Room&) = delete;
};

#endif // ROOM_H