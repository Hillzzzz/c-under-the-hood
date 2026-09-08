
#include <stdio.h>
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("argument invalid");
        return 1;
    }
    FILE *fp = fopen(argv[1], "w");
    if (fp == NULL)
    {
        printf("Could not open file: %s\n", argv[1]);
        return 1;
    }

    fputs("hello,world!\n", fp);
    fclose(fp);
    return 0;
}