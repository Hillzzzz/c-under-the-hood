#include <stdio.h>

#define MAXSTUDENTS 100

typedef struct
{
    int ID;
    char Name[20];
    char department[20];
    int age;
} student;

void load_Data(student *db, int *count)
{
    FILE *fp = fopen("output.txt", "r");
    if (fp == NULL)
    {
        printf("No existing file found. Starting empty.\n");
        *count = 0;
        return;
    }

    *count = 0;
    while (*count < MAXSTUDENTS &&
           fscanf(fp, "%d %19s %19s %d",
                  &db[*count].ID,
                  db[*count].Name,
                  db[*count].department,
                  &db[*count].age) == 4)
    {
        (*count)++;
    }

    fclose(fp);
    printf("Successfully loaded %d student(s).\n", *count);
}

void add(student *db, int *count, int *changelog, int **logpointer)
{
    if (*count >= MAXSTUDENTS)
    {
        printf("Database full!\n");
        return;
    }

    printf("what is the ID of the student: ");
    scanf("%d", &db[*count].ID);
    printf("what is the name of the student: ");
    scanf("%19s", db[*count].Name);
    printf("what is the dept of the student: ");
    scanf("%19s", db[*count].department);
    printf("what is the age of the student: ");
    scanf("%d", &db[*count].age);

    // Track index in changelog
    **logpointer = *count;
    (*logpointer)++;
    (*count)++;
}

void search(const student *s, int Id, int count)
{
    const student *local_pointer = s;

    while (local_pointer != s + count)
    {
        if (local_pointer->ID == Id)
        {
            printf("student found: %s\n", local_pointer->Name);
            return;
        }
        local_pointer++;
    }
    printf("student not found.\n");
}

void displayall_students(const student *db, int count)
{
    int local_count = 0;
    printf("\n--- Records (%d) ---\n", count);
    while (local_count < count)
    {
        printf("%d %s %s %d\n", db->ID, db->Name, db->department, db->age);
        db++;
        local_count++;
    }
}

void save(const student *db, int *changelog, const int *logpointer)
{
    FILE *fp = fopen("output.txt", "a");
    if (fp == NULL)
    {
        perror("Error opening file for save");
        return;
    }

    const int *start = changelog;
    while (start != logpointer)
    {
        int index = *start;
        fprintf(fp, "%d %s %s %d\n",
                db[index].ID,
                db[index].Name,
                db[index].department,
                db[index].age);
        start++;
    }

    fclose(fp); // Placed safely OUTSIDE loop
    printf("Successfully saved changes to output.txt.\n");
}

int main(void)
{
    student db[MAXSTUDENTS];
    int count = 0;
    int changelog[10];
    int *logpointer = changelog;

    load_Data(db, &count);

    // Add student (logs index to changelog)
    add(db, &count, changelog, &logpointer);

    displayall_students(db, count);

    // Pass 3 arguments to match function signature
    save(db, changelog, logpointer);

    return 0;
}