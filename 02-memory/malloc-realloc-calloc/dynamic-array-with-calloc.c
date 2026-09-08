
#include <stdio.h>
#include <stdlib.h>
void addelement(int *p, int index)
{
    int value;
    printf("\n what is the value for index %d? \n", index);
    scanf("%d", &value);
    *(p + index) = value;
    printf("you have set the value %d\n", *(p + index));
}

int setdynamic_array(int **pointer)
{
    int size;
    printf("\n how many numbers in your array? \n");
    scanf(" %d", &size);
    if (size <= 0)
    {
        printf("Size must be greater than zero.\n");
        return 0;
    }
    *pointer = calloc((size_t)size, sizeof(int));
    if (*pointer == NULL)
    {
        printf("Allocation error: Out of memory.\n");
        return 0;
    }
    return size;
}

int main()
{
    int *pointer = NULL;
    int size = setdynamic_array(&pointer);
    printf("calloc sets all values to 0? \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(pointer + i));
    }
    for (int i = 0; i < size; i++)
    {
        addelement(pointer, i);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(pointer + i));
    }

    free(pointer);
    pointer = NULL;
    return 0;
}
