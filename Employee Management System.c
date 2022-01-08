#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(){
    FILE *fp, *ft;
    char another, choice;

    struct emp{
        char name[40];
        int age;
        int id;
        char gender[20];
    };

    struct emp e;
    int empid;
    long int recsize;

    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL){
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL){
            printf("Connot open file");
            exit(1);
        }
    }

    recsize = sizeof(e);

    while(1){
        printf("\n1. Add Record\n");
        printf("2. List Records\n");
        printf("3. Modify Records\n");
        printf("4. Delete Records\n");
        printf("5. Exit\n");
        printf("Your Choice: ");
        fflush(stdin);
        scanf("\n%c", &choice);
        switch(choice){
            case '1':
                fseek(fp,0,SEEK_END);

                another = 'y';
                while(another == 'y'){
                    flush();
                    printf("\nEnter name: ");
                    gets(e.name);

                    printf("\nEnter ID: ");
                    scanf("%d", &e.id);

                    printf("\nEnter age: ");
                    scanf("%d", &e.age);

                    printf("\nEnter gender: ");
                    flush();
                    gets(e.gender);

                    fwrite(&e,recsize,1,fp);
                    printf("\nAdd another record(y/n) ");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
                break;
            case '2':
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1){
                    printf("\n%d-%s-%d-%s\n",e.id,e.name,e.age,e.gender);
                }
                break;

            case '3':
                another = 'y';
                while(another == 'y'){
                    printf("Enter the employee ID to modify: ");
                    scanf("%d", &empid);
                    printf("%d",empid);
                    rewind(fp);
                    while(fread(&e,recsize,1,fp)==1){
                        if(e.id==empid){
                            printf("\nEnter new ID: ");
                            scanf("%d",&e.id);
                            printf("\nEnter new Name: ");
                            scanf("%s",e.name);
                            printf("\nEnter new age: ");
                            scanf("%d",&e.age);
                            printf("\nEnter new Gender: ");
                            scanf("%s",&e.gender);
                            fseek(fp,-recsize,SEEK_CUR);
                            fwrite(&e,recsize,1,fp);
                            break;
                        }
                    }
                    printf("\nModify another record(y/n)");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
                break;
            case '4':
                another = 'y';
                while(another == 'y'){
                    flush();
                    printf("\nEnter ID of employee to delete: ");
                    scanf("%d",&empid);

                    ft = fopen("Temp.DAT","wb");
                    rewind(fp);
                    while(fread(&e,recsize,1,fp) == 1){
                        if(e.id!=empid){
                            fwrite(&e,recsize,1,ft);
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    if(remove("EMP.DAT")==0)
                    {
                        rename("Temp.DAT","EMP.DAT");
                        fp = fopen("EMP.DAT", "rb+");
                    }
                    printf("Delete another record(y/n)");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
                break;
            case '5':
                fclose(fp);
                exit(0);
        }
    }
    return 0;
}
