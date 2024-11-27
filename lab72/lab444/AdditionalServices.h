#ifndef ADDITIONALSERVICES_H
#define ADDITIONALSERVICES_H

#include <vector>
#include <string>
#include <iostream>

class AdditionalServices {
public:
    // Додавання послуги
    void addService(const std::string& service);

    // Виведення всіх послуг
    void displayServices() const;

    // Видалення послуг, назва яких має менше, ніж задану кількість символів
    void removeServiceIfLessThan(int length);

private:
    std::vector<std::string> services;
};

#endif // ADDITIONALSERVICES_H
