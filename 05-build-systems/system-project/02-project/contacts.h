#ifndef CONTACTS_H
#define CONTACTS_H

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_CONTACTS 100

typedef struct
{
    int Id;
    char name[MAX_NAME_LEN];
    char phone_number[MAX_PHONE_LEN];
} contacts;

void add_contact(contacts *p, int *count);
void delete_contact(contacts *p, int id, int *count);
void list_contacts(const contacts *p, int count);

#endif // CONTACTS_H