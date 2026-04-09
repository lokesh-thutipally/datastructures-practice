#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

/* Function Prototypes */

void push();
void pop();
void peek();
void traverse();

/* Main Function */

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);


        switch(choice)
        {
            case 1: push();
                    break;

            case 2: pop();
                    break;

            case 3: peek();
                    break;

            case 4: traverse();
                    break;

            case 5: exit(0);

            default: printf("Invalid choice\n");
        }
    }

    return 0;
}

/* Push Operation */

void push()
{
    int value;

    if(top == MAX-1)
    {
        printf("Stack Overflow \n");
        return;
    }

    printf("Enter value to push: ");
    scanf("%d",&value);

    top = top + 1;
    stack[top] = value;

    printf("Element inserted\n");
}

/* Pop Operation */

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Deleted element is %d\n",stack[top]);
    top = top - 1;
}

/* Peek Operation */

void peek()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element is %d\n",stack[top]);
}

/* Traverse Stack */

void traverse()
{
    int i;

    if(top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");

    for(i = top; i >= 0; i--)
    {
        printf("%d\n",stack[i]);
    }
}
