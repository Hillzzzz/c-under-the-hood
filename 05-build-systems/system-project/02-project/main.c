#include <stdio.h>
#include "contacts.h"

int main(void)
{
    contacts contact_list[MAX_CONTACTS];
    int count = 0;

    add_contact(contact_list, &count);
    list_contacts(contact_list, count);

    return 0;
}