#include <stdio.h>
struct Student {
    char name[50];
    int score;
};
void bubbleSort(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].score < students[j + 1].score) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student students[n];
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Score: ");
        scanf("%d", &students[i].score);
    }
    bubbleSort(students, n);

    printf("\nTop 10 Toppers:\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("Rank %d: %s, Score: %d\n", i + 1, students[i].name, students[i].score);
    }

    return 0;
}
