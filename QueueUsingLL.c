#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;

void enqueue()
{
    struct node *ptr;
    int item;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("can not creat newnode");
        return;
    }
    else
    {
        printf("Enter value: ");
        scanf("%d",&item);
        ptr->data=item;
        if(front==NULL)
        {
            front=ptr;
            rear=ptr;
            front->next=NULL;
            rear->next=NULL;
        }
        else
        {
            rear->next=ptr;
            rear=ptr;
            rear->next=NULL;
        }
    }
}
void dequeue()
{
    struct node *ptr;
    if(front==NULL)
    {
        printf("underflow");
        return;
    }
    else
    {
        ptr=front;
        front=front->next;
        free(ptr);
    }
}

void show()
{
    struct node *ptr;
    ptr=front;
    if(front==NULL)
    {
        printf("Empty queue");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d - ",ptr->data);
            ptr=ptr->next;
        }
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1. Enqueue\n");
        printf("2. dequeue\n");
        printf("3. display\n");
        printf("4. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue();
                break;
            case 2:dequeue();
                break;
            case 3:show();
                break;
            case 4: exit(1);
        }
    }
}
