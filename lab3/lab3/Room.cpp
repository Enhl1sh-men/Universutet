#include "Room.h"

// 2. ����������� ��� ���������
Room::Room() : minPrice(50.0), apartmentClass("Standard"), numberOfBeds(1), pricePerNight(100.0) {}

// 2. ����������� � ����������� �� ������� ����������� 
Room::Room(const std::string& aptClass, int beds, double price)
    : minPrice(50.0), apartmentClass(aptClass), numberOfBeds(beds), pricePerNight(price) {}

// 1. ����������� ���������
Room::Room(const Room& other)
    : minPrice(other.minPrice), apartmentClass(other.apartmentClass),
    numberOfBeds(other.numberOfBeds), pricePerNight(other.pricePerNight) {}