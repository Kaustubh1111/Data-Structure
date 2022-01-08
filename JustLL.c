#include<stdio.h>
#include<conio.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node1
{
    int data;
    struct Node* next;
};
struct Node2
{
    int data;
    struct Node* next;
};
struct Node3
{
    int data;
    struct Node* next;
};
struct Node4
{
    int data;
    struct Node* next;
};
struct Node* head;
struct Node1* head1;
struct Node2* head2;
struct Node3* head3;
struct Node4* head4;
void push(int n)
{
    for(int i=1;i<=n;i++)
   {
       struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
       if(ptr == NULL)
            printf("Node Not Created");
        else
        {
            if(head == NULL)
            {
                ptr->data = i;
                ptr->next = NULL;
                head = ptr;
            }
            else
            {
                struct Node* temp= head;
                while(temp->next!=NULL)
                {
                    temp = temp->next;
                }
                ptr->data = i;
                ptr->next = NULL;
                temp->next = ptr;
            }
        }
   }
}
int change(struct Node* ptr,struct Node* head,int data)
{
    if(ptr == NULL)
            printf("Node Not Created");
        else
        {
            if(head == NULL)
            {
                ptr->data = data;
                ptr->next = NULL;
                return 0;
            }
            else
            {
                struct Node* temp= head;
                while(temp->next!=NULL)
                {
                    temp = temp->next;
                }
                ptr->data = data;
                ptr->next = NULL;
                temp->next = ptr;
                return 1;
            }
        }
}
void show(struct Node* h)
{
        struct Node* temp = h;
        if(temp->next != NULL)
        {
            do{
            printf(" %d",temp->data);
            temp = temp->next;
            }while(temp->next != NULL);
            printf(" %d\n",temp->data);
        }
        else
        {
            printf(" %d\n",temp->data);
        }

}
void main()
{
    int n;
    printf("Enter Element: ");
    scanf("%d",&n);
    push(n);
    struct Node* temp = head;

    do{
        if((temp->data)%4 == 1)
        {
            struct Node1* ptr = (struct Node1*)malloc(sizeof(struct Node1));
            char r = change(ptr,head1,temp->data);
            if(r==0)
                head1 = ptr;
        }
        else if((temp->data)%4 == 2)
        {
            struct Node2* ptr = (struct Node2*)malloc(sizeof(struct Node2));
            int r = change(ptr,head2,temp->data);
            if(r==0)
                head2 = ptr;
        }
        else if((temp->data)%4 == 3)
        {
            struct Node3* ptr = (struct Node3*)malloc(sizeof(struct Node3));
            int r = change(ptr,head3,temp->data);
            if(r==0)
                head3 = ptr;

        }
        else if((temp->data)%4 == 0)
        {
            struct Node4* ptr = (struct Node4*)malloc(sizeof(struct Node4));
            int r = change(ptr,head4,temp->data);
            if(r==0)
                head4 = ptr;
        }
        temp =temp->next;
    }while(temp->next != NULL);
    printf("\n 1.  \n");
    show(head1);
    printf("\n 2. \n");
    show(head2);
    printf("\n 3. \n");
    show(head3);
    printf("\n 4. \n");
    show(head4);

}

