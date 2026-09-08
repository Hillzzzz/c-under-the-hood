#include <stdio.h>
int operation(int firstnumber, int secondnumber, char operand, int *error);

int main()
{
    printf("--SIMPLE CALCULATOR--\n");
    int firstnumber;
    int secondnumber;
    char operand;
    int error = 0;
    printf(" enter the first number: \n");
    scanf("%d", &firstnumber);
    printf(" enter the second number: \n");
    scanf("%d", &secondnumber);
    printf("what operation do you want to perform? the options are + - * /\n");
    scanf(" %c", &operand);
    int result = (operation(firstnumber, secondnumber, operand, &error));

    if (error)
    {
        printf("please enter a valid parameter next time");
    }
    else
    {
        printf("the result: %d", result);
    }
}

int operation(int firstnumber, int secondnumber, char operand, int *error)
{
    switch (operand)
    {
    case '+':
        return firstnumber + secondnumber;
        break;
    case '/':
        if (secondnumber == 0)
        {
            printf("invalid operation\n");
            *error = 1;
            return 0;
            break;
        }
        else
        {
            return firstnumber / secondnumber;
        }
        break;
    case '-':
        return firstnumber - secondnumber;
        break;
    case '*':
        return secondnumber * firstnumber;
        break;
    default:
        printf("you have the wrong operand please select a proper operand.");
        *error = 1;
    }
}