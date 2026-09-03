
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *l1current = l1;
    struct ListNode *l2current = l2;
    struct ListNode *root = NULL;
    int icarry = 0;
    int *carry = &icarry;

    while (l1current != NULL || l2current != NULL)
    {
        if (l1current != NULL && l2current != NULL)
        {
            construct_list(&root, (l1current->val + l2current->val), carry);
            l1current = l1current->next;
            l2current = l2current->next;
        }
        else if (l1current == NULL)
        {
            construct_list(&root, l2current->val, carry);
            l2current = l2current->next;
        }
        else if (l2current == NULL)
        {
            construct_list(&root, l1current->val, carry);
            l1current = l1current->next;
        }
    }
    return root;
}

void construct_list(struct ListNode **root, int value, int *carry)
{
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    if (new_node == NULL)
    {
        exit(1);
    }

    value = value + *carry;

    if (value >= 10)
    {
        *carry = value / 10;
        value = value % 10;
    }
    else
    {
        carry = 0;
    }
    new_node->val = value;
    new_node->next = NULL;

    if (*root == NULL)
    {
        *root = new_node;
        return;
    }
    struct ListNode *current = *root;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    return;
}
