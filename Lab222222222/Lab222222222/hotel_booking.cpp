#include "hotel_booking.h"
#include <iostream>
#include <iomanip>
#include <algorithm> 
#include <random>    // For random number generation

using namespace std;

// Booking constructor
Booking::Booking(const User& user, RoomType room, int guests, int stayDays, PaymentMethod method)
    : client(user), roomType(room), paymentMethod(method),
      numOfGuests(guests), days(stayDays), isConfirmed(false), price(0.0) {}

// Adding an additional service
void Booking::addAdditionalService(const AdditionalService& service) {
    additionalServices.push_back(service);
    price += service.cost;
    cout << "Added additional service: " << service.name << " ($" << service.cost << ")\n";
}

// Confirming booking
bool Booking::confirmBooking() {
    if (numOfGuests <= 0 || days <= 0) {
        cout << "Invalid booking data. Cannot confirm.\n";
        return false;
    }
    isConfirmed = true;
    // Calculating base price
    double basePrice = (roomType == RoomType::Standard) ? 50.0 : 100.0;
    price += basePrice * days;
    cout << "Booking confirmed. Total amount: $" << price << "\n";
    return isConfirmed;
}

// Canceling booking
bool Booking::cancelBooking(int hoursBeforeCheckin) {
    if (!isConfirmed) {
        cout << "Booking not confirmed. Nothing to cancel.\n";
        return false;
    }
    if (hoursBeforeCheckin >= 24) {
        isConfirmed = false;
        price = 0.0;
        cout << "Booking successfully canceled.\n";
        return true;
    }
    else {
        cout << "Cannot cancel booking. Less than 24 hours remaining before check-in.\n";
        return false;
    }
}

// Making payment for booking
void Booking::makePayment(double amount) {
    if (!isConfirmed) {
        cout << "Booking not confirmed. Payment is not possible.\n";
        return;
    }

    if (paymentMethod == PaymentMethod::Prepayment) {
        double requiredPrepayment = price * 0.5; // 50% prepayment
        if (amount >= requiredPrepayment) {
            cout << "Prepayment successfully made. Prepayment amount: $" << amount << "\n";
        }
        else {
            cout << "Insufficient prepayment. At least 50% of the amount required: $" << requiredPrepayment << "\n";
        }
    }
    else { // FullPayment
        if (amount >= price) {
            cout << "Full payment successfully made. Payment amount: $" << amount << "\n";
        }
        else {
            cout << "Insufficient payment. Full amount required: $" << price << "\n";
        }
    }
}

// Displaying booking information
void Booking::displayBookingInfo() const {
    cout << "-----------------------------\n";
    cout << "Booking Information:\n";
    cout << "Client: " << client.name << "\n";
    cout << "Email: " << client.email << "\n";
    cout << "Phone Number: " << client.phoneNumber << "\n";
    cout << "Room Type: " << ((roomType == RoomType::Standard) ? "Standard" : "Lux") << "\n";
    cout << "Number of Guests: " << numOfGuests << "\n";
    cout << "Number of Days: " << days << "\n";
    cout << "Payment Method: " << ((paymentMethod == PaymentMethod::FullPayment) ? "Full Payment" : "Prepayment") << "\n";
    cout << "Status: " << (isConfirmed ? "Confirmed" : "Not Confirmed") << "\n";
    cout << "Total Amount: $" << fixed << setprecision(2) << price << "\n";
    if (!additionalServices.empty()) {
        cout << "Additional Services:\n";
        for (const auto& service : additionalServices) {
            cout << " - " << service.name << " ($" << service.cost << ")\n";
        }
    }
    cout << "-----------------------------\n";
}

// Updating number of guests
void Booking::updateBookingDetails(int newNumOfGuests) {
    if (newNumOfGuests <= 0) {
        cout << "Invalid number of guests. Update not performed.\n";
        return;
    }
    numOfGuests = newNumOfGuests;
    cout << "Number of guests updated to " << numOfGuests << ".\n";
}

// Updating number of guests and days
void Booking::updateBookingDetails(int newNumOfGuests, int newDays) {
    if (newNumOfGuests <= 0 || newDays <= 0) {
        cout << "Invalid booking data. Update not performed.\n";
        return;
    }
    numOfGuests = newNumOfGuests;
    days = newDays;
    // Recalculating price based on new days
    double basePrice = (roomType == RoomType::Standard) ? 50.0 : 100.0;
    price = (basePrice * days);
    for (const auto& service : additionalServices) {
        price += service.cost;
    }
    cout << "Number of guests updated to " << numOfGuests << " and number of days to " << days << ".\n";
    cout << "Total amount recalculated: $" << price << "\n";
}

// Updating room type
void Booking::updateRoomType(RoomType newType) {
    roomType = newType;
    // Recalculating base price
    double basePrice = (roomType == RoomType::Standard) ? 50.0 : 100.0;
    price = (basePrice * days);
    for (const auto& service : additionalServices) {
        price += service.cost;
    }
    cout << "Room type updated to " << ((roomType == RoomType::Standard) ? "Standard" : "Lux") << ".\n";
    cout << "Total amount recalculated: $" << price << "\n";
}

