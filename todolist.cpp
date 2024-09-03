#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.emplace_back(description);
        cout << "Task added." << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << (i + 1) << ". " << tasks[i].description
                 << " - " << (tasks[i].completed ? "Completed" : "Not Completed") << endl;
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void deleteTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + (index - 1));
            cout << "Task deleted." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

void showMenu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Delete Task" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    TodoList todoList;
    int choice;
    size_t taskIndex;
    string taskDescription;

    while (true) {
        showMenu();
        cout << "Select an option (1-5): ";
        cin >> choice;
        cin.ignore();  // Clear newline character from the input buffer

        switch (choice) {
            case 1:
                cout << "Enter the task description: ";
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;

            case 2:
                todoList.viewTasks();
                break;

            case 3:
                todoList.viewTasks();
                cout << "Enter the number of the task to mark as completed: ";
                cin >> taskIndex;
                todoList.markTaskAsCompleted(taskIndex);
                break;

            case 4:
                todoList.viewTasks();
                cout << "Enter the number of the task to delete: ";
                cin >> taskIndex;
                todoList.deleteTask(taskIndex);
                break;

            case 5:
                cout << "Exiting the application." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    }

    return 0;
}


