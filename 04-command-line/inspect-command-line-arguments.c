#include <stdio.h>
int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    return 0;
}
// write in shell to compile
// gcc argv+argv.c -o args
// then write something like:
// then give it ./args hello world 22
