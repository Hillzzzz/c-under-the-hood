#include <stdlib.h>

int main(void)
{
    int *p = malloc(sizeof *p);

    if (p == NULL)
        return 1;

    free(p);
    // comment the line below for the error
    p = NULL;
    free(p);

    return 0;
}