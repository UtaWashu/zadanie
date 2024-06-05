#include <iostream>
#include <map>

struct Item {
    std::string name;
    int quantity;
};

std::map<int, Item> inventory;

void addItem(int id, std::string name, int quantity) {
    Item newItem;
    newItem.name = name;
    newItem.quantity = quantity;
    inventory[id] = newItem;
}

void removeItem(int id) {
    auto it = inventory.find(id);
    if(it != inventory.end()) {
        inventory.erase(it);
    }
}

int main() {
    addItem(1, "Item1", 10);
    addItem(2, "Item2", 5);
    
    std::cout << "Текущий инвентарь:" << std::endl;
    for(const auto& item : inventory) {
        std::cout << "ID: " << item.first << ", Name: " << item.second.name << ", Count: " << item.second.quantity << std::endl;
    }
    
    removeItem(1);
    
    std::cout << "Инвентарь после удаления:" << std::endl;
    for(const auto& item : inventory) {
        std::cout << "ID: " << item.first << ", Name: " << item.second.name << ", Count: " << item.second.quantity << std::endl;
    }
    
    return 0;
}
