#include "hotel_booking.h"
#include <iostream>
#include <vector>

using namespace std;
static Booking booking1;
static Booking booking2;
static Booking booking3;
static Booking booking4;
static Booking booking5;

int main() {


    // Статичні об'єкти Booking, які будуть розміщені у статичній пам'яті
    
    booking1 = Booking(User("John Doe", "john@example.com", "+123456789"), RoomType::Standard, 2, 3, PaymentMethod::FullPayment);
    booking2 = Booking(User("Jane Smith", "jane@example.com", "+987654321"), RoomType::Lux, 4, 5, PaymentMethod::Prepayment);
    booking3 = Booking(User("Tom Johnson", "tom@example.com", "+123123123"), RoomType::Standard, 1, 2, PaymentMethod::FullPayment);
    booking4 = Booking(User("Emily Davis", "emily@example.com", "+456456456"), RoomType::Lux, 2, 7, PaymentMethod::Prepayment);
    booking5 = Booking(User("Alice Brown", "alice@example.com", "+789789789"), RoomType::Standard, 3, 4, PaymentMethod::FullPayment);
    cout << "\n----- Static Bookings Information -----\n";
    Booking* bookingPtr = &booking1;
    bookingPtr->displayBookingInfo();
    bookingPtr = &booking2;
    bookingPtr->displayBookingInfo();
    bookingPtr = &booking3;
    bookingPtr->displayBookingInfo();
    bookingPtr = &booking4;
    bookingPtr->displayBookingInfo();
    bookingPtr = &booking5;
    bookingPtr->displayBookingInfo();
    // Створюємо 5 об'єктів Booking у динамічній пам'яті
    Booking* booking6 = new Booking(User("Aba John", "john@example.com", "+123456789"), RoomType::Standard, 2, 3, PaymentMethod::FullPayment);
    Booking* booking7 = new Booking(User("Jane Moriarty", "jane@example.com", "+987654321"), RoomType::Lux, 4, 5, PaymentMethod::Prepayment);
    Booking* booking8 = new Booking(User("Tom Johnson", "tom@example.com", "+123123123"), RoomType::Standard, 1, 2, PaymentMethod::FullPayment);
    Booking* booking9 = new Booking(User("Emily Davis", "emily@example.com", "+456456456"), RoomType::Lux, 2, 7, PaymentMethod::Prepayment);
    Booking* booking10 = new Booking(User("Alice Brown", "alice@example.com", "+789789789"), RoomType::Standard, 3, 4, PaymentMethod::FullPayment);

    // Виведемо інформацію про бронювання з динамічних об'єктів
    cout << "\n----- Dynamic Bookings Information -----\n";
    booking6->displayBookingInfo();
    booking7->displayBookingInfo();
    booking8->displayBookingInfo();
    booking9->displayBookingInfo();
    booking10->displayBookingInfo();

    // Define two vectors of Booking objects
    vector<Booking> bookings;           // All bookings
    vector<Booking> confirmedBookings; // Confirmed bookings

    // Create an Admin object
    Admin admin;

    // Define the maximum number of clients
    const int MAX_CLIENTS = 5;

    for (int i = 0; i < MAX_CLIENTS; ++i) {
        string clientName;
        string clientEmail;
        string clientPhone;
        int roomChoice;
        int numOfGuests;
        int days;
        PaymentMethod method;

        cout << "----- Booking for Client #" << (i + 1) << " -----\n";

        cout << "Enter client's name: ";
        getline(cin, clientName);

        cout << "Enter client's email: ";
        getline(cin, clientEmail);

        cout << "Enter client's phone number: ";
        getline(cin, clientPhone);

        // Create User object
        User user(clientName, clientEmail, clientPhone);

        // Display room prices per day
        cout << "Room prices per day:\n";
        cout << "1. Standard room: $50 per day\n";
        cout << "2. Lux room: $100 per day\n";

        cout << "Choose room type:\n1. Standard\n2. Lux\nYour choice: ";
        cin >> roomChoice;
        RoomType roomType = (roomChoice == 2) ? RoomType::Lux : RoomType::Standard;

        cout << "Enter number of guests: ";
        cin >> numOfGuests;

        cout << "Enter number of days of stay: ";
        cin >> days;

        cout << "Choose payment method:\n1. Full Payment\n2. Prepayment\nYour choice: ";
        int paymentChoice;
        cin >> paymentChoice;
        method = (paymentChoice == 2) ? PaymentMethod::Prepayment : PaymentMethod::FullPayment;

        // Clear buffer before next line input
        cin.ignore();

        // Create booking
        Booking booking(user, roomType, numOfGuests, days, method);

        // Display available additional services with prices
        cout << "\nAvailable Additional Services:\n";
        cout << "1. Breakfast: $10\n";
        cout << "2. Spa: $50\n";
        cout << "3. Late Check-Out: $30\n";
        cout << "4. Airport Transfer: $40\n";

        // Add additional services
        char addService;
        do {
            cout << "Would you like to add an additional service? (y/n): ";
            cin >> addService;

            if (addService == 'y' || addService == 'Y') {
                int serviceChoice;
                cout << "Choose a service by number: ";
                cin >> serviceChoice;

                // Handle service choice
                switch (serviceChoice) {
                    case 1:
                        booking.addAdditionalService(AdditionalService("Breakfast", 10.0));
                        break;
                    case 2:
                        booking.addAdditionalService(AdditionalService("Spa", 50.0));
                        break;
                    case 3:
                        booking.addAdditionalService(AdditionalService("Late Check-Out", 30.0));
                        break;
                    case 4:
                        booking.addAdditionalService(AdditionalService("Airport Transfer", 40.0));
                        break;
                    default:
                        cout << "Invalid service choice. Please try again.\n";
                        continue;
                }
                cout << "Service added successfully.\n";
            }
        } while (addService == 'y' || addService == 'Y');

        // Add booking to the list
        bookings.push_back(booking);

        // Check if user wants to continue
        if (i < MAX_CLIENTS - 1) {
            char continueChoice;
            cout << "Would you like to add another client? (y/n): ";
            cin >> continueChoice;
            cin.ignore();
            if (continueChoice != 'y' && continueChoice != 'Y') {
                break;
            }
        }
    }

    // Administrator reviews and confirms bookings
    for (auto& booking : bookings) {
        cout << "\n----- Reviewing booking for client: " << booking.client.name << " -----\n";
        if (admin.reviewBooking(booking)) {
            cout << "Booking confirmed by administrator.\n";
            booking.confirmBooking();
            confirmedBookings.push_back(booking); // Add to confirmed bookings
        }
        else {
            cout << "Booking rejected by administrator.\n";
            continue;
        }

        // Display booking information
        booking.displayBookingInfo();

        // Process payment
        cout << "Enter payment amount: $";
        double payment;
        cin >> payment;
        booking.makePayment(payment);

        // Option to cancel booking
        char cancelChoice;
        cout << "Would you like to cancel the booking? (y/n): ";
        cin >> cancelChoice;
        if (cancelChoice == 'y' || cancelChoice == 'Y') {
            int hoursBeforeCheckin;
            cout << "Enter number of hours remaining before check-in: ";
            cin >> hoursBeforeCheckin;
            booking.cancelBooking(hoursBeforeCheckin);
        }

        // Display final booking information
        booking.displayBookingInfo();

        // Clear buffer before next loop
        cin.ignore();
    }

    // Display all confirmed bookings
    cout << "\n----- List of Confirmed Bookings -----\n";
    for (const auto& confirmed : confirmedBookings) {
        confirmed.displayBookingInfo();
    }

    // Call the new method to sort guest counts
    admin.sortAndDisplayGuests(bookings);

    // Saving bookings to file
    char saveChoice;
    cout << "\nWould you like to save all bookings to a file? (y/n): ";
    cin >> saveChoice;
    cin.ignore();
    if (saveChoice == 'y' || saveChoice == 'Y') {
        string filename;
        cout << "Enter filename to save bookings (e.g., bookings.txt): ";
        getline(cin, filename);
        admin.saveBookingsToFile(bookings, filename);
    }

    // Loading bookings from file
    char loadChoice;
    cout << "\nWould you like to load bookings from a file? (y/n): ";
    cin >> loadChoice;
    cin.ignore();
    if (loadChoice == 'y' || loadChoice == 'Y') {
        string filename;
        cout << "Enter filename to load bookings from (e.g., bookings.txt): ";
        getline(cin, filename);
        vector<Booking> loadedBookings = admin.loadBookingsFromFile(filename);
        // Optionally add loaded bookings to the current list
        bookings.insert(bookings.end(), loadedBookings.begin(), loadedBookings.end());

        // Display loaded bookings
        cout << "\n----- Loaded Bookings -----\n";
        for (const auto& booking : loadedBookings) {
            booking.displayBookingInfo();
        }
    }
    
   
    // Видаляємо об'єкти з динамічної пам'яті
    delete booking6;
    delete booking7;
    delete booking8;
    delete booking9;
    delete booking10;

    cout << "\nAll bookings have been processed.\n";
    return 0;
}
