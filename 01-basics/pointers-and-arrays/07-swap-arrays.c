// we will swap two arrays of the same size using pointers
#include <stdio.h>
void swapping_using_pointers(int *p1, int *p2, int size);
void traversal(const int *p, int n);
int main()
{
    int array1[] = {1, 2, 3, 4};
    int array2[] = {5, 6, 7, 8};
    size_t size = sizeof(array1) / sizeof(array1[0]);

    printf("this is array 1 before\n");
    traversal(array1, size);
    printf("this is array 2 before\n");
    traversal(array2, size);
    swapping_using_pointers(array1, array2, size);
    printf("this is array 1 after\n");
    traversal(array1, size);
    printf("this is array 2 after\n");
    traversal(array2, size);
    return 0;
}
void swapping_using_pointers(int *p1, int *p2, int size)
{
    for (int i = 0; i < size; i++)
    {
        int store = *(p1 + i);
        *(p1 + i) = *(p2 + i);
        *(p2 + i) = store;
    }
}
void traversal(const int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d \n", *(p + i));
    }
}
