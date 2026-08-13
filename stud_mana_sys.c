#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    char department[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &students[count].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Department: ");
    scanf(" %[^\n]", students[count].department);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;
    printf("Student added successfully!\n");
}

void displayStudents() {
    int i;

    if (count == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n%-10s %-20s %-20s %-10s\n",
           "Roll No", "Name", "Department", "Marks");

    printf("------------------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%-10d %-20s %-20s %-10.2f\n",
               students[i].roll,
               students[i].name,
               students[i].department,
               students[i].marks);
    }
}

void searchStudent() {
    int roll, i;

    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", students[i].roll);
            printf("Name        : %s\n", students[i].name);
            printf("Department  : %s\n", students[i].department);
            printf("Marks       : %.2f\n", students[i].marks);
            return;
        }
    }

    printf("Student not found!\n");
}

void updateStudent() {
    int roll, i;

    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].roll == roll) {

            printf("Enter New Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Department: ");
            scanf(" %[^\n]", students[i].department);

            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);

            printf("Student record updated successfully!\n");
            return;
        }
    }

    printf("Student not found!\n");
}

void deleteStudent() {
    int roll, i, j;

    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;

            printf("Student record deleted successfully!\n");
            return;
        }
    }

    printf("Student not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student Record\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}