#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    float gpa;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void add_student() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }
    printf("Enter student's name: ");
    scanf("%49s", students[studentCount].name);
    printf("Enter student's ID: ");
    scanf("%d", &students[studentCount].id);
    printf("Enter student's GPA: ");
    scanf("%f", &students[studentCount].gpa);
    studentCount++;
    printf("Student added successfully.\n");
}

void load_students(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    Student temp;
    while (fscanf(file, "%49s %d %f", temp.name, &temp.id, &temp.gpa) == 3) {
        students[studentCount++] = temp;
        if (studentCount >= MAX_STUDENTS) break;
    }
    fclose(file);
}

void list_students() {
    printf("Name\tID\tGPA\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s\t%d\t%.2f\n", students[i].name, students[i].id, students[i].gpa);
    }
}

void save_students(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%s %d %.2f\n", students[i].name, students[i].id, students[i].gpa);
    }
    fclose(file);
    printf("Student records saved.\n");
}

void search_student() {
    int id;
    printf("Enter student's ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Student found: %s, ID: %d, GPA: %.2f\n", students[i].name, students[i].id, students[i].gpa);
            return;
        }
    }
    printf("No student found with ID %d.\n", id);
}

void delete_student() {
    int id;
    printf("Enter student's ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student deleted.\n");
            return;
        }
    }
    printf("No student found with ID %d.\n", id);
}

int main() {
    int choice;
    load_students("students.txt"); // Load existing records at the start

    while (1) {
        printf("0: Save and exit\n1: Add student\n2: Search for student\n3: Delete student\n4: List all students\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                save_students("students.txt");
                exit(0);
            case 1:
                add_student();
                break;
            case 2:
                search_student();
                break;
            case 3:
                delete_student();
                break;  
            case 4:
                list_students();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
