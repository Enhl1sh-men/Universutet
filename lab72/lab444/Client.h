#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    Client();  // Конструктор без параметрів
    Client(const std::string& name);  // Конструктор з параметром

    std::string getClientName() const;  // Геттер для отримання імені клієнта
    void setClientName(const std::string& name);  // Сеттер для встановлення імені клієнта

    // Оператор < для порівняння клієнтів за іменем
    bool operator<(const Client& other) const {
        return clientName < other.clientName;
    }

private:
    std::string clientName;
};

#endif // CLIENT_H
