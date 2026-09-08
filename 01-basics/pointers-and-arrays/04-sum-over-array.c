#include <stdio.h>

void sum_over_array(int *p, int number);

int main()
{
    int arrayofnumbers[5] = {1, 2, 3, 4, 5};
    int *pnumber = &arrayofnumbers[0];

    // start of question 5
    sum_over_array(pnumber, 4);
    // end of question 5
}

// part of question 5
void sum_over_array(int *p, int number)
{
    int value = 0;

    for (int i = 0; i < number; i++)
    {
        value += *(p + i);
        printf("%d", value);
    }
}
// end of part of question 5