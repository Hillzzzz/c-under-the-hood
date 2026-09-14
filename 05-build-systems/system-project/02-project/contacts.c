#include <stdio.h>
#include <string.h>
#include "contacts.h"

void add_contact(contacts *p, int *count)
{
    if (*count >= MAX_CONTACTS)
    {
        printf("Error: Contact storage is full.\n");
        return;
    }

    char name_buf[MAX_NAME_LEN];
    char phone_buf[MAX_PHONE_LEN];

    printf("Name: \n");
    if (scanf("%49s", name_buf) != 1)
    {
        printf("Error reading name.\n");
        return;
    }

    printf("Number: \n");
    if (scanf("%19s", phone_buf) != 1)
    {
        printf("Error reading number.\n");
        return;
    }

    // Set structure fields using array indexing
    p[*count].Id = 1000 + *count;

    strncpy(p[*count].name, name_buf, MAX_NAME_LEN - 1);
    p[*count].name[MAX_NAME_LEN - 1] = '\0';

    strncpy(p[*count].phone_number, phone_buf, MAX_PHONE_LEN - 1);
    p[*count].phone_number[MAX_PHONE_LEN - 1] = '\0';

    printf("Added %s (%s) successfully!\n", p[*count].name, p[*count].phone_number);

    (*count)++;
}

void delete_contact(contacts *p, int id, int *count)
{
    if (p == NULL || count == NULL || *count <= 0)
    {
        printf("Error: Contact list is empty.\n");
        return;
    }

    contacts *localpointer = p;
    contacts *tbd = NULL;

    while (localpointer < (p + *count))
    {
        if (localpointer->Id == id)
        {
            tbd = localpointer;
            break;
        }
        localpointer++;
    }

    if (tbd == NULL)
    {
        printf("Error: Contact with ID %d not found.\n", id);
        return;
    }

    for (contacts *p1 = tbd; p1 < (p + *count - 1); p1++)
    {
        *p1 = *(p1 + 1);
    }

    (*count)--;
    printf("Contact ID %d successfully deleted.\n", id);
}

void list_contacts(const contacts *p, int count)
{
    printf("\n=== CONTACT LIST (%d) ===\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("[%d] Name: %s | Phone: %s\n", p[i].Id, p[i].name, p[i].phone_number);
    }
}