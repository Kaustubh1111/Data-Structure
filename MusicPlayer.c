#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<windows.h>

struct node
{
    char musicName[100];
    int key;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *current = NULL;
int hKey;

void main()
{
    char m[]="music.mp3";
    char t[100];
    char an[100];
    int ch;
    int key,time,stop;
    char musicName[100];
    char c[]="start ";

    while(1)
    {
        printf("\n----- Music Player -----");
        printf("\n1. Insert Music\n");
        printf("2. Show Music\n");
        printf("3. Find Music\n");
        printf("4. Delete Music\n");
        printf("5. Play specific music\n");
        printf("6. Autoplay\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter Key: ");
            scanf("%d",&key);
            printf("Enter music name: ");
            scanf("%s",musicName);
            insert(key,musicName);
            break;
        case 2:
            printList();
            break;
        case 3:
            printf("Enter music name: ");
            scanf("%s",&key);
            find(key);
            break;
        case 4:
            printf("Enter Key: ");
            scanf("%d",&key);
            delete(key);
            break;
        case 5:
            printf("Enter music: ");
            scanf("%s",&key);
            play(key);
            break;
        case 6:
            printf("After ow many second autoplay next music: ");
            scanf("%d",&time);
            printf("After ow many second you want to stop autoplay next music: ");
            scanf("%d",&stop);

            autoplay(1,time,stop);
            break;
        case 7:
            exit(0);
        }
    }
}

void find(int key)
{
    struct node* current = head;
    if(head==NULL)
    {
        printf("Music not found.");
    }
    while(current->musicName!=key)
    {
        printf("a");
            current=current->next;
            if(current != head)
                break;
    }
    char t[100];
    if(current != NULL)
    {
        printf("Music found\n");
        strcpy(t,current->musicName);
        printf("| No. |  Music name |\n");
        printf("|   | %s |\n",current->musicName);
        printf("\n");
    }
    else
    {
        printf("Music not found.");
    }
}

void delete(int key)
{
    struct node *nodeToDelete=head;
    struct node *temp=head;
    int NoOfElements=0;

    if(temp!=NULL)
    {
        NoOfElements++;
        temp=temp->next;
    }
    while(temp!=head)
    {
        NoOfElements++;
        temp=temp->next;
    }

    if(key<1 || key>NoOfElements)
    {
        printf("\nInavalid position.");
    }
    else if (key==1)
    {

        if(head->next==head)
        {
            head=NULL;
        }
        else
        {
            while(temp->next !=head)
                temp = temp->next;
            head=head->next;
            temp->next=head;
            head->prev = temp;
            free(nodeToDelete);
        }
    }
    else
    {
        temp=head;
        for(int i = 1; i <key-1; i++)
            temp = temp->next;
        nodeToDelete = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        free(nodeToDelete);
    }
}

void printList()
{
    struct node *temp = head;

    printf("| No. | Music name |\n");
    while (temp->next != head)
    {
        printf("| %2d  | %s |\n",temp->key,temp->musicName);
        temp = temp->next;
    }
    printf("| %2d  | %s |\n",temp->key,temp->musicName);

}

void play(int key)
{
    struct node* current = head;
    if(head==NULL)
    {
        return NULL;
    }
    while(current->key != key)
    {
        if(current->next==NULL)
        {
            return NULL;
        }
        else
        {
            current=current->next;
        }
    }
    char t[100];
    char c[]="start ";

    int tem=0;
    int replay;
    if(current != NULL){
        if(current == current->next){
            tem=1;
            printf("Music running..\n");
            strcpy(t,current->musicName);
            strcpy(c,t);
            printf("| No. |  Music name |\n");
            printf("| %2d  | %s |\n",current->key,current->musicName);
            system(c);
            printf("\nThere is only one music. Do you want to replay it?(1,YES,0=No) ");
            scanf("%d",&replay);
            if(replay==1){
                play(key);
            }
        }
    }

    if(current != current->next && tem==0)
    {
        printf("Music running..\n");
        strcpy(t,current->musicName);
        strcpy(c,t);
        printf("| No. |  Music name |\n");
        printf("| %2d | %s |\n",current->key,current->musicName);
        system(c);
        sleep(5);
        int choice;
        printf("\n1. Play Next");
        printf("\n2. Play Previous");
        printf("\n3. Exit from playing music\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            play(current->next->key);
        }
        else if(choice==2)
        {
            play(current->prev->key);
        }
        else if(choice==3)
        {
            printf("\n");
        }

        printf("\n");
    }
    else
    {
        printf("Music not found.");
    }
}

void autoplay(int key,int time,int stop)
{
    struct node* current = head;
    if(head==NULL)
    {
        return NULL;
    }
    while(current->key!=key)
    {
        if(current->next==NULL)
        {
            return NULL;
        }
        else
        {
            current = current->next;
        }
    }
    char t[100];
    char c[]="start ";
    int tem=0;
    if(current != NULL){
        if(current == current->next){
            tem=1;
            printf("Music running..\n");
            strcpy(t,current->musicName);
            strcpy(c,t);
            printf("| No. |  Music name |\n");
            printf("| %2d  | %s |\n",current->key,current->musicName);
            system(c);
            stop-=time;
            if(stop<=0)
            {
                printf("\nAutoplay stopped.\n");
            }
            else
            {
                sleep(time);
                autoplay(current->next->key,time,stop);
            }
        }
    }

    if(current != current->next && tem==0)
    {
        printf("Music running..\n");
        strcpy(t,current->musicName);
        strcpy(c,t);
        printf("| No. |  Music name |\n");
        printf("| %2d  | %s |\n",current->key,current->musicName);
        system(c);
        stop-=time;
        if(stop<=0)
        {
            printf("\nAutoplay stopped.\n");
        }
        else
        {
            sleep(time);
            autoplay(current->next->key,time,stop);
        }
    }
    else
    {
        printf("Music not found.");
    }
}

void insert(int k, char music[])
{
    struct node *ptr,*temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        strcpy(ptr->musicName,music);
        ptr->key=k;
        if(head==NULL)
        {
            head=ptr;
            ptr->next=head;
            ptr->prev=head;
        }
        else
        {
            temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->prev =temp;
            head->prev=ptr;
            ptr->next=head;
            head=ptr;
        }
        hKey=ptr->key;
        printf("\nMusic inserted\n");
    }
}
