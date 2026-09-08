#include <stdio.h>
void traversal(const int *p, int n);
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    tranversal(array, sizeof(array) / sizeof(array[0]));
    return 0;
}

void traversal(const int *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d \n", *(p + i));
    }
}