#include <stdio.h>
#include <string.h> // For string functions
#include <time.h>   // For date/time functions

// Structure to hold candidate data
typedef struct {
    char name[30];
    char dob[11]; // YYYY/MM/DD
    char gender;
    char skills[30];
    int age; // Added age
} Candidate;

int calculateAge(const char *dob) {
    int year, month, day;
    sscanf(dob, "%d/%d/%d", &year, &month, &day);

    time_t now = time(0);
    struct tm *currentTime = localtime(&now);

    int currentYear = currentTime->tm_year + 1900;
    int currentMonth = currentTime->tm_mon + 1;
    int currentDay = currentTime->tm_mday;

    int age = currentYear - year;

    if (currentMonth < month || (currentMonth == month && currentDay < day)) {
        age--; // Subtract 1 if birthday hasn't occurred yet this year
    }

    return age;
}

int main() {
    // Store basic info for candidates
    Candidate candidates[6]; // Using the struct

    printf("=== K-Pop Audition Tracker ===\n\n");

    // Input data
    for (int i = 0; i < 6; i++) {
        printf("\nCandidate %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", candidates[i].name);

        printf("Birthdate (YYYY/MM/DD): ");
        scanf("%s", candidates[i].dob);

        printf("Gender (M/F): ");
        scanf(" %c", &candidates[i].gender);

        printf("Main Skill: ");
        scanf("%s", candidates[i].skills);

        candidates[i].age = calculateAge(candidates[i].dob); // Calculate age
    }

    // Display results
    printf("\n=== Audition Candidates ===\n");
    printf("No.  Name          Birthdate  Gender  Age  Skill\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < 6; i++) {
        printf("%-4d %-12s %-10s %-7c %-4d %s\n",
               i + 1, candidates[i].name, candidates[i].dob, candidates[i].gender, candidates[i].age, candidates[i].skills);
    }

    return 0;
}