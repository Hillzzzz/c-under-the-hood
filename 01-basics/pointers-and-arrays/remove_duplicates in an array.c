void removeduplicate(int *pointer, int size)
{
    int *end = pointer + size;
    int *read = pointer;
    int *write = pointer;
    while (read < end)
    {
        int is_duplicate = 0;
        for (const int *check = pointer; check < write; check++)
        {
            if (*read = *check)
            {
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate)
        {
            write = *read;
            write++;
        }
        read++;
    }
}