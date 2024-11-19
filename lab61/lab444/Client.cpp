#include "Client.h"

Client::Client() : clientName("") {}

Client::Client(const std::string& name) : clientName(name) {}

std::string Client::getClientName() const {
    return clientName;
}

void Client::setClientName(const std::string& name) {
    clientName = name;
}

Client Client::operator+(const Client& other) {
    return Client(clientName + " & " + other.clientName);
}

Client Client::operator-(const Client& other) {
    return Client(clientName);  // Створюємо новий клієнт з поточним іменем без імені іншого
}
