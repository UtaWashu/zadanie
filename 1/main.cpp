#include <iostream>
#include <queue>

class Task {
public:
    Task(int id, int priority) : id(id), priority(priority) {}

    int getId() const {
        return id;
    }

    int getPriority() const {
        return priority;
    }

private:
    int id;
    int priority;
};

struct ComparePriority {
    bool operator()(const Task& t1, const Task& t2) const {
        return t1.getPriority() < t2.getPriority();
    }
};

int main() {
    std::priority_queue<Task, std::vector<Task>, ComparePriority> tasks;

    tasks.push(Task(1, 5));
    tasks.push(Task(2, 3));
    tasks.push(Task(3, 8));
    tasks.push(Task(4, 1));

    while (!tasks.empty()) {
        Task task = tasks.top();
        std::cout << "Task id: " << task.getId() << ", priority: " << task.getPriority() << std::endl;
        tasks.pop();
    }

    return 0;
}