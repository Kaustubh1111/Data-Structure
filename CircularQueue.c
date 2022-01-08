#include<stdio.h>
#include<conio.h>
int F=-1;
int R=-1;
int max;
int a[100];
int i=0;

void show()
{
    if(F==R){
        printf("%d",a[R]);
    }
    if(R>F)
    {
        for(int j=F;j<=R;j++)
        {
            printf("%d | ",a[j]);
        }
    }
    else{
        for(int j=F;j<max;j++)
        {
            printf("%d | ",a[j]);
        }
        for(int k=0;k<=R;k++)
        {
            printf("%d | ",a[k]);
        }
    }

    printf("\n");

}
void nQ()
{
    int e;
    if((F==R+1) || (F==0 && R==max-1))
    {
        printf("Queue Overflow");
    }
    else
    {
        if(F==-1 && R==-1)
        {
            printf("Enter Number: ");
            R=(R+1)%max;
            F=(F+1)%max;
            scanf("%d",&a[R]);
        }
        else{
            printf("Enter Number: ");
            R=(R+1)%max;
            scanf("%d",&a[R]);
        }
    }
}

void dQ()
{
    if(F==-1 && R==-1){
        printf("Queue Underflow");
    }
    else
    {
        if(F==R)
        {
            F=R=-1;
        }
        else
        {
            F=(F+1)%max;
        }
    }
}

void main()
{
    int ch;
    printf("Enter size of Queue: ");
    scanf("%d",&max);

    while(1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Show\n");
        printf("4. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:nQ();
                break;
            case 2:dQ();
                break;
            case 3: show();
                break;
            case 4: exit(0);
        }
    }
}
