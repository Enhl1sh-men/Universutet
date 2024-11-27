#ifndef ADDITIONALSERVICES_H
#define ADDITIONALSERVICES_H

#include <vector>
#include <string>
#include <iostream>

class AdditionalServices {
public:
    void addService(const std::string& service);
    void displayServices() const;
    void removeServiceIfLessThan(int length);

    // Перевантаження операторів
    AdditionalServices& operator+=(const std::string& service);
    AdditionalServices& operator-=(const std::string& service);
    std::string operator[](int index) const;
    AdditionalServices operator*(int factor) const;

private:
    std::vector<std::string> services;
};

#endif // ADDITIONALSERVICES_H
