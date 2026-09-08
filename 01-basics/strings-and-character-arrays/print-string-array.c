#include <stdio.h>
void printchar(const char *pointer);

int main(void)
{
    char word[] = "cat";
    printf("%ld", sizeof(word));
    return 0;
}

void printchar(const char *pointer)
{
    while (*pointer != '\0')
    {
        printf("%c", *pointer);
        pointer++;
    }
    return;
}
