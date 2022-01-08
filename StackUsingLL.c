#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int val;void push()
{
    int val;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("can not create node");
    }
    else
    {
        printf("Enter the value");
        scanf("%d",&val);
        if(top==NULL)
        {
            ptr->val=val;
            ptr->next=NULL;
            top=ptr;
        }
        else
        {
            ptr->val=val;
            ptr->next=top;
            top=ptr;

        }
        printf("%d pushed.",val);
    }
}
    struct Node* next;
};
struct node* top;
struct node* top;



void pop()
{
    int item;
    struct node *ptr;
    if (top==NULL)
    {
        printf("Underflow");
    }
    else
    {
        item=top->val;
        ptr=top;
        top=top->next;
        free(ptr);
        printf("%d popped",item);

    }
}
void show()
{
    struct node *ptr;
    ptr=top;
    if(ptr==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d - ",ptr->val);
            ptr=ptr->next;
        }
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("\n1. push\n");
        printf("2. pop\n");
        printf("3. display\n");
        printf("4. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                break;
            case 2:pop();
                break;
            case 3:show();
                break;
            case 4: exit(1);
        }
    }
}
