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

void print_reverse(my_dll *list)
{
    struct node *head = list->head;
    struct node *ptr1 = head;
    while (ptr1->next)
        ptr1 = ptr1->next;
    while (ptr1)
    {
        printf("%d ", ptr1->data);
        ptr1 = ptr1->prev;
    }
    printf("\n");
}

int get_size(my_dll *list)
{
    struct node *head = list->head;
    int res = 0;
    while (head != NULL)
    {
        res++;
        head = head->next;
    }
    return res;
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
        else if (strcmp(name, "print_reverse") == 0)
        {
            print_reverse(list);
        }
        else if (strcmp(name, "get_size") == 0)
        {
            printf("%d\n", get_size(list));
        }
        else if (strcmp(name, "exit") == 0)
        {
            return 0;
        }
    }
    return 0;
}
