#include <stdio.h>
#define STUDENTMAX 100

typedef struct
{
    int ID;
    char Name[20];
    char department[20];
    int age;
} student;

void read_file(FILE *fp, student *student, int *count)
{
    *count = 0;
    while (*count < STUDENTMAX && fscanf(fp, "%d %s %s %d", &student[*count].ID, student[*count].Name, student[*count].department, &student[*count].age) == 4)
    {
        printf("%d %s %s %d \n", student[*count].ID, student[*count].Name, student[*count].department, student[*count].age);
        (*count)++;
    }
}
int main()
{
    FILE *fp;
    fp = fopen("output.txt", "r");
    if (fp == NULL)
    {
        printf("there was an error opening file");
        return 1;
    }

    student s[STUDENTMAX];
    int count = 0;
    read_file(fp, s, &count);
    fclose(fp);
    return 0;
}