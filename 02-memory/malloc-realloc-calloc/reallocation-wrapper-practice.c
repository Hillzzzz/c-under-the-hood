/*Ask user for N
allocate N ints
read N values
calculate:
- sum
- minimum
- maximum
- average
*/
#include <stdio.h>
#include <stdlib.h>
// user input
void addelement(int *pointer, int index)
{
    int value = 0;
    printf("\n what is the value for index %d ", index);
    scanf(" %d", &value);
    *(pointer + index) = value;
}

// allocate using malloc
int dynamic_array(int **pointer)
{
    int size = 0;
    printf("\nwhat is the number elements in your array ? ");
    scanf("%d", &size);
    if (size <= 0)
    {
        printf("\nyou have set an invalid amount");
        return 0;
    }
    *pointer = malloc(size * (size_t)sizeof(int));
    if (*pointer == NULL)
    {
        printf("\nallocation failed");
        return 0;
    }
    return size;
}

// calculate sum
int sumarray(const int *pointer, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(pointer + i);
    }
    return sum;
}

// maximum and minimum
void maxim_minim(const int *pointer, int *max, int *min, int size)
{
    int count = 0;
    const int *scan = pointer;
    while (count < size)
    {
        if (*scan >= *max)
            *max = *scan;
        else if (*scan < *min)
        {
            *min = *scan;
        }
        scan++;
        count++;
    }
}

// average calculator
float averagearray(const int *pointer, int size)
{
    if (size <= 0)
        return 0.0f;
    return (float)sumarray(pointer, size) / size;
}

int main()
{
    int *pointer = NULL;
    int size = dynamic_array(&pointer);

    if (size <= 0)
    {
        return 1;
    }
    for (int i = 0; i < size; i++)
    {
        addelement(pointer, i);
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(pointer + i));
    }
    printf("\n the sum is %d", sumarray(pointer, size));
    int max = *pointer;
    int min = *pointer;
    maxim_minim(pointer, &max, &min, size);
    printf("\nthe the max and min are: %d and %d ", max, min);
    printf("\nthe average will be: %.2f", averagearray(pointer, size));
    free(pointer);
    pointer = NULL;
    return 0;
}
