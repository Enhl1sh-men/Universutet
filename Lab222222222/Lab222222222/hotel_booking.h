#ifndef HOTEL_BOOKING_H
#define HOTEL_BOOKING_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

// ������������� ���� ������
enum class RoomType {
    Standard = 1,
    Lux
};

// ������������� ������ ������
enum class PaymentMethod {
    FullPayment,
    Prepayment
};

// ��������� ��� ���������� ������
struct AdditionalService {
    string name;
    double cost;

    AdditionalService() : name(""), cost(0.0) {}
    AdditionalService(const string& serviceName, double serviceCost)
        : name(serviceName), cost(serviceCost) {}
};

// ���� User ��� ��������� ���������� ��� �볺���
class User {
public:
    string name;          // ��'� �볺���
    string email;         // ���������� �����
    string phoneNumber;   // ����� ��������

    // �����������
    User() : name(""), email(""), phoneNumber("") {}
    User(const string& userName, const string& userEmail, const string& userPhone)
        : name(userName), email(userEmail), phoneNumber(userPhone) {}

    // ����� ��� ������ ����� ����������� � ����
    void saveToFile(ofstream& out) const {
        out << name << "\n" << email << "\n" << phoneNumber << "\n";
    }

    // ����� ��� ������� ����� ����������� � �����
    void loadFromFile(ifstream& in) {
        getline(in, name);
        getline(in, email);
        getline(in, phoneNumber);
    }
};

// ���� Booking ��� ��������� �����������
class Booking {
public:
    // ������ ����
    User client;                    // ���������� ��� �볺���
    RoomType roomType;              // ��� ������
    PaymentMethod paymentMethod;    // ����� ������

private:
    // ������� ����
    int numOfGuests;                             // ʳ������ ������
    int days;                                    // ʳ������ ��� �����������
    bool isConfirmed;                            // ������ ������������ ����������
    double price;                                // �������� ������� ����������
    vector<AdditionalService> additionalServices; // �������� �������

public:
    // �����������
    Booking() : roomType(RoomType::Standard), paymentMethod(PaymentMethod::FullPayment),
        numOfGuests(0), days(0), isConfirmed(false), price(0.0) {}
    Booking(const User& user, RoomType room, int guests, int stayDays, PaymentMethod method);

    // ������ ��� ��������� �����������
    void addAdditionalService(const AdditionalService& service);
    bool confirmBooking();
    bool cancelBooking(int hoursBeforeCheckin);
    void makePayment(double amount);
    void displayBookingInfo() const;

    // ��� ������ ��� ���������� �� ������������
    void saveToFile(ofstream& out) const;
    void loadFromFile(ifstream& in);

    // ������������ ������ ��� ��������� ������� ����������
    void updateBookingDetails(int newNumOfGuests);
    void updateBookingDetails(int newNumOfGuests, int newDays);

    // ������������ ������ ��� ��������� ���� ������
    void updateRoomType(RoomType newType);
    void updateRoomType(RoomType newType, double additionalCost);

    // ������ ��� ��������� ����
    int getNumOfGuests() const { return numOfGuests; }
    int getDays() const { return days; }
    bool getIsConfirmed() const { return isConfirmed; }
    double getPrice() const { return price; }
};

// ���� Admin ��� ��������� ���������
class Admin {
public:
    bool reviewBooking(const Booking& booking);

    // ����� ����� ��� �������� �� ���������� ��������� ������
    void sortAndDisplayGuests(const vector<Booking>& bookings);

    // ������ ��� ���������� �� ������������ ���������
    void saveBookingsToFile(const vector<Booking>& bookings, const string& filename) const;
    vector<Booking> loadBookingsFromFile(const string& filename) const;
};

#endif // HOTEL_BOOKING_H
