#include <stdio.h>
void selection_sort(int *array, int size)
{
    int *pointer = array;
    int *end = array + size - 1;
    while (pointer < end)
    {
        int *smallest = pointer;
        for (int i = 1; i <= (end - pointer); i++)
        {
            if (*smallest > *(pointer + i))
            {
                smallest = pointer + i;
            }
        }
        if (smallest != pointer)
        {
            int temp = *pointer;
            *pointer = *smallest;
            *smallest = temp;
        }
        pointer++;
    }
}
int main(void)
{
    int numbers[] = {64, 25, 12, 22, 11};
    int size = 5;

    selection_sort(numbers, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}