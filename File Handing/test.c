#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100

struct User {
    int userID;
    char name[50];
    char dob[12];
    int age;
    char address[100];
    char contactNumber[15];
    char sportsCategory[50];
    int isActive;
};

void registerUser(struct User newUser) {
    FILE *file = fopen("users.txt", "ab");
    if (file != NULL) {
        fwrite(&newUser, sizeof(struct User), 1, file);
        fclose(file);
        printf("User registered successfully!\n");
    } else {
        printf("Error: Unable to open file for writing.\n");
    }
}

void updateUser(int userID, char newContactNumber[], char newSportsCategory[]) {
    FILE *file = fopen("users.txt", "rb+");
    if (file != NULL) {
        struct User currentUser;
        while (fread(&currentUser, sizeof(struct User), 1, file) == 1) {
            if (currentUser.userID == userID) {
                if (strlen(newContactNumber) > 0) {
                    strncpy(currentUser.contactNumber, newContactNumber, sizeof(currentUser.contactNumber));
                }
                if (strlen(newSportsCategory) > 0) {
                    strncpy(currentUser.sportsCategory, newSportsCategory, sizeof(currentUser.sportsCategory));
                }

                fseek(file, -sizeof(struct User), SEEK_CUR);
                fwrite(&currentUser, sizeof(struct User), 1, file);
                fclose(file);
                printf("User information updated successfully!\n");
                return;
            }
        }
        fclose(file);
        printf("User not found!\n");
    } else {
        printf("Error: Unable to open file for updating.\n");
    }
}

void viewUserByID(int userID) {
    FILE *file = fopen("users.txt", "rb");
    if (file != NULL) {
        struct User currentUser;
        while (fread(&currentUser, sizeof(struct User), 1, file) == 1) {
            if (currentUser.userID == userID && currentUser.isActive) {
                printf("User ID: %d\n", currentUser.userID);
                printf("Name: %s\n", currentUser.name);
                printf("Date of Birth: %s\n", currentUser.dob);
                printf("Age: %d\n", currentUser.age);
                printf("Address: %s\n", currentUser.address);
                printf("Contact Number: %s\n", currentUser.contactNumber);
                printf("Sports Category: %s\n", currentUser.sportsCategory);
                fclose(file);
                return;
            }
        }
        fclose(file);
        printf("User not found or account deactivated!\n");
    } else {
        printf("Error: Unable to open file for reading.\n");
    }
}

void viewUserByName(const char *userName) {
    FILE *file = fopen("users.txt", "rb");
    if (file != NULL) {
        struct User currentUser;
        while (fread(&currentUser, sizeof(struct User), 1, file) == 1) {
            if (strcmp(currentUser.name, userName) == 0 && currentUser.isActive) {
                printf("User ID: %d\n", currentUser.userID);
                printf("Name: %s\n", currentUser.name);
                printf("Date of Birth: %s\n", currentUser.dob);
                printf("Age: %d\n", currentUser.age);
                printf("Address: %s\n", currentUser.address);
                printf("Contact Number: %s\n", currentUser.contactNumber);
                printf("Sports Category: %s\n", currentUser.sportsCategory);
                fclose(file);
                return;
            }
        }
        fclose(file);
        printf("User not found or account deactivated!\n");
    } else {
        printf("Error: Unable to open file for reading.\n");
    }
}

void removeUser(int userID) {
    FILE *file = fopen("users.txt", "rb+");
    if (file != NULL) {
        struct User currentUser;
        while (fread(&currentUser, sizeof(struct User), 1, file) == 1) {
            if (currentUser.userID == userID) {
                currentUser.isActive = 0;

                fseek(file, -sizeof(struct User), SEEK_CUR);
                fwrite(&currentUser, sizeof(struct User), 1, file);
                fclose(file);
                printf("User account removed or deactivated successfully!\n");
                return;
            }
        }
        fclose(file);
        printf("User not found!\n");
    } else {
        printf("Error: Unable to open file for updating.\n");
    }
}

void viewDirectory() {
    FILE *file = fopen("users.txt", "rb");
    if (file != NULL) {
        struct User currentUser;
        printf("Directory of Registered Users:\n");
        while (fread(&currentUser, sizeof(struct User), 1, file) == 1) {
            if (currentUser.isActive) {
                printf("User ID: %d, Name: %s, Sports Category: %s\n", currentUser.userID, currentUser.name, currentUser.sportsCategory);
            }
        }
        fclose(file);
    } else {
        printf("Error: Unable to open file for reading.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nSports Portal Management System\n");
        printf("1. Register User\n");
        printf("2. Update User Information\n");
        printf("3. View User Details by ID\n");
        printf("4. View User Details by Name\n");
        printf("5. Remove User Account\n");
        printf("6. View Sports Portal Directory\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct User newUser;

                printf("Enter User ID: ");
                scanf("%d", &newUser.userID);

                printf("Enter Name: ");
                scanf(" %[^\n]s", newUser.name);

                printf("Enter Date of Birth (YYYY-MM-DD): ");
                scanf("%s", newUser.dob);

                printf("Enter Age: ");
                scanf("%d", &newUser.age);

                printf("Enter Address: ");
                scanf(" %[^\n]s", newUser.address);

                printf("Enter Contact Number: ");
                scanf("%s", newUser.contactNumber);

                printf("Enter Sports Category: ");
                scanf(" %[^\n]s", newUser.sportsCategory);

                newUser.isActive = 1;

                registerUser(newUser);
                break;
            }
            case 2: {
                int userIDToUpdate, updateChoice;
                char newContactNumber[15], newSportsCategory[50];

                printf("Enter User ID to update information: ");
                scanf("%d", &userIDToUpdate);

                printf("1. Update Contact Number\n");
                printf("2. Update Sports Category\n");
                printf("Enter choice: ");
                scanf("%d", &updateChoice);

                switch (updateChoice) {
                    case 1:
                        printf("Enter new Contact Number: ");
                        scanf("%s", newContactNumber);
                        updateUser(userIDToUpdate, newContactNumber, "");
                        break;
                    case 2:
                        printf("Enter new Sports Category: ");
                        scanf(" %[^\n]s", newSportsCategory);
                        updateUser(userIDToUpdate, "", newSportsCategory);
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            }
            case 3: {
                int userIDToView;
                printf("Enter User ID to view details: ");
                scanf("%d", &userIDToView);
                viewUserByID(userIDToView);
                break;
            }
            case 4: {
                char userName[50];
                printf("Enter User Name to view details: ");
                scanf(" %[^\n]s", userName);
                viewUserByName(userName);
                break;
            }
            case 5: {
                int userIDToRemove;
                printf("Enter User ID to remove or deactivate account: ");
                scanf("%d", &userIDToRemove);
                removeUser(userIDToRemove);
                break;
            }
            case 6:
                viewDirectory();
                break;
            case 7:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}