#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        Task task(description);
        tasks.push_back(task);
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
        } else {
            std::cout << "Tasks in the list:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". ";
                if (tasks[i].completed) {
                    std::cout << "[Completed] ";
                }
                std::cout << tasks[i].description << std::endl;
            }
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed: " << tasks[index - 1].description << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            std::cout << "Task removed: " << tasks[index - 1].description << std::endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    ToDoList toDoList;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Quit\n";
        std::cout << "Select an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline character from the input buffer.
std::string description;
        switch (choice) {
            case 1:
                std::cout << "Enter the task description: ";
                // std::string description;
                std::getline(std::cin, description);
                toDoList.addTask(description);
                break;
            case 2:
                toDoList.viewTasks();
                break;
            case 3:
                toDoList.viewTasks();
                std::cout << "Enter the index of the task to mark as completed: ";
                break;
        }
    }
}
