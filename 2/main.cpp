#include <iostream>
#include <vector>

struct Order {
    int orderNumber;
    float amount;
};

int main() {
    std::vector<Order> orders;

    Order newOrder;
    newOrder.orderNumber = 1;
    newOrder.amount = 100.0f;

    orders.push_back(newOrder);

    int orderNumberToDelete = 1;
    for (auto it = orders.begin(); it != orders.end(); ++it) {
        if (it->orderNumber == orderNumberToDelete) {
            orders.erase(it);
            break;
        }
    }

    for (const auto& order : orders) {
        std::cout << "Order number: " << order.orderNumber << ", Amount: " << order.amount << std::endl;
    }

    return 0;
}