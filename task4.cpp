#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;
};

std::vector<Task> tasks;

void addTask(const std::string& description) {
    tasks.push_back({description, false});
    std::cout << "Task added successfully!\n";
}

void viewTasks() {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }

    std::cout << "Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        if (tasks[i].completed)
            std::cout << "[X] ";
        else
            std::cout << "[ ] ";
        std::cout << tasks[i].description << std::endl;
    }
}

void deleteTask(size_t index) {
    if (index >= tasks.size()) {
        std::cout << "Invalid task index.\n";
        return;
    }

    tasks.erase(tasks.begin() + index);
    std::cout << "Task deleted successfully!\n";
}

int main() {
    while (true) {
    	std::cout << "\n===== To-Do List Manager =====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Complete\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore();
                std::cout << "Enter task description: ";
                std::string description;
                std::getline(std::cin, description);
                addTask(description);
                break;
            }
            case 2:
                viewTasks();
                break;
            case 3: {
                viewTasks();
                if (!tasks.empty()) {
                    std::cout << "Enter the index of the task to delete: ";
                    size_t index;
                    std::cin >> index;
                    deleteTask(index - 1);
                }
                break;
            }
            case 4:
                std::cout << "Exiting program...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

