#include <iostream>
#include <unordered_map>
#include <string>

struct Transport {
    int id;
    std::string model;

    Transport(int id, std::string model) : id(id), model(model) {}
};

int main() {
    std::unordered_map<int, Transport> transportMap;

    Transport car1(1, "Toyota Camry");
    Transport car2(2, "Honda Civic");

    transportMap[car1.id] = car1;
    transportMap[car2.id] = car2;
    int idToFind = 2;

    if (transportMap.find(idToFind) != transportMap.end()) {
        Transport foundTransport = transportMap[idToFind];
        std::cout << "Транспортное средство с ID " << idToFind << " найдено. Модель: " << foundTransport.model << std::endl;
    } else {
        std::cout << "Транспортное средство с ID " << idToFind << " не найдено." << std::endl;
    }

    return 0;
}