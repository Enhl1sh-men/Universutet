#ifndef ADDITIONALSERVICES_H
#define ADDITIONALSERVICES_H

#include <string>
#include <vector>
#include <algorithm>

class AdditionalServices {
public:
    void addService(const std::string& service);
    void displayServices() const;

private:
    std::vector<std::string> services;

    void sortServices();
};

#endif // ADDITIONALSERVICES_H