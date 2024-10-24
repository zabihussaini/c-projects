#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    char name[40];
    int r;
    float m;
};

// Function to calculate the length of a string
int mystrlen(char str[]) {
    int c = 0, i = 0;
    while (str[i] != '\0') {
        c++;
        i++;
    }
    return c;
}

// Function to compare two strings
int mystrcmp(char str1[], char str2[]) {
    int i;
    for (i = 0; str1[i] && str2[i]; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return str1[i] - str2[i];
}

// Function to scan student data manually (one-by-one)
void scanstruct(struct student *p) {
    printf("Student name? : ");
    scanf(" %[^\n]", p->name);
    printf("Roll no: ");
    scanf("%d", &p->r);
    printf("Enter marks: ");
    scanf("%f", &p->m);
}

// Function to input student data in bulk
void scanstruct_bulk(struct student p[], int ne) {
    printf("Enter student details in the format: name roll_no marks (space separated)\n");
    for (int i = 0; i < ne; i++) {
        printf("Student %d: ", i + 1);
        scanf(" %s %d %f", p[i].name, &p[i].r, &p[i].m);
    }
}

// Function to sort students based on roll number in ascending order
void sortstudentrollasc(struct student p[], int ne) {
    struct student st;
    for (int i = 0; i < ne - 1; i++) {
        for (int j = i + 1; j < ne; j++) {
            if ((p[i].r) > (p[j].r)) {
                st = p[i];
                p[i] = p[j];
                p[j] = st;
            }
        }
    }
}

// Function to sort students based on roll number in descending order
void sortstudentrolldsc(struct student p[], int ne) {
    struct student st;
    for (int i = 0; i < ne - 1; i++) {
        for (int j = i + 1; j < ne; j++) {
            if ((p[i].r) < (p[j].r)) {
                st = p[i];
                p[i] = p[j];
                p[j] = st;
            }
        }
    }
}

// Function to sort students based on marks in ascending order
void sortstudentmarksasc(struct student p[], int ne) {
    struct student st;
    for (int i = 0; i < ne - 1; i++) {
        for (int j = i + 1; j < ne; j++) {
            if ((p[i].m) > (p[j].m)) {
                st = p[i];
                p[i] = p[j];
                p[j] = st;
            }
        }
    }
}

// Function to sort students based on marks in descending order
void sortstudentmarksdsc(struct student p[], int ne) {
    struct student st;
    for (int i = 0; i < ne - 1; i++) {
        for (int j = i + 1; j < ne; j++) {
            if ((p[i].m) < (p[j].m)) {
                st = p[i];
                p[i] = p[j];
                p[j] = st;
            }
        }
    }
}

// Function to delete student by name
void deletestudentbyname(struct student s[], int *ne) {
    char nam[40];
    printf("Enter the student name to delete: ");
    scanf(" %[^\n]", nam);
    
    for (int i = 0; i < *ne; i++) {
        int c = mystrcmp(s[i].name, nam);
        if (c == 0) {
            for (int j = i; j < *ne - 1; j++) {
                strcpy(s[j].name, s[j + 1].name);
                s[j].r = s[j + 1].r;
                s[j].m = s[j + 1].m;
            }
            *ne = *ne - 1;
            printf("********************************************\n");
            printf("Student '%s' deleted successfully!\n", nam);
            printf("********************************************\n");
            return;
        }
    }
    printf("Student '%s' not found!\n", nam);
}

// Function to print student details
void printstruct(struct student *p) {
    printf("\n\n");
    printf("Name: %s\nRoll no.: %d\nMarks: %.2f\n", p->name, p->r, p->m);
}

// Function to find highest and lowest marks
void findHighestLowestMarks(struct student s[], int ne) {
    float highest = s[0].m;
    float lowest = s[0].m;
    for (int i = 1; i < ne; i++) {
        if (s[i].m > highest) {
            highest = s[i].m;
        }
        if (s[i].m < lowest) {
            lowest = s[i].m;
        }
    }
    printf("********************************************\n");
    printf("Highest marks: %.2f\n", highest);
    printf("Lowest marks: %.2f\n", lowest);
    printf("********************************************\n");
}

// Function to search for a student by name
void searchStudentByName(struct student s[], int ne) {
    char nam[40];
    printf("Enter the student name to search: ");
    scanf(" %[^\n]", nam);
    
    for (int i = 0; i < ne; i++) {
        if (mystrcmp(s[i].name, nam) == 0) {
            printstruct(&s[i]);
            return;
        }
    }
    printf("Student '%s' not found!\n", nam);
}

int main() {
    int ne, op, input_mode;
    printf("Enter the number of students: ");
    scanf("%d", &ne);

    struct student *s = malloc(ne * sizeof(struct student)); // Dynamic memory allocation

    printf("Choose input mode:\n");
    printf("Enter 1 for Manual Input (one by one)\n");
    printf("Enter 2 for Bulk Input (all at once)\n");
    scanf("%d", &input_mode);

    if (input_mode == 1) {
        // Manual Input Mode
        for (int i = 0; i < ne; i++) {
            scanstruct(&s[i]);
            printf("\n");
        }
    } else if (input_mode == 2) {
        // Bulk Input Mode
        scanstruct_bulk(s, ne);
    } else {
        printf("Invalid input mode. Exiting.\n");
        free(s);
        return 0;
    }

    printf("\n********************************************\n");

    while (1) {
        printf("\n********************************************\n");
        printf("Enter 1 to sort student data (ascending by roll number)\n");
        printf("Enter 2 to sort student data (descending by roll number)\n");
        printf("Enter 3 to delete student by name\n");
        printf("Enter 4 to sort student data by marks (ascending)\n");
        printf("Enter 5 to sort student data by marks (descending)\n");
        printf("Enter 6 to print student list\n");
        printf("Enter 7 to find highest and lowest marks\n");
        printf("Enter 8 to search for a student by name\n");
        printf("Enter 9 to exit\n");
        printf("********************************************\n");
        printf("Enter the number to perform operation: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                sortstudentrollasc(s, ne);
                printf("********************************************\n");
                printf("Students sorted by roll number (ascending).\n");
                break;
            case 2:
                sortstudentrolldsc(s, ne);
                printf("********************************************\n");
                printf("Students sorted by roll number (descending).\n");
                break;    
            case 3:
                deletestudentbyname(s, &ne);
                break;
            case 4:
                sortstudentmarksasc(s, ne);
                printf("********************************************\n");
                printf("Students sorted by marks (ascending).\n");
                break;    
            case 5:
                sortstudentmarksdsc(s, ne);
                printf("********************************************\n");
                printf("Students sorted by marks (descending).\n");
                break;  
            case 6:
                printf("Student List:\n");
                for (int i = 0; i < ne; i++) {
                    printstruct(&s[i]);
                }
                break;    
            case 7:
                findHighestLowestMarks(s, ne);
                break;    
            case 8:
                searchStudentByName(s, ne);
                break;
            case 9:
                free(s); // Free dynamically allocated memory
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
