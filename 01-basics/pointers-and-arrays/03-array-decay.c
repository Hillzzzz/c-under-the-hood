#include <stdio.h>

void iterate_over_array(int *p, int number);

int main()
{
    int arrayofnumbers[5] = {1, 2, 3, 4, 5};
    int *pnumber = &arrayofnumbers[0];

    // start of question 4
    iterate_over_array(pnumber, 4);
    // end of question 4
}

// part of question 4
void iterate_over_array(int *p, int number)
{
    for (int i = 0; i < number; i++)
    {
        int value = *(p + i);
        printf(" %d ", value);
    }
}
// end of part of question 4