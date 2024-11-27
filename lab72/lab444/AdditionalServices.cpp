#include "AdditionalServices.h"

// ��������� ������� �� ������
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

// ��������� ��� ������
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

// ��������� ������, ����� ���� �� ����� �� ������ ������� ������� 7 �����
void AdditionalServices::removeServiceIfLessThan(int length) {
    try {
        // �������� �� ��������� ��������
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
