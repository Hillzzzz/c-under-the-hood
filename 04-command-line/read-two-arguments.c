// copying the student functions
#include <stdio.h>
#include <string.h>
#define MAXSTUDENTS 100

// enums could represent the type of education
typedef enum
{
    UGR,
    PGR,
    PHD,
    OTHER,
} TypeofED;

// date struct
typedef struct
{
    int date;
    int month;
    int year;
} Date;

// student struct
// needs name,date of birth,GPA,type_of_education(masters,phd...)
typedef struct
{
    int id;
    char name[30];
    Date date_of_birth;
    TypeofED type_of_education;
} student;

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

// load contents
int load(char *filename, student *s)
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Could not open %s\n", filename);
        return 0;
    }

    int i = 0;

    while (i < MAXSTUDENTS)
    {
        int education;

        int result = fscanf(
            fp,
            "%d %29s %d %d %d %d",
            &s[i].id,
            s[i].name,
            &s[i].date_of_birth.year,
            &s[i].date_of_birth.month,
            &s[i].date_of_birth.date,
            &education);

        if (result != 6)
        {
            break;
        }

        s[i].type_of_education = (TypeofED)education;

        i++;
    }

    fclose(fp);

    return i;
}

// save contents
int save(char *filename, const student *s, int count)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
    {
        printf("Could not open %s for saving\n", filename);
        return 0;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(
            fp,
            "%d %s %d %d %d %d\n",
            s[i].id,
            s[i].name,
            s[i].date_of_birth.year,
            s[i].date_of_birth.month,
            s[i].date_of_birth.date,
            s[i].type_of_education);
    }

    fclose(fp);

    printf("\nSaved %d students\n", count);

    return 1;
}

// add function
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
    printf("\nsuccessfully registered. %s with ID of %d: ",
           student->name,
           student->id);

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
            printf(
                "%d\n%s\n%d %d %d\n %s\n",
                student->id,
                student->name,
                student->date_of_birth.year,
                student->date_of_birth.month,
                student->date_of_birth.date,
                typeofeducation(student->type_of_education));

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
        printf(
            "\n%d\n%s\n%d %d %d\n %s\n",
            student->id,
            student->name,
            student->date_of_birth.year,
            student->date_of_birth.month,
            student->date_of_birth.date,
            typeofeducation(student->type_of_education));

        student++;
        local_count++;
    }

    return;
}

// main for testing
int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf(
            "Usage: %s <filename> <display|search|add|displayall>\n",
            argv[0]);

        return 1;
    }

    student students[MAXSTUDENTS];

    int count = load(argv[1], students);

    if (strcmp(argv[2], "display") == 0)
    {
        printf("what is the student Id? ");

        int student_Id;
        scanf("%d", &student_Id);

        displayfunction(students, student_Id, count);

        return 0;
    }

    if (strcmp(argv[2], "search") == 0)
    {
        printf("what is the student Id? ");

        int student_Id;
        scanf("%d", &student_Id);

        searchfunction(students, student_Id, count);

        return 0;
    }

    if (strcmp(argv[2], "add") == 0)
    {
        addstudent(students, &count);

        if (save(argv[1], students, count) == 0)
        {
            return 1;
        }

        return 0;
    }

    if (strcmp(argv[2], "displayall") == 0)
    {
        displayall_students(students, count);

        return 0;
    }

    printf("Unknown command: %s\n", argv[2]);

    return 1;
}