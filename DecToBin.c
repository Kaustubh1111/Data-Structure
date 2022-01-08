#include<stdio.h>
#include<conio.h>
void main(){
    int num,a[10],i,bin[10],t;
    printf("Enter Number: ");
    scanf("%d",&num);

    t=num;
    for(i=0;num>0;i++)
    {
        a[i]=num%2;
        num=num/2;
    }
    printf("Binary of %d is: ",t);
    for(int j=i-1;j>=0;j--)
    {
        printf("%d",a[j]);
    }
    getch();
}
