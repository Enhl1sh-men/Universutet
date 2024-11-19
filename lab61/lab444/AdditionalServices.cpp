#include "AdditionalServices.h"

// Додавання послуги до списку
void AdditionalServices::addService(const std::string& service) {
    try {
        if (service.empty()) {
            throw std::invalid_argument("Service name cannot be empty.");
        }
        services.push_back(service);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error adding service: " << e.what() << std::endl;
    }
}

// Виведення всіх послуг
void AdditionalServices::displayServices() const {
    if (services.empty()) {
        std::cout << "No services available." << std::endl;
    }
    else {
        std::cout << "Available services:" << std::endl;
        for (const auto& service : services) {
            std::cout << "- " << service << std::endl;
        }
    }
}

// Видалення послуг, назва яких має менше ніж задану кількість символів
void AdditionalServices::removeServiceIfLessThan(int length) {
    try {
        // Перевірка на коректний параметр
        if (length <= 0) {
            throw std::invalid_argument("Length must be positive.");
        }

        services.erase(
            std::remove_if(services.begin(), services.end(), [length](const std::string& service) {
                return service.length() < length;
                }),
            services.end()
        );

        std::cout << "Services with names shorter than " << length << " characters removed." << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error removing services: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during service removal." << std::endl;
    }
}
AdditionalServices& AdditionalServices::operator=(const AdditionalServices& other) {
    if (this != &other) {
        services = other.services;
    }
    return *this;
}

AdditionalServices& AdditionalServices::operator+=(const std::string& service) {
    addService(service);
    return *this;
}

AdditionalServices& AdditionalServices::operator-=(const std::string& service) {
    services.erase(std::remove(services.begin(), services.end(), service), services.end());
    return *this;
}

AdditionalServices AdditionalServices::operator*(int multiplier) const {
    AdditionalServices result;
    for (int i = 0; i < multiplier; ++i) {
        result.services.insert(result.services.end(), services.begin(), services.end());
    }
    return result;
}

AdditionalServices& AdditionalServices::operator*=(int multiplier) {
    std::vector<std::string> original = services;
    for (int i = 1; i < multiplier; ++i) {
        services.insert(services.end(), original.begin(), original.end());
    }
    return *this;
}

std::string AdditionalServices::operator[](size_t index) const {
    if (index < services.size()) {
        return services[index];
    }
    throw std::out_of_range("Index out of range");
}