#include "students.h"
#include <stdio.h>

int main(void)
{
    student students[10];
    int count = 0;

    // add a few students
    addstudent(students, &count);
    addstudent(students, &count);
    addstudent(students, &count);

    printf("\nALL STUDENTS:\n");
    displayall_students(students, count);

    printf("\n\nSEARCH TEST:\n");
    searchfunction(students, 1001, count);

    printf("\n\nDISPLAY ONE STUDENT:\n");
    displayfunction(students, 1000, count);

    printf("\n");

    return 0;
}