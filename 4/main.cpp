#include <iostream>
#include <vector>

struct Task {
    int id;
    bool isCompleted;
};

class ProjectManager {
private:
    std::vector<Task> tasks;
public:
    void addTask(int id) {
        tasks.push_back({id, false});
    }

    void completeTask(int id) {
        for (auto& task : tasks) {
            if (task.id == id) {
                task.isCompleted = true;
                std::cout << "Task with ID " << id << " has been completed" << std::endl;
                return;
            }
        }
        std::cout << "Task with ID " << id << " not found" << std::endl;
    }

    void removeTask(int id) {
        for (auto it = tasks.begin(); it != tasks.end(); it++) {
            if (it->id == id) {
                tasks.erase(it);
                std::cout << "Task with ID " << id << " has been removed" << std::endl;
                return;
            }
        }
        std::cout << "Task with ID " << id << " not found" << std::endl;
    }
};

int main() {
    ProjectManager manager;
    manager.addTask(1);
    manager.addTask(2);
    manager.addTask(3);

    manager.completeTask(2);
    manager.removeTask(1);
    manager.removeTask(5);

    return 0;
}