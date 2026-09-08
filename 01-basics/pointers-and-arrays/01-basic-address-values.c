#include <stdio.h>

int main()
{
    // start of question 1
    //  declaring an int and then changing through the pointer.

    int number = 7;
    int *pnumber = &number;
    *pnumber = 10;
    printf("%d\n", number);

    // done with question 1
}