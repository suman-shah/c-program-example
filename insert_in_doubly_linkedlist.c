#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

typedef struct My_dll my_dll;
struct My_dll
{
    struct node *head; // head=root
};

// Insert at the end of the linked list.

struct My_dll *insert(my_dll *list, int data)
{
    struct node *head = list->head;
    struct node *temp = malloc(sizeof(struct node));
    if (head == NULL)
    {
        head = temp;
        temp->data = data;
        list->head = head;
        return list;
    }
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    struct node *tp;
    tp = head;
    while (tp->next != NULL)
    {
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return list;
}

// Insert at any position in the linked list.

struct My_dll *insert_at(my_dll *list, int data, int position)
{
    struct node *head = list->head;
    struct node *temp = malloc(sizeof(struct node));
    struct node *newp = NULL;
    // struct My_dll*new_node;
    newp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    // struct My_dll *temp2 = NULL;
    if (position == 0)
    {
        newp->next = head;
        head->prev = newp;
        head = newp;
        newp->data = data;
        newp->prev = NULL;
        list->head = head;
        return list;
    }
    for (int i = 0; i < position - 1; i++)
        temp = temp->next;
    newp->data = data;
    newp->next = temp->next;
    temp->next = newp;
    if (newp->next)
        newp->next->prev = newp;
    newp->prev = temp;
    return list;
}

// Print the linked list.

void print(my_dll *list)
{
    struct node *head = list->head;

    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    struct My_dll *list;
    list = (struct My_dll *)malloc(sizeof(struct My_dll));
    list->head = NULL;
    while (1)
    {
        char name[100];
        scanf("%s", name);
        if (strcmp(name, "insert") == 0)
        {
            int n;
            scanf("%d", &n);
            list = insert(list, n);
        }
        else if (strcmp(name, "insert_at") == 0)
        {
            int m;
            int idx;
            scanf("%d %d", &m, &idx);
            list = insert_at(list, m, idx);
        }
        else if (strcmp(name, "print") == 0)
        {
            print(list);
        }
        else if (strcmp(name, "exit") == 0)
        {
            return 0;
        }
    }
    return 0;
}
