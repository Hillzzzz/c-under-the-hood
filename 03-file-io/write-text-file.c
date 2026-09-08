#include <stdio.h>
// define a struct of a student
// make that struct into a string
// make it print to the out put file
// use fprintf

// struct
typedef struct
{
    int ID;
    char Name[20];
    char department[20];
    int age;
} student;

// add a student to out put
void add_student(student *student, FILE *fp)
{
    fprintf(fp, "%d %s %s %d \n", student->ID, student->Name, student->department, student->age);
    // close outside the function
}

int main()
{
    FILE *fp;
    fp = fopen("output.txt", "a");
    if (fp == NULL)
    {
        printf("could not open file");
        return 1;
    }
    student student1 = {1006, "rihanna", "electrical", 21};
    student student2 = {1009, "beyonce", "civil", 22};
    add_student(&student1, fp);
    add_student(&student2, fp);
    fclose(fp);
}
