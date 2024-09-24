#include <iostream>
#include <string>
using namespace std;

// Define structure for node
struct TaskNode {
    int taskId;
    string taskDescription;
    int priority;
    TaskNode* next;
};TaskNode* head = NULL, *tail = NULL;

// Function to add new task
void addTask() {
  TaskNode* newNode = new TaskNode;
  cout << "Enter task ID: ";
  cin >> newNode->taskId;

  // Check for duplicate task IDs
  TaskNode* current = head;
  while (current != NULL) {
    if (current->taskId == newNode->taskId) {
      cout << "Task ID already exists." << endl;
      delete newNode;
      return;
    }current = current->next;
  }
  cout << "Enter task description: ";
  cin.ignore();
  getline(cin, newNode->taskDescription);
  cout << "Enter priority level: ";
  cin >> newNode->priority;

  //check for empty list
  if (head == NULL) {
    newNode->next = NULL;
    head = tail = newNode;
  } else {
    if (newNode->priority > head->priority) {
      newNode->next = head;
      head = newNode;
      if (newNode->next == tail) {
        tail = newNode->next;
      }
    } else {
      current = head;
      //check for priority order
      while (current->next != NULL &&
        current->next->priority >= newNode->priority) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
      if (newNode->next == NULL) {
        tail = newNode;
      }
    }
  }
}
// Function to view all tasks
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
// Function to remove high priority task
void removeHighPriorityTask() {
  if (head == NULL) {
    cout << "No tasks available." << endl;
    return;
  }
  TaskNode* maxNode = head;
  TaskNode* prevMaxNode = NULL;
  TaskNode* current = head;
  TaskNode* prev = NULL;
  while (current != NULL) {
    if (current->priority > maxNode->priority) {
      maxNode = current;
      prevMaxNode = prev;
    }
    prev = current;
    current = current->next;
  }
  if (prevMaxNode == NULL) {
    head = maxNode->next;
  } else {
    prevMaxNode->next = maxNode->next;
  }
  if (maxNode == tail) {
    tail = prevMaxNode;
  }
  delete maxNode;
  cout << "Highest priority task removed." << endl;
}
// Function to remove task by ID
void removeTaskById() {
    int idToRemove;
    cout << "Enter task ID to remove: ";
    cin >> idToRemove;

    if (head == NULL) {
        cout << "No tasks available." << endl;
        return;
    }

    if (head->taskId == idToRemove) {
        TaskNode* temp = head;
        head = head->next;
        delete temp;
        cout << "Task removed." << endl;
        return;
    }
    TaskNode* current = head;
    while (current->next != NULL) {
        if (current->next->taskId == idToRemove) {
            TaskNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Task removed." << endl;
            return;
        }
        current = current->next;
    }cout << "Task not found." << endl;
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
                removeHighPriorityTask();
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


