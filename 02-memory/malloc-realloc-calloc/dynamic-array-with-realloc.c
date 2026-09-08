#include <stdlib.h>
#include <stdio.h>

// make the array
int make_array(int **pointer)
{
    int capacity;
    printf("what is the initial size of the array?: \n");
    scanf("%d", &capacity);
    // allocate safely
    if (capacity <= 0)
    {
        printf("capacity must be greater than 0\n");
        return 0;
    }
    int *new_pointer = malloc(capacity * sizeof(int));
    if (new_pointer == NULL)
    {
        printf("allocation failed");
        return 0;
    }

    *pointer = new_pointer;
    return capacity;
}

int add_element(int **pointer, int index, int capacity)
{
    if (index >= capacity)
    {
        int *new_pointer = realloc(*pointer, (capacity * 2) * sizeof(int));
        if (new_pointer == NULL)
        {
            printf("reallocation failed");
            return 0;
        }
        *pointer = new_pointer;
        printf("resize: %d -> %d\n", capacity, capacity * 2);
        capacity *= 2;
    }
    int value;
    printf("what is the value of index %d:  ", index);
    scanf("%d", &value);
    *(*pointer + index) = value;
    return capacity;
}

int main()
{
    // initalize pointer to NULL
    int *pointer = NULL;

    // get the size of the user input array safely
    int new_capacity = make_array(&pointer);
    if (new_capacity == 0)
    {
        printf("there has been an error");
        free(pointer);
        return 1;
    }
    int capacity = new_capacity;
    ;
    // now lets set values to the allocated array
    int count = 0;

    for (int i = 0; i < 10; i++)
    {
        new_capacity = add_element(&pointer, count, capacity);
        if (new_capacity == 0)
        {
            free(pointer);
            return 1;
        }
        capacity = new_capacity;
        count++;
    }
    printf("\nValues: ");

    for (int i = 0; i < count; i++)
    {
        printf("%d ", *(pointer + i));
    }

    printf("\n");

    printf("The new capacity of your array after %d input is %d", count, capacity);
    int *new_pointer = realloc(pointer, count * sizeof(int));

    if (new_pointer == NULL)
    {
        printf("shrink failed\n");
        free(pointer);
        return 1;
    }

    pointer = new_pointer;
    capacity = count;
    printf("\nThe new capacity of your array after resize is %d", capacity);
    free(pointer);
    pointer = NULL;
    return 0;
}