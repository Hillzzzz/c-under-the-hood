#include <stdio.h>

int linear_search(const int *array, int target, int size, int *iterations)
{
    *iterations = 0;

    for (int i = 0; i < size; i++)
    {
        (*iterations)++;

        if (array[i] == target)
            return i;
    }

    return -1;
}

int binary_search(const int *array, int target, int size, int *iterations)
{
    int low = 0;
    int high = size - 1;

    *iterations = 0;

    while (low <= high)
    {
        (*iterations)++;

        int mid = low + (high - low) / 2;

        if (array[mid] == target)
            return mid;

        if (array[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main(void)
{
    int array[] = {2, 3, 5, 7, 9, 12, 15, 20};
    int size = sizeof array / sizeof array[0];

    int linear_iterations;
    int binary_iterations;

    int linear_index =
        linear_search(array, 12, size, &linear_iterations);

    int binary_index =
        binary_search(array, 12, size, &binary_iterations);

    printf("Linear search:\n");
    printf("Index: %d\n", linear_index);
    printf("Iterations: %d\n\n", linear_iterations);

    printf("Binary search:\n");
    printf("Index: %d\n", binary_index);
    printf("Iterations: %d\n", binary_iterations);

    return 0;
}