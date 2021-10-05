//doubly linked list

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;

int size()
{
    int c = 1;
    struct node *p = head;
    if (head == NULL)
    {
        printf("Linked List is empty.");
        return 0;
    }
    while (p->next != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

void display()
{
    struct node *p = head;
    while (p->next != NULL)
    {
        printf("%d <-> ", p->data);
        p = p->next;
    }

    printf("%d", p->data);
}

void insertHead(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    new->data = data;
    new->prev = NULL;
    new->next = head;
    head = new;
}

void insertTail(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        insertHead(data);
        return;
    }
    struct node *p = head;
    while (p->next != NULL)
        p = p->next;
    new->data = data;
    p->next = new;
    new->prev = p;
    new->next = NULL;
}

void insertPos(int pos, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (pos == 1)
    {
        insertHead(data);
        return;
    }
    new->data = data;
    struct node *p = head;
    struct node *q = head;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    for (int i = 1; i < pos; i++)
    {
        q = q->next;
    }
    p->next = new;
    new->prev = p;
    new->next = q;
    q->prev = new;
}

void delHead()
{
    struct node *p = head;
    struct node *q = head->next;
    free(p);
    head = q;
    q->prev = NULL;
}

void delTail()
{
    struct node *p = head;
    struct node *q = head;
    while (p->next != NULL)
        p = p->next;
    for (int i = 1; i < size() - 1; i++)
        q = q->next;
    q->prev = p->prev;
    free(p);
    q->next = NULL;
}

void delPos(int pos)
{
    if (pos == 1)
    {
        delHead();
        return;
    }
    if (pos == size())
    {
        delTail();
        return;
    }
    struct node *p = head;
    struct node *q = head;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    for (int i = 1; i <= pos; i++)
    {
        q = q->next;
    }
    free(p->next);
    p->next = q;
    q->prev = p;
}

int main()
{
    printf("a. Display the elements of the linked list\n");
    printf("b. Insert an element at the beginning of the list\n");
    printf("c. Insert an element at the end of the list\n");
    printf("d. Insert an element at a specified position in the list\n");
    printf("e. Deletion of an element from the beginning of the list\n");
    printf("f. Deletion of an element from the end of the list\n");
    printf("g. Deletion of an element from a specified position in the list\n");
    while (1)
    {
        int data,pos;
        char choice;
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            display();
            break;
        case 'b':
            
            scanf("%d", &data);
            insertHead(data);
            break;
        case 'c':
            
            scanf("%d", &data);
            insertTail(data);
            break;
        case 'd':
            
            scanf("%d %d", &pos, &data);
            insertPos(pos, data);
            break;
        case 'e':
            delHead();
            break;
        case 'f':
            delTail();
            break;
        case 'g':
            
            scanf("%d", &pos);
            delPos(pos);
            break;
        default:
            printf("!!!ERROR!!!");
            return 0;
        }
    }

    return 0;
}