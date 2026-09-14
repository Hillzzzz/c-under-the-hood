#include <stdio.h>

int linear_search(const int *array, int size, int target)
{
    const int *pointer = array;
    int index = 0;
    int debug_count = 0;

    while (index < size)
    {
        debug_count++;
        printf("Iteration %d: checking index %d\n", debug_count, index);

        if (*pointer == target)
        {
            return index;
        }
        index++;
        pointer++;
    }
    return -1;
}

int main(void)
{
    int numbers[] = {3, 8, 12, 19, 27, 31, 44, 58};
    int answer = linear_search(numbers, 8, 19);
    printf("Found at index: %d\n", answer);
    return 0;
}