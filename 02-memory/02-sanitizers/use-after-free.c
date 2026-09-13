#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = malloc(sizeof *p);

    if (p == NULL)
        return 1;

    *p = 42;
    // uncomment this for the error

    // free(p);

    printf("%d\n", *p);
    free(p);
    p = NULL;

    return 0;
}