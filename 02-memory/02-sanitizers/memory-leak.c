#include <stdlib.h>

int main(void)
{
    int *p = malloc(100 * sizeof *p);

    if (p == NULL)
        return 1;

    p[0] = 50;
    free(p); // comment this out to see the error

    return 0;
}