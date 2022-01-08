#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* head;
void reverse()
{
    struct node* current=head;
    struct node *prev=NULL,*next=NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void insert()
{
    int d;
    printf("Enter data: ");
    scanf("%d",&d);
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=head;
    head=temp;
}
void show()
{
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d |",temp->data);
        temp = temp->next;
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1. Insert\n");
        printf("2. Show\n");
        printf("3. Reverse\n");
        printf("4. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                break;
            case 2:show();
                break;
            case 3:reverse();
                break;
            case 4: exit(1);
        }
    }
}

