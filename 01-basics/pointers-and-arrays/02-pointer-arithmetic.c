#include <stdio.h>

void changevalue_frompointer(int *pointer);

int main()
{
    int number = 7;
    int *pnumber = &number;

    // start of question 2
    changevalue_frompointer(pnumber);
    printf("%d\n", number);
    // end of question 2
}

// part of question 2
void changevalue_frompointer(int *pointer)
{
    *pointer = *pointer * 3;
    return;
}
// end of part of question 2