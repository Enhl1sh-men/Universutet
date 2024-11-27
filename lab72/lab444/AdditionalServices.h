#ifndef ADDITIONALSERVICES_H
#define ADDITIONALSERVICES_H

#include <vector>
#include <string>
#include <iostream>

class AdditionalServices {
public:
    // ��������� �������
    void addService(const std::string& service);

    // ��������� ��� ������
    void displayServices() const;

    // ��������� ������, ����� ���� �� �����, �� ������ ������� �������
    void removeServiceIfLessThan(int length);

private:
    std::vector<std::string> services;
};

#endif // ADDITIONALSERVICES_H
