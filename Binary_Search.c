#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float percentage;
};

int main() {
    int size, searchRollNo, searchResult;
    printf("Enter the size of the student database: ");
    scanf("%d", &size);

    struct Student studentDatabase[size];

    for (int i = 0; i < size; ++i) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &studentDatabase[i].rollNo);
        printf("Name: ");
        scanf("%s", studentDatabase[i].name);
        printf("Percentage: ");
        scanf("%f", &studentDatabase[i].percentage);
    }

    printf("\n%-10s%-20s%-15s\n", "Roll No", "Name", "Percentage");
    for (int i = 0; i < size;i++) {
        printf("%-10d%-20s%-15.2f\n", studentDatabase[i].rollNo, studentDatabase[i].name, studentDatabase[i].percentage);
    }

    printf("\nEnter the roll number to search: ");
    scanf("%d", &searchRollNo);

    int low = 0, high = size - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (studentDatabase[mid].rollNo == searchRollNo) {
            searchResult = mid;
            break;
        } else if (studentDatabase[mid].rollNo < searchRollNo) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (low <= high) {
        printf("Student found!\n");
        printf("Roll No: %d, Name: %s, Percentage: %.2f\n",
               studentDatabase[searchResult].rollNo,
               studentDatabase[searchResult].name,
               studentDatabase[searchResult].percentage);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}
