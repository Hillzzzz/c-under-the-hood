#ifndef STUDENTS_H
#define STYDENT_H
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

const char *typeofeducation(int number);
void addstudent(student *student, int *count);
void searchfunction(const student *student, int studentId, int count);
void displayfunction(const student *student, int studentId, int count);
void displayall_students(const student *student, int count);

#endif