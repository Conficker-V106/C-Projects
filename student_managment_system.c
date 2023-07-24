#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct Student {
    int rollNumber;
    char name[MAX_NAME_LENGTH];
    int age;
};

void addStudent(struct Student** students, int* numStudents) {
    struct Student newStudent;

    printf("Enter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    printf("Enter Name: ");
    scanf("%s", newStudent.name);
    printf("Enter Age: ");
    scanf("%d", &newStudent.age);

    (*numStudents)++;
    *students = (struct Student*)realloc(*students, (*numStudents) * sizeof(struct Student));
    (*students)[(*numStudents) - 1] = newStudent;

    printf("Student added successfully.\n");
}

void displayStudents(struct Student* students, int numStudents) {
    printf("\nStudent List:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Roll Number: %d, Name: %s, Age: %d\n", students[i].rollNumber, students[i].name, students[i].age);
    }
}

int searchStudent(struct Student* students, int numStudents, int rollNumber) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            return i;
        }
    }
    return -1;
}

void updateStudent(struct Student* students, int numStudents) {
    int rollNumber;
    printf("Enter the Roll Number of the student to update: ");
    scanf("%d", &rollNumber);

    int index = searchStudent(students, numStudents, rollNumber);
    if (index == -1) {
        printf("Student with Roll Number %d not found.\n", rollNumber);
        return;
    }

    printf("Enter updated Name: ");
    scanf("%s", students[index].name);
    printf("Enter updated Age: ");
    scanf("%d", &students[index].age);

    printf("Student information updated successfully.\n");
}

void deleteStudent(struct Student** students, int* numStudents) {
    int rollNumber;
    printf("Enter the Roll Number of the student to delete: ");
    scanf("%d", &rollNumber);

    int index = searchStudent(*students, *numStudents, rollNumber);
    if (index == -1) {
        printf("Student with Roll Number %d not found.\n", rollNumber);
        return;
    }

    for (int i = index; i < (*numStudents) - 1; i++) {
        (*students)[i] = (*students)[i + 1];
    }

    (*numStudents)--;
    *students = (struct Student*)realloc(*students, (*numStudents) * sizeof(struct Student));

    printf("Student with Roll Number %d deleted successfully.\n", rollNumber);
}

void saveStudentsToFile(struct Student* students, int numStudents) {
    FILE* file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%d %s %d\n", students[i].rollNumber, students[i].name, students[i].age);
    }

    fclose(file);
}

void loadStudentsFromFile(struct Student** students, int* numStudents) {
    FILE* file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("No data found.\n");
        return;
    }

    while (!feof(file)) {
        struct Student newStudent;
        if (fscanf(file, "%d %s %d\n", &newStudent.rollNumber, newStudent.name, &newStudent.age) == 3) {
            (*numStudents)++;
            *students = (struct Student*)realloc(*students, (*numStudents) * sizeof(struct Student));
            (*students)[(*numStudents) - 1] = newStudent;
        }
    }

    fclose(file);
}

void freeMemory(struct Student* students, int numStudents) {
    free(students);
}

int main() {
    struct Student* students = NULL;
    int numStudents = 0;
    int choice;

    loadStudentsFromFile(&students, &numStudents);

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Save Data\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&students, &numStudents);
                break;
            case 2:
                displayStudents(students, numStudents);
                break;
            case 3: {
                int rollNumber;
                printf("Enter the Roll Number of the student to search: ");
                scanf("%d", &rollNumber);
                int index = searchStudent(students, numStudents, rollNumber);
                if (index != -1) {
                    printf("Student found:\n");
                    printf("Roll Number: %d, Name: %s, Age: %d\n", students[index].rollNumber, students[index].name, students[index].age);
                } else {
                    printf("Student with Roll Number %d not found.\n", rollNumber);
                }
                break;
            }
            case 4:
                updateStudent(students, numStudents);
                break;
            case 5:
                deleteStudent(&students, &numStudents);
                break;
            case 6:
                saveStudentsToFile(students, numStudents);
                break;
            case 7:
                saveStudentsToFile(students, numStudents);
                freeMemory(students, numStudents);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
