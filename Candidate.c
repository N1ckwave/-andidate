#include <stdio.h>
#include <string.h>
#include <time.h>

#define NUM_CANDIDATES 6
#define MAX_LENGTH 50

struct Candidate {
    char name[MAX_LENGTH];
    char dob[11]; // YYYY/MM/DD
    char gender;
    char email[MAX_LENGTH];
    char nationality[MAX_LENGTH];
    float bmi;
    char primary[MAX_LENGTH];
    char secondary[MAX_LENGTH];
    int korean;
    char mbti[5];
    char intro[200];
};

int get_age(const char* dob) {
    int year, month, day;
    sscanf(dob, "%d/%d/%d", &year, &month, &day);
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    int age = t->tm_year + 1900 - year;
    if (t->tm_mon + 1 < month || (t->tm_mon + 1 == month && t->tm_mday < day)) {
        age--;
    }
    return age;
}

int main() {
    struct Candidate candidates[NUM_CANDIDATES];
    char group[MAX_LENGTH];
    int i = 0;
    
    printf("Group name: ");
    fgets(group, MAX_LENGTH, stdin);
    group[strcspn(group, "\n")] = '\0';
    
    // Input data
    printf("\n=== [%s] Candidate Entry ===\n", group);
    while (i < NUM_CANDIDATES) {
        printf("\nCandidate %d:\n", i+1);
        
        printf("Name: ");
        fgets(candidates[i].name, MAX_LENGTH, stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = '\0';
        
        printf("DOB (YYYY/MM/DD): ");
        fgets(candidates[i].dob, 11, stdin);
        getchar();
        
        printf("Gender (M/F): ");
        scanf(" %c", &candidates[i].gender);
        getchar();
        
        printf("Email: ");
        fgets(candidates[i].email, MAX_LENGTH, stdin);
        candidates[i].email[strcspn(candidates[i].email, "\n")] = '\0';
        
        printf("Nationality: ");
        fgets(candidates[i].nationality, MAX_LENGTH, stdin);
        candidates[i].nationality[strcspn(candidates[i].nationality, "\n")] = '\0';
        
        printf("BMI: ");
        scanf("%f", &candidates[i].bmi);
        getchar();
        
        printf("Primary skill: ");
        fgets(candidates[i].primary, MAX_LENGTH, stdin);
        candidates[i].primary[strcspn(candidates[i].primary, "\n")] = '\0';
        
        printf("Secondary skill: ");
        fgets(candidates[i].secondary, MAX_LENGTH, stdin);
        candidates[i].secondary[strcspn(candidates[i].secondary, "\n")] = '\0';
        
        printf("Korean level (0-4): ");
        scanf("%d", &candidates[i].korean);
        getchar();
        
        printf("MBTI: ");
        fgets(candidates[i].mbti, 5, stdin);
        getchar();
        
        printf("Introduction: ");
        fgets(candidates[i].intro, 200, stdin);
        candidates[i].intro[strcspn(candidates[i].intro, "\n")] = '\0';
        
        i++;
    }
    
    // Display data
    printf("\n=== [%s] Candidate Review ===\n", group);
    printf("==================================================================\n");
    printf("%-15s | DOB      | G | Email           | Skill\n", "Name (Age)");
    printf("==================================================================\n");
    
    for (i = 0; i < NUM_CANDIDATES; i++) {
        char dob[9];
        strncpy(dob, candidates[i].dob, 4);
        strncpy(dob+4, candidates[i].dob+5, 2);
        strncpy(dob+6, candidates[i].dob+8, 2);
        dob[8] = '\0';
        
        printf("%-15s | %s | %c | %-15s | %s/%s\n", 
               candidates[i].name, dob, candidates[i].gender, 
               candidates[i].email, candidates[i].primary, candidates[i].secondary);
        
        printf("------------------------------------------------------------------\n");
        printf("%s\n", candidates[i].intro);
        printf("------------------------------------------------------------------\n");
    }
    
    return 0;
}
