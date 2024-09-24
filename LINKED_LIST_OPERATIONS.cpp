#include <iostream>  
using namespace std; 


struct Task_node {
    int id, priority;    
    string description; 
   // pointer to the next node
    Task_node *next = NULL; 
};

// Function to create a new task node
Task_node *createTask(int id, int priority, string description) {
 // Allocate memory for a new task node
    Task_node *newTask = new Task_node; 
    newTask->id = id;                   
    newTask->priority = priority;       
    newTask->description = description; 
    newTask->next = NULL; // initialize  next pointer to NULL
    return newTask;// return  newly created task node
}

// Function to add a task node to the list based on priority
void add_task(Task_node *&head, Task_node *newTask) {
    if (head == NULL || newTask->priority >= head->priority) {
        newTask->next = head; 
        head = newTask;      
    } else {
        Task_node *current = head; 
        // Traversing the list 
        while (current->next != NULL && current->next->priority > newTask->priority) {
            current = current->next; 
        }
        newTask->next = current->next; 
        current->next = newTask;       
    }
    cout << "Task added successfully!" << endl; 
}

// Function to remove the task with the highest priority 
void remove_on_priority(Task_node *&head) {
    if (head != NULL) {         
        Task_node *temp = head; 
        head = head->next;      
        delete temp;           
    }
}

// Function to remove a task by its id
void remove_by_id(Task_node *&head, int id) {
    if (head == NULL) {                      
        cout << "Task list is empty." << endl;
        return;
    }

    if (head->id == id) {                   
        Task_node *temp = head;             
        head = head->next;                  
        delete temp;                       
        return;
    }

    Task_node *current = head;               
    // Traverse the list to find  task with  given id
    while (current->next != NULL && current->next->id != id) {
        current = current->next;            
    }

    if (current->next == NULL) {             
        cout << "Task with ID " << id << " not found." << endl;
    } else {
        Task_node *temp = current->next;     // Store node to be deleted
        current->next = current->next->next; // Remove  node from the list
        delete temp;                         
    }
}

// Function to view all tasks in the list
void view_tasks(Task_node *head) {
    if (head == NULL) {                       
        cout << "Task list is empty." << endl;
    } else {
        Task_node *current = head;            
        // Traversing of list and printing each task's details
        while (current != NULL) {
            cout << "Task ID: " << current->id << endl;
            cout << "Description: " << current->description << endl;
            cout << "Priority: " << current->priority << endl;
            cout << endl;
            current = current->next;          
        }
    }
}

int main() {
    Task_node *head = NULL;  
    // infinite loop to keep the menu running .loop will exit when user enters 5.
    while (true) {            
        
        cout << "1-Add a new task.\n2-View all tasks.\n3-Remove the highest priority task.\n4-Remove a task by ID\n5-exit" << endl;
        int choice;
        cin >> choice;        

        if (choice == 1) {    
            int id, priority;
            string description;

            cout << "Enter task ID: ";
            cin >> id;        

            cout << "Enter task description: ";
            cin.ignore();     // Clear  input buffer
            getline(cin, description); 

            cout << "Enter task priority: ";
            cin >> priority;  
            // Create a new task node
            Task_node *newTask = createTask(id, priority, description); 
            // Add the new task to the list
            add_task(head, newTask); 
        }
        else if (choice == 2) {  
            view_tasks(head);    
        }
        else if (choice == 3) {  
            remove_on_priority(head); 
        }
        else if (choice == 4) {  
            int id;
            cout << "Enter task ID to remove: ";
            cin >> id;           
            remove_by_id(head, id); 
        }
        else if (choice == 5) {  
            break;//loop will exit
        }
        else {
            cout << "Invalid input" << endl; 
        }
    }

    return 0; 
}
