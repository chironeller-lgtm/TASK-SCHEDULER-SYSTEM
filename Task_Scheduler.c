#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =========================
   TASK STRUCTURE 
   ========================= */
struct Task {
    int id;
    char name[100];
    int priority;
    int completed;
    struct Task* next;
};

/* =========================
   STACK 
   ========================= */
struct Stack {
    struct Task task;
    struct Stack* next;
};

/* =========================
   QUEUE 
   ========================= */
struct Queue {
    struct Task* front;
    struct Task* rear;
};

/* =========================
   GLOBAL VARIABLES
   ========================= */
struct Task* head = NULL;
struct Stack* top = NULL;
struct Queue q = {NULL, NULL};
int idCounter = 1;

/* =========================
   STACK FUNCTIONS
   ========================= */
void push(struct Task t) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->task = t;
    newNode->next = top;
    top = newNode;
}

int isStackEmpty() {
    return top == NULL;
}

struct Task pop() {
    struct Stack* temp = top;
    struct Task t = temp->task;
    top = top->next;
    free(temp);
    return t;
}

/* =========================
   QUEUE FUNCTIONS
   ========================= */
void enqueue(struct Task* t) {
    struct Task* newNode = (struct Task*)malloc(sizeof(struct Task));
    *newNode = *t;
    newNode->next = NULL;

    if (q.rear == NULL) {
        q.front = q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

void displayQueue() {
    struct Task* temp = q.front;

    printf("\n--- Scheduled Tasks (Queue) ---\n");

    while (temp != NULL) {
        printf("ID: %d | %s | Priority: %d\n",
               temp->id, temp->name, temp->priority);
        temp = temp->next;
    }
}

/* =========================
   CORE FUNCTIONS
   ========================= */

void addTask() {
    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));

    newTask->id = idCounter++;
    newTask->completed = 0;
    newTask->next = NULL;

    printf("Enter task name: ");
    scanf(" %[^\n]", newTask->name);

    printf("Enter priority (1-High, 2-Medium, 3-Low): ");
    scanf("%d", &newTask->priority);

    
    newTask->next = head;
    head = newTask;

    
    enqueue(newTask);

    printf("Task added successfully!\n");
}

void viewTasks() {
    struct Task* temp = head;

    if (!temp) {
        printf("No tasks available.\n");
        return;
    }

    printf("\n--- TASK LIST ---\n");

    while (temp != NULL) {
        printf("ID: %d | %s | Priority: %d | %s\n",
               temp->id,
               temp->name,
               temp->priority,
               temp->completed ? "Done" : "Pending");
        temp = temp->next;
    }
}

void deleteTask() {
    int id;
    printf("Enter task ID to delete: ");
    scanf("%d", &id);

    struct Task *temp = head, *prev = NULL;

    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Task not found.\n");
        return;
    }

    
    push(*temp);

    if (!prev)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Task deleted.\n");
}

void undoDelete() {
    if (isStackEmpty()) {
        printf("Nothing to undo.\n");
        return;
    }

    struct Task t = pop();

    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
    *newTask = t;

    newTask->next = head;
    head = newTask;

    printf("Undo successful!\n");
}

void markComplete() {
    int id;
    printf("Enter task ID: ");
    scanf("%d", &id);

    struct Task* temp = head;

    while (temp) {
        if (temp->id == id) {
            temp->completed = 1;
            printf("Task marked as completed.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Task not found.\n");
}

/* =========================
   SORT 
   ========================= */
void sortTasks() {
    if (!head) return;

    struct Task *i, *j;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->priority > j->priority) {

            
                struct Task temp = *i;
                *i = *j;
                *j = temp;

                
                struct Task* tmpNext = i->next;
                i->next = j->next;
                j->next = tmpNext;
            }
        }
    }

    printf("Tasks sorted by priority.\n");
}

/* =========================
   SEARCH 
   ========================= */
void searchTask() {
    char name[100];
    printf("Enter task name to search: ");
    scanf(" %[^\n]", name);

    struct Task* temp = head;

    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found: ID %d | Priority %d\n",
                   temp->id, temp->priority);
            return;
        }
        temp = temp->next;
    }

    printf("Task not found.\n");
}

/* =========================
   MAIN MENU
   ========================= */
int main() {
    int choice;

    do {
        printf("\n===== TASK MANAGER =====\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Mark Complete\n");
        printf("5. Sort Tasks\n");
        printf("6. Search Task\n");
        printf("7. Undo Delete\n");
        printf("8. View Queue\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: deleteTask(); break;
            case 4: markComplete(); break;
            case 5: sortTasks(); break;
            case 6: searchTask(); break;
            case 7: undoDelete(); break;
            case 8: displayQueue(); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 9);

    return 0;
}

