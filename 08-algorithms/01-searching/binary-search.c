#include <stdio.h>

int binary_search(const int *array, int size, int target)
{
    const int *low = array;
    const int *high = (array + size - 1);
    int iteration_counter = 0;

    while (low <= high)
    {
        iteration_counter += 1;
        printf("[Debug] Iteration count: %d\n", iteration_counter);

        const int *mid = low + (high - low) / 2;

        if (*mid == target)
        {
            return (int)(mid - array);
        }
        else if (*mid < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main(void)
{
    int numbers[] = {3, 8, 12, 19, 27, 31, 44, 58};
    int index = binary_search(numbers, 8, 19);

    printf("Result: Target found at index %d\n", index);
    return 0;
}