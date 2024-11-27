#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include "HotelReservation.h"
#include "Client.h"
#include "Room.h"
#include "ReservationWithServices.h"
#include "AdditionalServices.h"
#include "PremiumRoom.h"
#include <functional>

int main() {
    // 1. Використання vector для зберігання об'єктів Roomмасив з довільним доступом, найчастіше застосовується тоді, коли треба послідовно додавати дані в кінець ланцюжка;
    std::vector<Room> roomsVector;
    roomsVector.push_back(Room("Standard", 1, 100.0));
    roomsVector.push_back(Room("Deluxe", 2, 150.0));

    // Виведення даних з vector
    std::cout << "Rooms in vector:\n";
    for (const auto& room : roomsVector) {
        room.displayRoomInfo();
    }

    // Використання алгоритму sort для vector
    std::sort(roomsVector.begin(), roomsVector.end(), [](const Room& a, const Room& b) {
        return a.pricePerNight < b.pricePerNight;
        });

    std::cout << "Sorted rooms by price:\n";
    for (const auto& room : roomsVector) {
        room.displayRoomInfo();
    }

    // 2. Використання list для зберігання об'єктів Client схожий на вектор, але ефективний при додаванні і видаленні даних в будь-яке місце ланцюжка;
    std::list<Client> clientsList;
    clientsList.emplace_back("Alice");
    clientsList.emplace_back("Bob");

    // Виведення даних з list
    std::cout << "\nClients in list:\n";
    for (const auto& client : clientsList) {
        std::cout << "Client Name: " << client.getClientName() << std::endl;
    }

    // Використання методу remove для видалення елемента з list
    clientsList.remove_if([](const Client& client) {
        return client.getClientName().length() < 4;  // Видалення клієнтів з короткими іменами
        });

    std::cout << "\nClients after removal:\n";
    for (const auto& client : clientsList) {
        std::cout << "Client Name: " << client.getClientName() << std::endl;
    }

    // 3. Використання deque для зберігання об'єктів HotelReservation контейнер, зручний для вставки даних на початок або кінець;
    std::deque<HotelReservation> reservationsDeque;
    reservationsDeque.emplace_back(Client("Charlie"), roomsVector[0]);
    reservationsDeque.emplace_back(Client("Diana"), roomsVector[1]);

    std::cout << "\nReservations in deque:\n";
    for (const auto& reservation : reservationsDeque) {
        reservation.displayRequest();
    }

    // 4. Використання set для зберігання унікальних значень назв кімнат набір унікальних елементів, відсортованих в певному порядку;
    std::set<std::string> roomTypesSet;
    roomTypesSet.insert("Suite");
    roomTypesSet.insert("Economy");
    roomTypesSet.insert("Suite");  // Дублікат не буде доданий

    std::cout << "\nRoom types in set:\n";
    for (const auto& type : roomTypesSet) {
        std::cout << type << std::endl;
    }

    // 5. Використання multiset для зберігання значень з повтореннями те ж, що і set, але може містити повторювані копії;
    std::multiset<std::string> roomTypesMultiset;
    roomTypesMultiset.insert("Suite");
    roomTypesMultiset.insert("Economy");
    roomTypesMultiset.insert("Suite");  // Дублікат буде доданий

    std::cout << "\nRoom types in multiset:\n";
    for (const auto& type : roomTypesMultiset) {
        std::cout << type << std::endl;
    }

    // 6. Використання map для зберігання пар Client -> Room забезпечує доступ до значень за ключам;
    std::map<Client, Room> clientRoomMap;
    clientRoomMap[Client("Edward")] = roomsVector[0];
    clientRoomMap[Client("Fiona")] = roomsVector[1];

    std::cout << "\nClient-Room map:\n";
    for (const auto& pair : clientRoomMap) {
        std::cout << "Client: " << pair.first.getClientName() << " - ";
        pair.second.displayRoomInfo();
    }

    // 7. Використання multimap для зберігання пар з повтореннями - те ж, що і map, але допускає повторювані ключі;
    std::multimap<Client, Room> clientRoomMultimap;
    clientRoomMultimap.insert({ Client("George"), roomsVector[0] });
    clientRoomMultimap.insert({ Client("George"), roomsVector[1] });

    std::cout << "\nClient-Room multimap:\n";
    for (const auto& pair : clientRoomMultimap) {
        std::cout << "Client: " << pair.first.getClientName() << " - ";
        pair.second.displayRoomInfo();
    }

    // 8. Використання stack для роботи з об'єктами Room дані додаються в одному порядку, а виймаються у зворотному;
    std::stack<Room> roomStack;
    roomStack.push(roomsVector[0]);
    roomStack.push(roomsVector[1]);

    std::cout << "\nTop room in stack:\n";
    roomStack.top().displayRoomInfo();
    roomStack.pop();

    // 9. Використання queue для роботи з об'єктами Client - дані додаються і виймаються в тому ж порядку;

    std::queue<Client> clientQueue;
    clientQueue.push(Client("Henry"));
    clientQueue.push(Client("Isabel"));

    std::cout << "\nFirst client in queue:\n";
    std::cout << clientQueue.front().getClientName() << std::endl;
    clientQueue.pop();

    // 10. Використання priority_queue для роботи з об'єктами Room за пріоритетом ціни те ж, що і queue, але може сортувати дані по пріоритету
    std::priority_queue<Room, std::vector<Room>, std::function<bool(const Room&, const Room&)>> roomPQ(
        [](const Room& a, const Room& b) {
            return a.pricePerNight < b.pricePerNight;  // Від вищої до нижчої ціни
        }
    );

    roomPQ.push(roomsVector[0]);
    roomPQ.push(roomsVector[1]);

    std::cout << "\nTop room in priority queue (highest price):\n";
    roomPQ.top().displayRoomInfo();

    // 3.1 Вхідний (input) ітератор:  для читання даних.
    std::cout << "\nUsing input iterator (const_iterator):\n";
    for (std::vector<Room>::const_iterator it = roomsVector.begin(); it != roomsVector.end(); ++it) {
        it->displayRoomInfo();  // Читання елементів
    }

    // 3.2 Вихідний (output) ітератор: для запису даних.
    std::cout << "\nUsing output iterator (we don't read, only write):\n";
    std::vector<Room> newRoomsVector;
    std::back_insert_iterator<std::vector<Room>> outputIt(newRoomsVector);
    *outputIt = Room("Suite", 3, 200.0);  // Записуємо нову кімнату

    for (const auto& room : newRoomsVector) {
        room.displayRoomInfo();  // Виведення нової кімнати
    }

    // 3.3 Односпрямований (forward) ітератор: підтримує однонаправлений доступ.
    std::cout << "\nUsing forward iterator (moving forward only):\n";
    for (std::vector<Room>::iterator it = roomsVector.begin(); it != roomsVector.end(); ++it) {
        it->displayRoomInfo();  // Читання елементів
    }

    // 3.4 Двонаправлений (bidirectional) ітератор: дозволяє переміщуватися в обох напрямках. 
    std::cout << "\nUsing bidirectional iterator (moving forward and backward):\n";
    std::list<int> myList = { 1, 2, 3, 4, 5 };
    std::list<int>::iterator it = myList.begin();
    std::cout << *it << " ";  // Читання вперед
    ++it;
    std::cout << *it << " ";  // Читання вперед
    --it;
    std::cout << *it << " ";  // Читання назад
    std::cout << std::endl;

    // 3.5 Довільного доступу (random access) ітератор: дозволяє доступ до довільного елемента
    std::cout << "\nUsing random access iterator (access by index):\n";
    std::deque<int> myDeque = { 10, 20, 30, 40, 50 };
    for (std::deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 4. Застосування алгоритмів

    // Алгоритм 1: std::for_each для виконання операцій над елементами
    std::cout << "\nApplying std::for_each to roomsVector:\n";
    std::for_each(roomsVector.begin(), roomsVector.end(), [](Room& room) {
        room.displayRoomInfo();
        });

    // Алгоритм 2: std::sort для сортування кімнат за ціною
    std::cout << "\nApplying std::sort to roomsVector (sorted by price):\n";
    std::sort(roomsVector.begin(), roomsVector.end(), [](const Room& a, const Room& b) {
        return a.pricePerNight < b.pricePerNight;  // Сортуємо за ціною
        });

    // Виведення відсортованого списку кімнат
    for (const auto& room : roomsVector) {
        room.displayRoomInfo();
    }

    return 0;
}
