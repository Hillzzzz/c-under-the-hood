#include <stdio.h>
#include <ctype.h>
float convertor(char from, float fromvalue, char to, int *error);
int main()
{
    printf("standard temperature converter\n");
    int error = 0;
    char from;
    float fromvalue;
    char to;
    float convertedvalue;

    printf("what is the  temperature in? \n options are C/ K/ F: \n");
    scanf(" %c", &from);
    from = tolower((unsigned char)from);
    printf("what is the number of the temperature: \n");
    scanf(" %f", &fromvalue);
    printf("what unit do you want the temperature to ?\n options are C/ K/ F: \n");
    scanf(" %c", &to);
    to = tolower((unsigned char)to);
    convertedvalue = convertor(from, fromvalue, to, &error);
    if (error)
    {
        printf("you have input an invalid yada yada");
    }
    else
    {
        printf("%f %c converted to %c will be %f %c", fromvalue, from, to, convertedvalue, to);
    }
}

float convertor(char from, float fromvalue, char to, int *error)
{
    switch (from)
    {
    case 'k':
        if (to == 'k')
        {
            return fromvalue;
        }
        else if (to == 'f')
        {
            return (fromvalue - 273.15) * (9.0f / 5.0f) + 32;
        }
        else if (to == 'c')
        {
            return fromvalue - 273.15;
        }
        else
        {
            *error = 1;
            return 0;
        }

        // do operation
        break;
    case 'c':
        if (to == 'c')
        {
            return fromvalue;
        }
        else if (to == 'f')
        {
            return fromvalue * (9.0f / 5.0f) + 32;
        }
        else if (to == 'k')
        {
            return fromvalue + 273.15;
        }
        else
        {
            *error = 1;
            return 0;
        }
        break;
    case 'f':
        if (to == 'f')
        {
            return fromvalue;
        }
        else if (to == 'k')
        {
            return (fromvalue - 32) * 5.0f / 9.0f + 273.15;
        }
        else if (to == 'c')
        {
            return (fromvalue - 32) * 5.0f / 9.0f;
        }
        else
        {
            *error = 1;
            return 0;
        }
        break;
    default:
        *error = 1;
        return 0;
    }
}