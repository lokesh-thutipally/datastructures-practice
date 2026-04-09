#include <stdio.h>
#include <stdlib.h>
 
struct node
{
	int data;
	struct node *next;
};
 
struct node *front = NULL, *rear = NULL;
 
/* Function declarations */
void enqueue();
void dequeue();
void peek();
void display();
 
int main()
{
	int choice;
 
	while(1)
	{
    	printf("\n--- Queue Using Linked List ---\n");
        printf("1. Enqueue\n");
    	printf("2. Dequeue\n");
    	printf("3. Peek\n");
    	printf("4. Display\n");
    	printf("5. Exit\n");
    	printf("Enter your choice: ");
    	scanf("%d", &choice);
 
    	switch(choice)
    	{
        	case 1: enqueue(); break;
        	case 2: dequeue(); break;
        	case 3: peek(); break;
        	case 4: display(); break;
        	case 5: exit(0);
        	default: printf("Invalid choice\n");
    	}
	}
}
 
/* Enqueue operation */
void enqueue()
{
	struct node *ptr;
	int value;
 
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
    	printf("Queue Overflow\n");
    	return;
	}
 
	printf("Enter element to insert: ");
	scanf("%d", &value);
 
	ptr->data = value;
	ptr->next = NULL;
 
	if(rear == NULL)
	{
    	front = rear = ptr;
	}
	else
	{
    	rear->next = ptr;
    	rear = ptr;
	}
 
	printf("Element inserted successfully\n");
}
 
/* Dequeue operation */
void dequeue()
{
	struct node *temp;
 
	if(front == NULL)
	{
    	printf("Queue Underflow\n");
    	return;
	}
 
	temp = front;
	printf("Deleted element: %d\n", temp->data);
	front = front->next;
 
	if(front == NULL)
    	rear = NULL;
 
	free(temp);
}
 
/* Peek operation */
void peek()
{
	if(front == NULL)
	{
    	printf("Queue is empty\n");
    	return;
	}
 
	printf("Front element: %d\n", front->data);
}
 
/* Display operation */
void display()
{
	struct node *temp;
 
	if(front == NULL)
	{
    	printf("Queue is empty\n");
    	return;
	}
 
	temp = front;
	printf("Queue elements: ");
	while(temp != NULL)
	{
    	printf("%d ", temp->data);
    	temp = temp->next;
	}
	printf("\n");
}
