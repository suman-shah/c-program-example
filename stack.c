#include <stdio.h>
#include <stdlib.h>

int top = -1; //Since the stack is not yet created, initialized the top of the stack as -1 since it doesnt exist yet.

void push(int la[], int x) //Function to add elements on top of the stack
{

    if (top >= x - 1)
    {
        printf("Stack is overflow\n\n");
    }
    else
    {
        int item;
        printf("Enter a value to be pushed : ");
        scanf("%d", &item);
        top++;          //Before adding the item first increment top variable so element is added at the next position.
        la[top] = item; //Added the item in the respective place.
    }
    printf("\n");
}

void pop(int la[]) //Function to remove elements from top of the stack.
{

    if (top <= -1) //If the top value is -1, this means that stack is empty and there is nothing to delete. This is called underflow condtion.
    {
        printf("Stack is underflow\n\n");
    }
    else //If the stack is not empty.
    {
        printf("The popped element is " "%d" "\n\n", la[top]);//Print the element which is deleted.
        top--;//Decrement the top value since the previous top item is removed
    }
}

int peek(int la[])
{

    if (top == -1)
    {
        printf("Underflow\n\n");
        return 0;
    }
    else
    {
        printf("The top element is "
               "%d"
               "\n\n",
               la[top]);
        return la[top];
    }
}

void display(int la[])
{

    if (top >= 0)
    {
        printf("Stack : ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", la[i]);
        }
        printf("\n\n");
    }
    else
    {
        printf("The stack is empty.\n\n");
    }
}

int main()
{

    int stack[100];
    int m;
    printf("Enter the no. of elements in the stack (1 - 100) : ");
    scanf(" %d", &m);
    printf("\n");

    int a = 0;
    while (a < 1)
    {
        int response;
        printf("Stack Operations : Push = 1  Pop = 2  Peek = 3  Display = 4  End = 5\n\n");
        printf("Enter your choice = ");
        scanf(" %d", &response);
        switch (response)
        {
        case 1:
        {
            push(stack, m);
            break;
        }

        case 2:
        {
            pop(stack);
            break;
        }

        case 3:
        {
            peek(stack);
            break;
        }

        case 4:
        {
            display(stack);
            break;
        }

        case 5:
        {
            a++;
            break;
        }

        default:
        {
            printf("Invalid input. Please try again.\n\n");
            break;
        }
        }
    }
    printf("\n");

    return 0;
}
