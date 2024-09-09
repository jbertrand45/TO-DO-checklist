#include <iostream>
#include "listimplementation.h"

int main() {
    LinkedList<std::string> todoList;

    int choice = 0;
    std::string task;

    do {
        std::cout << "TODO List\n";
        std::cout << "1. Add a task\n";
        std::cout << "2. Delete a task\n";
        std::cout << "3. Show all tasks\n";
        std::cout << "4. Remove all tasks\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: 
                std::cout << "Enter task: ";
                std::cin >> task;
                todoList.insert(todoList.getLength() + 1, task);
                std::cout << "Task added.\n\n";
                break;

            case 2: 
                if (todoList.isEmpty()) {
                    std::cout << "The list is empty.\n\n";
                }
                else {
                    std::cout << "Enter task number to delete: ";
                    int taskNum;
                    std::cin >> taskNum;
                    if (todoList.remove(taskNum)) {
                        std::cout << "Task deleted.\n\n";
                    }
                    else {
                        std::cout << "Invalid task number.\n\n";
                    }
                }
                break;

            case 3: 
                if (todoList.isEmpty()) {
                    std::cout << "The list is empty.\n\n";
                }
                else {
                    std::cout << "TODO List:\n";
                    for (int i = 1; i <= todoList.getLength(); i++) {
                        std::cout << i << ". " << todoList.getEntry(i) << std::endl;
                    }
                    std::cout << std::endl;
                }
                break;

            case 4: 
                todoList.clear();
                std::cout << "All tasks removed.\n\n";
                break;

            case 5: 
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n\n";
                break;
        }

    } while (choice != 5);

    return 0;
}





