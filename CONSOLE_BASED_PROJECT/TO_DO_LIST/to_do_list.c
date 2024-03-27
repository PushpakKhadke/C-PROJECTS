#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 50

// Structure to represent a task
struct Task {
    char description[MAX_LENGTH];
    int completed;
};

// Function prototypes
void printMenu();
void addTask(struct Task tasks[], int *taskCount);
void markTaskComplete(struct Task tasks[], int taskCount);
void printTasks(struct Task tasks[], int taskCount);

int main() {
    struct Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                markTaskComplete(tasks, taskCount);
                break;
            case 3:
                printTasks(tasks, taskCount);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while(choice != 4);

    return 0;
}

// Function to print the menu options
void printMenu() {
    printf("\nTodo List Menu\n");
    printf("1. Add Task\n");
    printf("2. Mark Task Complete\n");
    printf("3. Print Tasks\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a task
void addTask(struct Task tasks[], int *taskCount) {
    if (*taskCount == MAX_TASKS) {
        printf("Todo list is full!\n");
        return;
    }

    printf("Enter task description: ");
    scanf(" %[^\n]", tasks[*taskCount].description);
    tasks[*taskCount].completed = 0; // Set task as not completed
    (*taskCount)++;
}

// Function to mark a task as complete
void markTaskComplete(struct Task tasks[], int taskCount) {
    int taskIndex;

    if (taskCount == 0) {
        printf("No tasks to mark as complete.\n");
        return;
    }

    printf("Enter the index of the task to mark as complete (0-%d): ", taskCount - 1);
    scanf("%d", &taskIndex);

    if (taskIndex < 0 || taskIndex >= taskCount) {
        printf("Invalid task index!\n");
        return;
    }

    tasks[taskIndex].completed = 1;
    printf("Task marked as complete.\n");
}

// Function to print all tasks
void printTasks(struct Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks to display.\n");
        return;
    }

    printf("Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%s] %s\n", i, tasks[i].completed ? "X" : " ", tasks[i].description);
    }
}
