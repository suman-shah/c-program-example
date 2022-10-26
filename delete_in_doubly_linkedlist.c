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

// Deleting a node from linkedlist
struct My_dll *delete (my_dll *list, int position)
{
    struct node *head = list->head;
    struct node *temp = head;
    struct node *temp2 = NULL;

    if (position == 0)
    {
        if (head->next == 0)
        {

            list->head = 0;
        }
        else
        {
            struct node *temp = head;
            head = head->next;
            list->head = head;
            list->head->prev = NULL;
            free(temp);
        }
        return list;
    }

    while (position > 0)
    {
        temp = temp->next;
        position--;
    }
    if (temp->next == NULL)
    {
        struct node *temp = head;
        struct node *temp2;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp2 = temp->prev;
        temp2->next = NULL;
        free(temp);
        return list;
    }
    else
    {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
    }
    return list;
}

// Deleting alternate nodes from the linkedlist

void prune(my_dll *list)
{
    struct node *head = list->head;
    int temp = get_size(list) - 1;
    if (temp % 2 == 0)
    {
        temp--;
    }
    for (int i = temp; i >= 0; i -= 2)
    {
        list = delete (list, i);
    }
}

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
        if (strcmp(name, "delete") == 0)
        {
            int index;
            scanf("%d", &index);
            list = delete (list, index);
        }
        else if (strcmp(name, "print") == 0)
        {
            print(list);
        }
        else if (strcmp(name, "prune") == 0)
        {
            prune(list);
        }
        else if (strcmp(name, "exit") == 0)
        {
            return 0;
        }
    }
    return 0;
}
