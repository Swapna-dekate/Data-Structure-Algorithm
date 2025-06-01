#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {
    int empid;
    char name[50];
};

int main() {
    struct Employee emp[MAX];
    int n, choice, id, found = 0;
    char searchName[50];

    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Input employee details
    for (int i = 0; i < n; i++) {
        printf("Enter Employee %d ID: ", i + 1);
        scanf("%d", &emp[i].empid);
        printf("Enter Employee %d Name: ", i + 1);
        scanf("%s", emp[i].name);
    }

    printf("\nSearch by:\n1. ID\n2. Name\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Employee ID to search: ");
        scanf("%d", &id);
        for (int i = 0; i < n; i++) {
            if (emp[i].empid == id) {
                printf("Employee Found: ID=%d, Name=%s\n", emp[i].empid, emp[i].name);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        printf("Enter Employee Name to search: ");
        scanf("%s", searchName);
        for (int i = 0; i < n; i++) {
            if (strcmp(emp[i].name, searchName) == 0) {
                printf("Employee Found: ID=%d, Name=%s\n", emp[i].empid, emp[i].name);
                found = 1;
                break;
            }
        }
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    if (!found) {
        printf("Employee not found.\n");
    }

    return 0;
}
