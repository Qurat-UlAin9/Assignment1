#include <iostream>
#include <string>
using namespace std;

// Define structure for task node
struct TaskNode {
    int taskId;
    string taskDescription;
    int priority;
    TaskNode* next;
};

// Initialize head of linked list
TaskNode* head = NULL;

/* Adds a new task to the linked list, maintaining priority order.
  New task is inserted at the beginning if its priority is higher than the current head */
void addTask() {
    TaskNode* newNode = new TaskNode;
    cout << "Enter task ID: ";
    cin >> newNode->taskId;
     // Check for duplicate task IDs
    TaskNode* current = head;
    while (current != NULL) {
        if (current->taskId == newNode->taskId) {
            cout << "Task ID already exists. Please enter a unique ID." << endl;
            delete newNode;
            return;
        }
        current = current->next;
    }
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newNode->taskDescription);
    cout << "Enter priority level: ";
    cin >> newNode->priority;

    // Check if list is empty or new task has higher priority than head
    if (head == NULL || newNode->priority > head->priority) {
        newNode->next = head;
        head = newNode;
    } else {
        TaskNode* current = head;
        // Traverse list to find correct position for new task
        while (current->next != NULL && current->next->priority >= newNode->priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Displays all tasks in the linked list. Prints task ID, description, and priority level for each task.
 
void viewTasks() {
    TaskNode* current = head;
    if (current == NULL) {
        cout << "No tasks available." << endl;
    } else {
        cout << "Task List:" << endl;
        while (current != NULL) {
            cout << "Task ID: " << current->taskId << endl;
            cout << "Task Description: " << current->taskDescription << endl;
            cout << "Priority Level: " << current->priority << endl << endl;
            current = current->next;
        }
    }
}

/*
  Removes the highest priority task from the linked list.
  Updates head pointer to the next task in the list.
 */
void removeHighestPriorityTask() {
    if (head == NULL) {
        cout << "No tasks available." << endl;
    } else {
        TaskNode* temp = head;
        head = head->next;
        delete temp;
        cout << "Highest priority task removed." << endl;
    }
}

/*
  Removes a task by its ID from the linked list.
  Updates pointers to maintain list integrity.
 */
void removeTaskById() {
    int taskId;
    cout << "Enter task ID to remove: ";
    cin >> taskId;
    TaskNode* current = head;
    TaskNode* previous = NULL;

    // Traverse list to find task with matching ID
    while (current != NULL && current->taskId != taskId) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Task not found." << endl;
    } else if (previous == NULL) {
     
        head = head->next;
        delete current;
        cout << "Task removed." << endl;
    } else {
        previous->next = current->next;
        delete current;
        cout << "Task removed." << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "Task Management System" << endl;
        cout << "1. Add new task" << endl;
        cout << "2. View all tasks" << endl;
        cout << "3. Remove highest priority task" << endl;
        cout << "4. Remove task by ID" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                removeHighestPriorityTask();
                break;
            case 4:
                removeTaskById();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please choose again." << endl;
        }
    } while (choice != 5);
    return 0;
}

