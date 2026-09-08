#include <stdio.h>

void swap_numbers_in_array(int *number1, int *number2);

int main()
{
    // start of question number 9
    int number1 = 8;
    int number2 = 4;
    printf("number1 %d, number2 %d", number1, number2);
    swap_numbers_in_array(&number1, &number2);
    printf("number1 %d, number2 %d", number1, number2);
    // end of question number 9
}

// part of number 9
void swap_numbers_in_array(int *number1, int *number2)
{
    int temphold = *(number1);
    *number1 = *number2;
    *number2 = temphold;
    return;
}
// end of part of number 9