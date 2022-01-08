#include<stdio.h>
#include<conio.h>
struct node1
{
    int power1;
    int value1;
    struct node1* next1;
};
struct node2
{
    int power2;
    int value2;
    struct node2* next2;
};
struct node1* head1;
struct node2* head2;
void insert1()
{
    int ch=0;
    do
    {
        printf("\n\nEnter 1 For Continue, 0 For Exit");
        printf("\nEnter Choice :- ");
        scanf("%d",&ch);
        if(ch)
        {
            struct node1* ptr = (struct node1*)malloc(sizeof(struct node1));
            if(ptr== NULL)
                printf("Node Not Created");
            else
            {
                int value,power;
                printf("Enter Value :- ");
                scanf("%d",&value);
                printf("Enter Power :- ");
                scanf("%d",&power);
                ptr->power1 = power;
                ptr->value1 = value;
                ptr->next1 = NULL;
                if(head1 == NULL)
                    head1 = ptr;
                else
                {
                    struct node1* temp = head1;
                    while(temp->next1 != NULL)
                        temp = temp->next1;
                    temp->next1 = ptr;
                }
            }
        }
    }while(ch !=0);
}
void insert2()
{
    int ch=0;
    do
    {
        printf("\n\nEnter 1 For Continue, 0 For Exit");
        printf("\nEnter Choice :- ");
        scanf("%d",&ch);
        if(ch)
        {
            struct node2* ptr = (struct node2*)malloc(sizeof(struct node2));
            if(ptr== NULL)
                printf("Node Not Created");
            else
            {
                int value,power;
                printf("Enter Value :- ");
                scanf("%d",&value);
                printf("Enter Power :- ");
                scanf("%d",&power);
                ptr->power2 = power;
                ptr->value2 = value;
                ptr->next2 = NULL;
                if(head2 == NULL)
                    head2 = ptr;
                else
                {
                    struct node2* temp = head2;
                    while(temp->next2 != NULL)
                        temp = temp->next2;
                    temp->next2 = ptr;
                }
            }
        }
    }while(ch !=0);
}
void show1()
{
    if(head1 == NULL)
        printf("No Data");
    else
    {
        struct node1* temp = head1;
        while(temp->next1 != NULL)
        {
            printf("%dx^%d + ",temp->value1,temp->power1);
            temp = temp->next1;
        }
        printf("%dx^%d",temp->value1,temp->power1);

    }
}
void show2()
{
    if(head2 == NULL)
        printf("No Data");
    else
    {
        struct node2* temp = head2;
        while(temp->next2 != NULL)
        {
            printf("%dx^%d + ",temp->value2,temp->power2);
            temp = temp->next2;
        }
        printf("%dx^%d",temp->value2,temp->power2);

    }
}
void sum()
{
   if(head1 == NULL)
        show2();
    else if(head2 == NULL)
        show1();
    else
    {
        struct node1* temp1 = head1;
        struct node2* temp2 = head2;
        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1->power1 == temp2->power2)
            {
                printf("%dx^%d + ",temp1->value1+temp2->value2,temp2->power2);
                temp1 = temp1->next1;
                temp2 = temp2->next2;
            }

            else if(temp1->power1 > temp2->power2)
            {
                while(temp1 != NULL && temp1->power1 > temp2->power2)
                {
                    printf("%dx^%d + ",temp1->value1,temp1->power1);
                    temp1 = temp1->next1;
                }            }
            else if(temp1->power1 < temp2->power2)
            {
                while(temp2 != NULL  && temp1->power1 < temp2->power2 )
                {
                    printf("%dx^%d + ",temp2->value2,temp2->power2);
                    temp2 = temp2->next2;
                }
            }
        }
        if(temp1 != NULL)
        {   while(temp1->next1 != NULL)
            {
                printf("%dx^%d + ",temp1->value1,temp1->power1);
                temp1 = temp1->next1;
            }
            printf("%dx^%d",temp1->value1,temp1->power1);
        }
        else if(temp2 != NULL)
        {
            while(temp2->next2 != NULL)
            {
                printf("%dx^%d + ",temp2->value2,temp2->power2);
                temp2 = temp2->next2;
            }
            printf("%dx^%d",temp2->value2,temp2->power2);
        }

    }
}
void main()
{
    printf("----- Enter First Equation -----");
    insert1();
    printf("\n\n----- Enter Second Equation -----");
    insert2();

    printf("\n\nFirst Equation :- ");
    show1();
    printf("\nSecond Equation :- ");
    show2();

    printf("\n\nAddition :- ");
    sum();
    printf("\n\n");
    getch();
}
