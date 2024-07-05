#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 10

typedef struct {
    char name[50];
    int scores[MAX_SUBJECTS];
    int numSubjects;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void inputStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    Student *student = &students[studentCount];
    printf("Enter student name: ");
    scanf("%s", student->name);
    printf("Enter number of subjects: ");
    scanf("%d", &student->numSubjects);

    for (int i = 0; i < student->numSubjects; i++) {
        printf("Enter score for subject %d: ", i + 1);
        scanf("%d", &student->scores[i]);
    }

    studentCount++;
}

float calculateAverage(int scores[], int numSubjects) {
    int sum = 0;
    for (int i = 0; i < numSubjects; i++) {
        sum += scores[i];
    }
    return (float)sum / numSubjects;
}

void findHighestLowestScores(int scores[], int numSubjects, int *highest, int *lowest) {
    *highest = scores[0];
    *lowest = scores[0];

    for (int i = 1; i < numSubjects; i++) {
        if (scores[i] > *highest) {
            *highest = scores[i];
        }
        if (scores[i] < *lowest) {
            *lowest = scores[i];
        }
    }
}

void displaySummary() {
    float totalAverage = 0;
    int highestScore = 0;
    int lowestScore = 100;

    for (int i = 0; i < studentCount; i++) {
        Student *student = &students[i];
        float average = calculateAverage(student->scores, student->numSubjects);
        int highest, lowest;
        findHighestLowestScores(student->scores, student->numSubjects, &highest, &lowest);

        totalAverage += average;
        if (highest > highestScore) {
            highestScore = highest;
        }
        if (lowest < lowestScore) {
            lowestScore = lowest;
        }

        printf("\nStudent: %s\n", student->name);
        printf("Average Score: %.2f\n", average);
        printf("Highest Score: %d\n", highest);
        printf("Lowest Score: %d\n", lowest);
    }

    if (studentCount > 0) {
        totalAverage /= studentCount;
    }

    printf("\nOverall Performance:\n");
    printf("Average Score of All Students: %.2f\n", totalAverage);
    printf("Highest Score among All Students: %d\n", highestScore);
    printf("Lowest Score among All Students: %d\n", lowestScore);
}

int main() {
    int choice;
    while (1) {
        printf("\nStudent Grade Management\n");
        printf("1. Input Student Information\n");
        printf("2. Display Summary\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputStudent();
                break;
            case 2:
                displaySummary();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
