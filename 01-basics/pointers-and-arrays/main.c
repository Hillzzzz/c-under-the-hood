#include <stdio.h>
void changevalue_frompointer(int *pointer);
void changepointer(int **pointer, int *new_numberaddress);
void iterate_over_array(int *p, int number);
void sum_over_array(int *p, int number);
void mirrorflip_array(int *p, int number);
void max_min_extractor(int *p, int number, int *max, int *min);
void transverse_til_n(int *pointer, int n);
void swap_numbers_in_array(int *number1, int *number2);
int main()
{
    // start of question 1
    //  declaring an int and then changing through the pointer.

    int number = 7;
    int *pnumber = &number;
    *pnumber = 10;
    printf("%d\n", number);
    printf("\ndone with question\n");

    // done with question 1

    // start of question 2
    changevalue_frompointer(pnumber);
    printf("%d\n", number);
    printf("\ndone with question\n");
    // end of question 2

    // start of question 3
    int newnumber = 12;
    changepointer(&pnumber, &newnumber);
    printf("%d\n", *pnumber);
    printf("\ndone with question\n");
    // end of question 3

    // start of question 4
    int arrayofnumbers[5] = {1, 2, 3, 4, 5};
    pnumber = &arrayofnumbers[0];
    iterate_over_array(pnumber, sizeof(arrayofnumbers) / sizeof(arrayofnumbers[0]));
    printf("\ndone with question\n");
    // end of question 4

    // start of question 5
    sum_over_array(pnumber, sizeof(arrayofnumbers) / sizeof(arrayofnumbers[0]));
    printf("\ndone with question\n");
    // end of question 5

    // question number 6
    mirrorflip_array(pnumber, sizeof(arrayofnumbers) / sizeof(arrayofnumbers[0]));
    printf("\ndone with question\n");
    // end of question number 6

    // start of question number 7
    int max = 0;
    int min = 0;
    max_min_extractor(pnumber, sizeof(arrayofnumbers) / sizeof(arrayofnumbers[0]), &max, &min);
    printf("%d  and %d", max, min);
    printf("\ndone with question\n");
    // end of question number 7

    // start of question number 8
    transverse_til_n(pnumber, 3);
    printf("\ndone with question\n");
    // end of question number 8

    // start of question number 9
    int number1 = 8;
    int number2 = 4;
    printf("number1 = %d and number2 = %d \n", number1, number2);
    swap_numbers_in_array(&number1, &number2);
    printf("number1 = %d and number2 = %d ", number1, number2);
    printf("\ndone with question\n");
    // end of question number 9
}

// part of question 2
void changevalue_frompointer(int *pointer)
{
    *pointer = *pointer * 3;
    return;
}
// end of part of question 2

// part of question 3
void changepointer(int **pointer, int *new_numberaddress)
{
    *pointer = new_numberaddress;
    return;
}
// end of part of question 3

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

// part of question 5
void sum_over_array(int *p, int number)
{
    int value = 0;

    for (int i = 0; i < number; i++)
    {
        value += *(p + i);
    }
    printf("%d\n", value);
}
// end of part of question 5

// part of question 6
void mirrorflip_array(int *p, int number)
{
    int *start = p;
    int *end = p + number - 1;
    while (start < end)
    {
        int tempstore = *start;
        *start = *end;
        *end = tempstore;
        start++;
        end--;
    }
    iterate_over_array(p, number);
}

// end of part of question 6

// part of number 7
void max_min_extractor(int *p, int number, int *max, int *min)
{
    /* lets just set min and max to the first number at first
    then we go to i+1 if the number is greater than max we have our
    new max if it is less than min we have our new min until the iteration is over
    */
    *max = *p;
    *min = *p;
    for (int i = 1; i < number; i++)
    {
        if (*(p + i) > *max)
        {
            *max = *(p + i);
        }
        else if (*(p + i) < *(min))
        {
            *min = *(p + i);
        }
    }
    return;
}
// end of part of number 7

// part of number 8
void transverse_til_n(int *pointer, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", *(pointer + i));
    }
}
// end of number 8

// part of number 9
void swap_numbers_in_array(int *number1, int *number2)
{
    int temphold = *(number1);
    *number1 = *number2;
    *number2 = temphold;
    return;
}
// end of part of number 9
