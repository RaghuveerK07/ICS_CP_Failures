#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define FILENAME_SIZE 1024
#define MAX_LENGTH 2048

void Input_attendance() {
    char Date[MAX_LENGTH];
    char Name[MAX_LENGTH];
    int roll;
    char your_filename[MAX_LENGTH];

    printf("Enter filename to store the Attendance: ");
    scanf("%s",your_filename);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", Date);
    printf("Enter Student Roll no.: ");
    scanf("%d", &roll);
    printf("Enter student name: ");
    scanf("%s", Name);

    FILE *ptr;
    ptr = fopen(your_filename, "a");

    if (ptr == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    fprintf(ptr, "%s,%d,%s\n", Date, roll, Name);

    fclose(ptr);
    printf("Attendance for student %s has been successfully recorded.\n", Name);
    printf("\n");
}


void check_attendance() {
    char filename[FILENAME_SIZE];
    char buffer[MAX_LENGTH];
    char target_roll[MAX_LENGTH];
    char target_date[MAX_LENGTH];

    FILE *file;

    printf("Enter File name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    printf("Check Attendance Record: Write roll no. in format (eg. 1020): ");
    scanf("%s", target_roll);

    printf("Check Attendance Record: Write date in format (dd/mm/yyyy): ");
    scanf("%s", target_date);

    bool studentFound = false;

    while (fgets(buffer, MAX_LENGTH, file) != NULL) {
        if (strstr(buffer, target_roll) && strstr(buffer, target_date) != NULL) {
            printf("STUDENT PRESENT\n");
            printf("\n");
            studentFound = true;
            break;
        }
    }

    if (!studentFound) {
        printf("STUDENT ABSENT\n");
        printf("\n");
    }

    fclose(file);
}

int main() {
    int choice;

    do {
        printf("\n");
        printf("****************  MAIN MENU  ****************\n");
        printf("\n");
        printf("Student Attendance Management System\n");
        printf("\n");
        printf("1) Input Attendance\n");
        printf("2) Check Attendance\n");
        printf("3) Exit program\n");
        printf("\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Input_attendance();
                break;
            case 2:
                check_attendance();
                break;
            case 3:
                printf("Exiting Program! BYE BYE :) 3\n");
                break;
            default:
                printf("Oops, entered a wrong choice, try again!\n");
        }
    } while (choice != 3);

    return 0;
}
