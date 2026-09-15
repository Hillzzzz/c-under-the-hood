
#include <stdio.h>
void insertion_sort(int *arr, int size)
{
    int *sr_end = arr;
    int *ar_end = arr + size - 1;

    while (sr_end < (ar_end))
    {

        if (*sr_end < *(sr_end + 1))
        {
            sr_end++;
        }
        else
        {
            for (int *pointer = arr; pointer <= sr_end; pointer++)
            {
                if (*pointer > *(sr_end + 1))
                {
                    int *shifter = sr_end + 1;

                    while (shifter > pointer)
                    {
                        // swap
                        int temp = *shifter;
                        *shifter = *(shifter - 1);
                        *(shifter - 1) = temp;
                        shifter--;
                    }

                    break;
                }
            }
            sr_end++;
        }
    }
}

int main(void)
{
    int array[] = {7, 3, 9, 2, 5};
    int size = sizeof array / sizeof array[0];

    printf("Before:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    insertion_sort(array, size);

    printf("After:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}
