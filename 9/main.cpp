#include <iostream>
#include <map>
#include <string>

struct Employee {
    std::string name;
    std::string position;
};

int main() {
    std::map<int, Employee> employees;

    employees[1] = {"Иванов Иван", "Менеджер"};
    employees[2] = {"Петров Петр", "Разработчик"};
    employees[3] = {"Сидоров Сидор", "Тестировщик"};

    for (const auto& [id, employee] : employees) {
        std::cout << "ID: " << id << ", Имя: " << employee.name << ", Должность: " << employee.position << std::endl;
    }

    return 0;
}