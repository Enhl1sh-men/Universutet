#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    Client();  // Конструктор без параметрів
    Client(const std::string& name);  // Конструктор з параметром
    std::string getClientName() const;  // Геттер для отримання імені клієнта
    void setClientName(const std::string& name);  // Сеттер для встановлення імені клієнта
private:
    std::string clientName;
};

#endif // CLIENT_H
