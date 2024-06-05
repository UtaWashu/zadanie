#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct Order {
    int id;
    vector<string> dishes;
};

vector<Order> orders;

unordered_map<int, vector<string>> orderDishes;

void addOrder(int id, vector<string> dishes) {
    Order newOrder = {id, dishes};
    orders.push_back(newOrder);
    orderDishes[id] = dishes;
}

void removeOrder(int id) {
    for (auto it = orders.begin(); it != orders.end(); ++it) {
        if (it->id == id) {
            orders.erase(it);
            break;
        }
    }
    
    orderDishes.erase(id);
}

int main() {
    addOrder(1, {"Pizza", "Salad", "Coke"});
    addOrder(2, {"Burger", "Fries", "Soda"});
    
    for (const auto& order : orders) {
        cout << "Order #" << order.id << ": ";
        for (const auto& dish : order.dishes) {
            cout << dish << " ";
        }
        cout << endl;
    }
    
    removeOrder(1);
    
    for (const auto& order : orders) {
        cout << "Order #" << order.id << ": ";
        for (const auto& dish : order.dishes) {
            cout << dish << " ";
        }
        cout << endl;
    }
    
    return 0;
}
