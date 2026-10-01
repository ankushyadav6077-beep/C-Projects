#include <stdio.h>

// Student Result Analyzer
// Calculate the Total marks
int calculateTotal(int marks[], int size)
{   
    int total = 0;
    for(int i = 0; i < size; i++)
    {
        total += marks[i];
    }
    return total;
}

// Percentage of total marks
float calculatePercentage(int total, int maximumMarks)
{
    float percentage;
    percentage = (float)total / maximumMarks * 100;

    return percentage;
}
// Highest marks
int findHighest(int marks[], int size)
{
    int highest = marks[0];
    
    for(int i = 0; i < size; i++)
    {
        if(marks[i] > highest)
        {
            highest = marks[i];
        }
    }
    return highest;
}

// Lowest Marks
int findLowest(int marks[], int size)
{
    int lowest = marks[0];

    for(int i = 0; i < size; i++)
    {
        if(marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }
    return lowest;
}

// Count of pass and fail
void countPassFail(int marks[], int size, int *passed, int *failed)
{   
    
    for(int i = 0; i < size; i++)
    {
        if(marks[i] >= 40)
        {
            (*passed)++;
        }
        else{
            (*failed)++;
        }
    }
}
// Calculate Grade using percentage
char calculateGrade(float percentage)
{
    if(percentage >= 90)
    {
        return 'A';
    }
    else if(percentage >= 75)
    {
        return 'B';
    }
    else if(percentage >= 60)
    {
        return 'C';
    }
    else if(percentage >= 40)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

int main()
{
    char name[100];
    int marks[5];
    int total = 0;
    float percentage;

// student name
    printf("Enter Student name: ");
    fgets(name, sizeof(name), stdin);
// student marks
    printf("\nEnter 5 subject marks: ");
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &marks[i]);
    }

    printf("\n========================================\n");
    printf("           STUDENT RESULT\n");
    printf("========================================\n\n");

    printf("Student Name : %s\n", name);

    printf("Subject Marks\n");
    printf("----------------------------------------\n");
    for(int i = 0; i < 5; i++)
    {
        printf("Subject %d    : %d\n", i + 1, marks[i]);
    }
    printf("\n----------------------------------------\n");
// total marks
    total = calculateTotal(marks, 5);
    printf("Total        : %d / 500\n", total);
// percentage of all marks
    percentage = calculatePercentage(total, 500);
    printf("Percentage   : %.2f%%\n", percentage);
// highest marks
    printf("Highest      : %d\n", findHighest(marks, 5));
// lowest marks
    printf("Lowest       : %d\n", findLowest(marks, 5));
// Check if passed of failed
    int passed = 0;
    int failed = 0;
    countPassFail(marks, 5, &passed, &failed);
    printf("\nPassed       : %d\n", passed);
    printf("Failed       : %d\n", failed);

    printf("Grade        : %c\n", calculateGrade(percentage));
    printf("\n========================================\n");
    return 0;
}
