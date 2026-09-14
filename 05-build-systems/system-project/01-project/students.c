#include "students.h"
#include <stdio.h>

const char *typeofeducation(int number)
{
    switch (number)
    {
    case UGR:
        return "undergraduate";
    case PGR:
        return "postgraduate";
    case PHD:
        return "Doctorate";
    case OTHER:
        return "Other";

    default:
        printf("you have entered an invalid number");
        return "error";
    }
}
void addstudent(student *student, int *count)
{

    // check if there are already 10 students: if there are espond error
    if (*count >= 10)
    {
        printf("full database");
        return;
    }

    // if not get to the index of the count by pointer arithemetic
    student = student + *count;
    // get user input for the info
    // set the id
    student->id = 1000 + (*count);
    // get name
    printf("\nENTER NAME: ");
    scanf(" %29s", student->name);
    // get date_of_birth
    printf("ENTER YEAR OF BIRTH: ");
    scanf(" %d", &student->date_of_birth.year);
    printf("ENTER MONTH OF BIRTH: ");
    scanf(" %d", &student->date_of_birth.month);
    printf("ENTER DATE OF BIRTH: ");
    scanf(" %d", &student->date_of_birth.date);
    // get the type of education
    printf("ARE YOU UGR(0),PGR(1),PHD(2), OR OTHER(3)? ");
    int choice;
    scanf("%d", &choice);
    if (choice < UGR || choice > OTHER)
    {
        printf("Invalid education type\n");
        return;
    }
    student->type_of_education = (TypeofED)choice;
    // increment count
    *count += 1;
    // say you have registered.
    printf("\nsuccessfully registered. %s with ID of %d: ", student->name, student->id);
    return;
}

// search function
void searchfunction(const student *student, int studentId, int count)
{
    // look through the indexes and say if the student exist or not
    for (int i = 0; i < count; i++)
    {
        if (student->id == studentId)
        {
            printf("\nStudent is registered with name %s", student->name);
            return;
        }
        student++;
    }
    printf("\nThe student is not registered");
    return;
}
// display student function
void displayfunction(const student *student, int studentId, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (student->id == studentId)
        {
            printf("%d\n%s\n%d %d %d\n %s\n", student->id, student->name, student->date_of_birth.year, student->date_of_birth.month, student->date_of_birth.date, typeofeducation(student->type_of_education));
            return;
        }
        student++;
    }
    printf("The student is not registered");
    return;
}

// display all students function
void displayall_students(const student *student, int count)
{
    int local_count = 0;
    while (local_count < count)
    {
        printf("\n%d\n%s\n%d %d %d\n %s\n", student->id, student->name, student->date_of_birth.year, student->date_of_birth.month, student->date_of_birth.date, typeofeducation(student->type_of_education));
        student++;
        local_count++;
    }
    return;
}