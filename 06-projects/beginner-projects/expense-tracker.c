#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char expense_name[10];
    char category[10];
    float amount;
    char date[12];
} expense;

void addexp(expense *exp, int *elements);
void viewexp(expense *exp, int elements);
void delete_expense(expense *exp, int *elements);

int main()
{
    expense *exp = malloc(4 * sizeof(expense));
    int elements = 0;

    // Hardcoded initial expense 1
    strcpy(exp[0].expense_name, "Lunch");
    strcpy(exp[0].category, "food");
    exp[0].amount = 12.50;
    strcpy(exp[0].date, "2026-08-01");
    elements++;

    // Hardcoded initial expense 2
    strcpy(exp[1].expense_name, "Taxi");
    strcpy(exp[1].category, "transport");
    exp[1].amount = 8.00;
    strcpy(exp[1].date, "2026-08-02");
    elements++;

    // Hardcoded initial expense 3
    strcpy(exp[2].expense_name, "Coffee");
    strcpy(exp[2].category, "food");
    exp[2].amount = 3.75;
    strcpy(exp[2].date, "2026-08-03");
    elements++;

    delete_expense(exp, &elements);
    viewexp(exp, elements);

    free(exp);
    return 0;
}

void addexp(expense *exp, int *elements)
{
    printf("you are now adding an expense.\n");
    printf("what is the name of the expense?\n ");
    scanf(" %9s", exp[*elements].expense_name);
    printf("what is the category of the expense? \n");
    scanf(" %9s", exp[*elements].category);
    printf("what is the amount of the expense? \n");
    scanf(" %f", &exp[*elements].amount);
    printf("what is the date of the expense? \n");
    scanf(" %11s", exp[*elements].date);
    *elements += 1;
}

void viewexp(expense *exp, int elements)
{
    for (int i = 0; i < elements; i++)
    {
        printf(" %d,%s,%s,%s,%f \n", i, exp[i].category, exp[i].expense_name, exp[i].date, exp[i].amount);
    }
}

void totalexp(int elements, expense *exp)
{
    float total = 0;
    for (int i = 0; i < elements; i++)
    {
        total += exp[i].amount;
    }
    printf("your total expense is: %f", total);
}

void expense_by_catagory(expense *exp, int elements)
{
    int catagory = 0;
    float total = 0;
    char catagoryworded[20] = "";
    printf("which catagory would you like to see the expense of?\n 1. for food, 2 for transport, 3 for accessories, 4 for investing, 5 for utilities");
    scanf(" %d", &catagory);
    switch (catagory)
    {
    case 1:
        strcpy(catagoryworded, "food");
        break;
    case 2:
        strcpy(catagoryworded, "transport");
        break;
    case 3:
        strcpy(catagoryworded, "accessories");
        break;
    case 4:
        strcpy(catagoryworded, "investing");
        break;
    case 5:
        strcpy(catagoryworded, "utilities");
        break;
    default:
        printf("sorry this catagory doesnt exist. please retry with a correct number");
        return;
    }

    for (int i = 0; i < elements; i++)
    {
        if (strcmp(exp[i].category, catagoryworded) == 0)
        {
            printf("we have %s with %f\n", exp[i].expense_name, exp[i].amount);
            total += exp[i].amount;
        }
    }
    printf("the catagory %s expense is given by: %f", catagoryworded, total);
}

void delete_expense(expense *exp, int *elements)
{
    int index = 0;
    printf("hello these are your lists of expenses please select the to be deleted by ID\n");
    viewexp(exp, *elements);
    printf("which of these would you like to delete? ");
    fflush(stdout);
    scanf(" %d", &index);
    if (index < 0 || index >= *elements)
    {
        printf("Invalid index!\n");
        return;
    }
    for (int i = index; i < *elements - 1; i++)
    {
        exp[i] = exp[i + 1];
    }
    *elements -= 1;
}