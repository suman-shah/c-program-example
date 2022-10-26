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

// Find the index of any node in the doubly linked list.

void find(my_dll *list, int x)
{
    struct node *head = list->head;
    int index = 0;
    while (head != NULL)
    {
        if (head->data == x)
        {
            printf("%d\n", index);
            return;
        }
        index++;
        head = head->next;
    }
    printf("-1\n");
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
        if (strcmp(name, "print") == 0)
        {
            print(list);
        }
        else if (strcmp(name, "find") == 0)
        {
            int a;
            scanf("%d", &a);
            find(list, a);
        }
        else if (strcmp(name, "exit") == 0)
        {
            return 0;
        }
    }
    return 0;
}
