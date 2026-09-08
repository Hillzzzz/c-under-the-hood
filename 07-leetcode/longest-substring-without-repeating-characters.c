// string is given
// we want to return integer
// implementation
// use two pointers and one length editable
#include <stdio.h>
#include <string.h>
int lengthOfLongestSubstring(char *s)
{
    if (*s == '\0')
        return 0;
    if (*(s + 1) == '\0')
    {
        return 1;
    }
    char *start = s;
    char *end = s + 1;
    int number = 0;
    while (*end != '\0')
    {
        for (char *p = start; p < end; p++)
        {
            if (*p == *end)
            {
                start = p + 1;
                break;
            }
        }
        int current_length = end - start + 1;
        if (current_length > number)
        {

            number = current_length;
        }
        end++;
    }
    return number;
}

int main()
{
    char s[] = "hanselel";
    int length = lengthOfLongestSubstring(s);
    printf("%d", length);
    return 0;
}