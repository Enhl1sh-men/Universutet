#include "AdditionalServices.h"
#include <algorithm>
#include <iostream>

void AdditionalServices::addService(const std::string& service) {
    services.push_back(service);
    sortServices();
}

void AdditionalServices::displayServices() const {
    for (const auto& service : services) {
        std::cout << service << std::endl;
    }
}

void AdditionalServices::sortServices() {
    std::sort(services.begin(), services.end());
}
