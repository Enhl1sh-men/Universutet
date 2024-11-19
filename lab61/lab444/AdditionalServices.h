#ifndef ADDITIONALSERVICES_H
#define ADDITIONALSERVICES_H

#include <vector>
#include <string>
#include <iostream>

class AdditionalServices {
public:
    // Додавання послуги
    void addService(const std::string& service);

    // Перевантаження операторів
    AdditionalServices& operator=(const AdditionalServices& other);
    AdditionalServices& operator+=(const std::string& service);
    AdditionalServices& operator-=(const std::string& service);
    AdditionalServices operator*(int multiplier) const;
    AdditionalServices& operator*=(int multiplier);
    std::string operator[](size_t index) const;

    // Виведення всіх послуг
    void displayServices() const;
    void removeServiceIfLessThan(int length);

private:
    std::vector<std::string> services;
};
#endif // ADDITIONALSERVICES_H
