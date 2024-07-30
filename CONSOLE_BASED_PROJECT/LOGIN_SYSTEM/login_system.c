#include <stdio.h>1
#include <string.h>

#define MAX_USERS 10

// Structure for storing user information
struct User {
    char username[50];
    char password[50];
};

// Array to store registered users
struct User users[MAX_USERS];
int num_users = 0;

// Function prototypes
void registerUser();
void loginUser();

int main() {
    int choice;

    while (1) {
        printf("\n1. Register\n2. Login\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void registerUser() {
    if (num_users >= MAX_USERS) {
        printf("Maximum users reached.\n");
        return;
    }

    struct User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);

    users[num_users++] = newUser;
    printf("Registration successful.\n");
}

void loginUser() {
    char username[50];
    char password[50];
    int i;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (i = 0; i < num_users; ++i) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");
            return;
        }
    }

    printf("Invalid username or password.\n");
}
