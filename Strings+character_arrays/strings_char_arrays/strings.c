#include <stdio.h>

int my_strlen(const char *pointer)
{
    const char *first = pointer;

    while (*pointer != '\0')
    {
        pointer++;
    }
    return pointer - first;
}
char *my_strcpy(char *destination, char *source)
{
    char *start = destination;
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return start;
}
int my_strcmp(const char *s1, const char *s2)
{

    while (*s1 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

#include <stdio.h>
#include <assert.h> // add this

// ... your three functions here ...

int main(void)
{
    // ========== my_strlen tests ==========
    assert(my_strlen("") == 0);
    assert(my_strlen("a") == 1);
    assert(my_strlen("hello") == 5);
    assert(my_strlen("hello world") == 11);
    printf("my_strlen: all tests passed\n");

    // ========== my_strcpy tests ==========
    char buffer[50];

    my_strcpy(buffer, "hello");
    assert(my_strcmp(buffer, "hello") == 0);

    my_strcpy(buffer, "");
    assert(my_strcmp(buffer, "") == 0);

    my_strcpy(buffer, "C programming");
    assert(my_strcmp(buffer, "C programming") == 0);
    printf("my_strcpy: all tests passed\n");

    // ========== my_strcmp tests ==========
    assert(my_strcmp("abc", "abc") == 0);
    assert(my_strcmp("abc", "abd") < 0);
    assert(my_strcmp("abd", "abc") > 0);
    assert(my_strcmp("ab", "abc") < 0);
    assert(my_strcmp("abc", "ab") > 0);
    assert(my_strcmp("", "") == 0);
    assert(my_strcmp("a", "") > 0);
    assert(my_strcmp("", "a") < 0);
    printf("my_strcmp: all tests passed\n");

    printf("\nAll tests passed successfully!\n");
    return 0;
}