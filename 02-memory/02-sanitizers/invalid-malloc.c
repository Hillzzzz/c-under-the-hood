#include <stdlib.h>

int main(void)
{
    int count = -10;
    // comment the below
    // from here

    if (count <= 0)
    {
        return 1;
    }
    // to here to see the error

    int *p = malloc(count * sizeof *p);

    if (p == NULL)
        return 1;

    free(p);
    return 0;
}