// Updating room type with additional cost
void Booking::updateRoomType(RoomType newType, double additionalCost) {
    roomType = newType;
    // Recalculating base price and adding additional cost
    double basePrice = (roomType == RoomType::Standard) ? 50.0 : 100.0;
    price = (basePrice * days) + additionalCost;
    for (const auto& service : additionalServices) {
        price += service.cost;
    }
    cout << "Room type updated to " << ((roomType == RoomType::Standard) ? "Standard" : "Lux")
         << " with additional cost of $" << additionalCost << ".\n";
    cout << "Total amount recalculated: $" << price << "\n";
}

// Method to save booking to file
void Booking::saveToFile(ofstream& out) const {
    // Write User
    client.saveToFile(out);
    // Write RoomType and PaymentMethod
    out << static_cast<int>(roomType) << "\n";
    out << static_cast<int>(paymentMethod) << "\n";
    // Write number of guests and days
    out << numOfGuests << "\n" << days << "\n";
    // Write confirmation status and price
    out << isConfirmed << "\n" << price << "\n";
    // Write number of additional services
    out << additionalServices.size() << "\n";
    for (const auto& service : additionalServices) {
        out << service.name << "\n" << service.cost << "\n";
    }
}

// Method to load booking from file
void Booking::loadFromFile(ifstream& in) {
    // Read User
    cout << "Loading user information...\n";
    client.loadFromFile(in);
    // Read RoomType and PaymentMethod
    int roomTypeInt, paymentMethodInt;
    in >> roomTypeInt >> paymentMethodInt;
    roomType = static_cast<RoomType>(roomTypeInt);
    paymentMethod = static_cast<PaymentMethod>(paymentMethodInt);
    // Read number of guests and days
    in >> numOfGuests >> days;
    // Read confirmation status and price
    in >> isConfirmed >> price;
    // Read number of additional services
    size_t servicesCount;
    in >> servicesCount;
    // Read each additional service
    additionalServices.clear();
    in.ignore(); // Clear newline character before reading lines
    for (size_t i = 0; i < servicesCount; ++i) {
        string serviceName;
        double serviceCost;
        getline(in, serviceName);
        in >> serviceCost;
        in.ignore(); // Clear newline character after reading cost
        additionalServices.emplace_back(serviceName, serviceCost);
    }
}

// Admin reviewing booking
bool Admin::reviewBooking(const Booking& booking) {
    cout << "Administrator reviewing booking...\n";
    // Conditions for confirming booking
    if (booking.getNumOfGuests() > 0 && booking.getDays() > 0) {
        return true;
    }
    return false;
}

// Implementation of new method for allocating and sorting guest counts
void Admin::sortAndDisplayGuests(const vector<Booking>& bookings) {
    // Check for bookings
    if (bookings.empty()) {
        cout << "No bookings to process.\n";
        return;
    }

    // Determine random array size (from 1 to number of bookings)
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, bookings.size());

    int size = dis(gen);
    cout << "\nRandomly selected array size: " << size << "\n";

    // Allocate dynamic memory
    int* guestNumbers = new int[size];

    // Fill array with number of guests from the first 'size' bookings
    for (int i = 0; i < size; ++i) {
        guestNumbers[i] = bookings[i].getNumOfGuests();
    }

    // Display array before sorting
    cout << "Number of guests before sorting: ";
    for (int i = 0; i < size; ++i) {
        cout << guestNumbers[i] << " ";
    }
    cout << "\n";

    // Sort the array
    sort(guestNumbers, guestNumbers + size);

    // Display sorted array
    cout << "Sorted number of guests: ";
    for (int i = 0; i < size; ++i) {
        cout << guestNumbers[i] << " ";
    }
    cout << "\n";

    // Free memory
    delete[] guestNumbers;
}

// Method to save all bookings to a file
void Admin::saveBookingsToFile(const vector<Booking>& bookings, const string& filename) const {
    cout << "Attempting to open file for writing: " << filename << "\n";
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error opening file for writing: " << filename << "\n";
        return;
    }

    // Write number of bookings
    outFile << bookings.size() << "\n";

    // Write each booking
    for (const auto& booking : bookings) {
        booking.saveToFile(outFile);
    }

    outFile.close();
    cout << "All bookings have been saved to " << filename << "\n";
}

// Method to load all bookings from a file
vector<Booking> Admin::loadBookingsFromFile(const string& filename) const {
    vector<Booking> loadedBookings;
    cout << "Attempting to open file for reading: " << filename << "\n";
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening file for reading: " << filename << "\n";
        return loadedBookings;
    }

    // Read number of bookings
    size_t bookingsCount;
    inFile >> bookingsCount;
    inFile.ignore(); // Clear newline character after number

    // Read each booking
    for (size_t i = 0; i < bookingsCount; ++i) {
        Booking booking;
        booking.loadFromFile(inFile);
        loadedBookings.push_back(booking);
    }

    inFile.close();
    cout << "All bookings have been loaded from " << filename << "\n";
    return loadedBookings;
}
