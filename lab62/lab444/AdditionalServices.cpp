#include "AdditionalServices.h"
#include <algorithm>

void AdditionalServices::addService(const std::string& service) {
    if (!service.empty()) {
        services.push_back(service);
    }
}

void AdditionalServices::displayServices() const {
    if (services.empty()) {
        std::cout << "No services available.\n";
        return;
    }
    for (const auto& service : services) {
        std::cout << "- " << service << std::endl;
    }
}

void AdditionalServices::removeServiceIfLessThan(int length) {
    services.erase(std::remove_if(services.begin(), services.end(),
        [length](const std::string& service) {
            return service.length() < length;
        }),
        services.end());
}

AdditionalServices& AdditionalServices::operator+=(const std::string& service) {
    addService(service);
    return *this;
}

AdditionalServices& AdditionalServices::operator-=(const std::string& service) {
    auto it = std::find(services.begin(), services.end(), service);
    if (it != services.end()) {
        services.erase(it);
    }
    return *this;
}

std::string AdditionalServices::operator[](int index) const {
    if (index >= 0 && index < static_cast<int>(services.size())) {
        return services[index];
    }
    return "Invalid index";
}

AdditionalServices AdditionalServices::operator*(int factor) const {
    AdditionalServices result;
    for (const auto& service : services) {
        for (int i = 0; i < factor; ++i) {
            result.addService(service);
        }
    }
    return result;
}
