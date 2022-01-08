#include<stdio.h>
#include<conio.h>
#include<string.h>
int TOP=-1;
char st[100];
char user[100];

int push(char s[])
{
    if(TOP==strlen(user))
    {
        return 0;
    }

    for(int i=0;i<strlen(user);i++)
    {
        TOP++;
        st[TOP]=user[i];
    }
    return 1;
}
void pop()
{
    if(TOP==-1){
        printf("Stack Underflow.");
    }
    printf("%c",st[TOP]);
    TOP--;
}
void main()
{
    printf("Enter String:");
    gets(user);

    if(push(user)==0)
    {
        printf("Stack Overflow");
    }
    printf("Reverse string(using stack) is: ");
    while(TOP!=-1)
    {
        pop();
    }

}
