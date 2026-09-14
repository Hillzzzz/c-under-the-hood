#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

int read_int()
{
    char buffer[100];
    char *end;
    while (1)
    {
        if (fgets(buffer, sizeof buffer, stdin) == NULL)
            return -1;

        buffer[strcspn(buffer, "\n")] = '\0';
        errno = 0;
        long number = strtol(buffer, &end, 10);

        if (end == buffer)
        {
            printf("no input. Try again\n");
            continue;
        }

        while (isspace((unsigned char)*end))
        {
            end++;
        }
        if (errno == ERANGE)
        {
            printf("number is too large or too small\n");
            continue;
        }
        if (*end != '\0')
        {
            printf("invalid characters detected: %s\n", end);
            continue;
        }
        if (number < 0 || number > 100)
        {
            printf("number out of bounds try again");
            continue;
        }
        return number;
    }
}
int main(void)
{
    printf("enter number: ");
    int number = read_int();
    printf("the number you entered is %d", number);
    return 0;
}