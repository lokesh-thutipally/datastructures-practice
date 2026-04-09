#include <stdio.h>
#include <stdlib.h>

/* Definition of Node */
struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

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
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value to push: ");
    scanf("%d",&value);

    newnode->data = value;
    newnode->next = top;
    top = newnode;

    printf("Element inserted\n");
}

/* Pop Operation */

void pop()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Deleted element is %d\n", top->data);

    top = top->next;
    free(temp);
}

/* Peek Operation */

void peek()
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element is %d\n", top->data);
}

/* Traverse Stack */

void traverse()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    temp = top;

    printf("Stack elements are:\n");

    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
