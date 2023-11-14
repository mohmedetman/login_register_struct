#include <stdio.h>
#include <string.h>

#define MAX_USERS 10

// Enumeration for the flag values
enum FlagValue {
    True = 1,
    Error = 0
};

// Structure to represent a user
struct User {
    char username[20];
    char password[20];
    enum FlagValue flag;
};

// Array to store user data
struct User users[MAX_USERS];
int userCount = 0;

// Function prototypes
void registerUser();
void loginUser();

int main() {
    int choice;

    do {
        printf("1. Register\n2. Login\n3. Exit\n");
        printf("Enter your choice: ");
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
                break;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }

    } while (choice != 3);

    return 0;
}

void registerUser() {
    if (userCount < MAX_USERS) {
        printf("Enter a username: ");
        scanf("%s", users[userCount].username);

        printf("Enter a password: ");
        scanf("%s", users[userCount].password);

        printf("Set the flag (True/1 or Error/0): ");
        scanf("%d", &users[userCount].flag);

        printf("Registration successful!\n");
        userCount++;
    } else {
        printf("Maximum user limit reached.\n");
    }
}

void loginUser() {
    char username[20];
    char password[20];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    int i;
    for (i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            if (users[i].flag == True) {
                printf("Login successful! Welcome, %s!\n", username);
            } else {
                printf("Login failed. User is not active.\n");
            }
            return;
        }
    }

    printf("Invalid username or password. Please try again.\n");
}