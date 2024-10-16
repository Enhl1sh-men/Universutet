#ifndef HOTEL_BOOKING_H
#define HOTEL_BOOKING_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Перерахування типів номерів
enum class RoomType {
    Standard = 1,
    Lux
};

// Перерахування методів оплати
enum class PaymentMethod {
    FullPayment,
    Prepayment
};

// Структура для додаткових послуг
struct AdditionalService {
    string name;
    double cost;

    AdditionalService() : name(""), cost(0.0) {}
    AdditionalService(const string& serviceName, double serviceCost)
        : name(serviceName), cost(serviceCost) {}
};

// Клас User для зберігання інформації про клієнта
class User {
public:
    string name;          // Ім'я клієнта
    string email;         // Електронна пошта
    string phoneNumber;   // Номер телефону

    // Конструктор
    User() : name(""), email(""), phoneNumber("") {}
    User(const string& userName, const string& userEmail, const string& userPhone)
        : name(userName), email(userEmail), phoneNumber(userPhone) {}

    // Метод для запису даних користувача у файл
    void saveToFile(ofstream& out) const {
        out << name << "\n" << email << "\n" << phoneNumber << "\n";
    }

    // Метод для читання даних користувача з файлу
    void loadFromFile(ifstream& in) {
        getline(in, name);
        getline(in, email);
        getline(in, phoneNumber);
    }
};

// Клас Booking для управління бронюванням
class Booking {
public:
    // Публічні поля
    User client;                    // Інформація про клієнта
    RoomType roomType;              // Тип номера
    PaymentMethod paymentMethod;    // Метод оплати

private:
    // Приватні поля
    int numOfGuests;                             // Кількість гостей
    int days;                                    // Кількість днів перебування
    bool isConfirmed;                            // Статус підтвердження бронювання
    double price;                                // Загальна вартість бронювання
    vector<AdditionalService> additionalServices; // Додаткові послуги

public:
    // Конструктор
    Booking() : roomType(RoomType::Standard), paymentMethod(PaymentMethod::FullPayment),
        numOfGuests(0), days(0), isConfirmed(false), price(0.0) {}
    Booking(const User& user, RoomType room, int guests, int stayDays, PaymentMethod method);

    // Методи для управління бронюванням
    void addAdditionalService(const AdditionalService& service);
    bool confirmBooking();
    bool cancelBooking(int hoursBeforeCheckin);
    void makePayment(double amount);
    void displayBookingInfo() const;

    // Нові методи для серіалізації та десеріалізації
    void saveToFile(ofstream& out) const;
    void loadFromFile(ifstream& in);

    // Перевантажені методи для оновлення деталей бронювання
    void updateBookingDetails(int newNumOfGuests);
    void updateBookingDetails(int newNumOfGuests, int newDays);

    // Перевантажені методи для оновлення типу номера
    void updateRoomType(RoomType newType);
    void updateRoomType(RoomType newType, double additionalCost);

    // Гетери для приватних полів
    int getNumOfGuests() const { return numOfGuests; }
    int getDays() const { return days; }
    bool getIsConfirmed() const { return isConfirmed; }
    double getPrice() const { return price; }
};

// Клас Admin для перегляду бронювань
class Admin {
public:
    bool reviewBooking(const Booking& booking);

    // Новий метод для виділення та сортування кількостей гостей
    void sortAndDisplayGuests(const vector<Booking>& bookings);

    // Методи для збереження та завантаження бронювань
    void saveBookingsToFile(const vector<Booking>& bookings, const string& filename) const;
    vector<Booking> loadBookingsFromFile(const string& filename) const;
};

#endif // HOTEL_BOOKING_H
