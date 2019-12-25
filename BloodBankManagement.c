#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>

char name[20];
char lastName[20];
char bloodGroup[20];
char contactNumber[20];

void display()
{
    printf("\n\t\tBlood Bank Management\n");
    printf("\t\t---------------------\n");

}

void mainMenu()
{
    char ch='-1';

   while(1)
   {
    printf("\n\t\tMain Menu:\n");
    printf("\n\t\t**************\n");
    printf("\t\t1.Add new person\n");
    printf("\t\t2.Search blood group\n");
    printf("\t\t3.Exit\n");
    printf("\t\tPlease enter your choice:");
    fflush(stdin);
    scanf("%c",&ch);

    switch(ch)
    {
        case '1':addNewPerson();break;
        case '2':searchBloodGroup();break;
        case '3':exit(1);
       default:printf("\t\tSorry,invalid choice...!\n");
    }
   }
}

//add person
void addNewPerson(){

    printf("\n\t\tEnter your name:");
    fflush(stdin);
    gets(name);

    printf("\n\t\tEnter your blood group:");
    fflush(stdin);
    gets(bloodGroup);

    printf("\n\t\tEnter your contact number:");
    fflush(stdin);
    gets(contactNumber);

    FILE *fp;

    fp=fopen("record.txt","a");

    fprintf(fp,"%s %s %s\n",name,bloodGroup,contactNumber);
    printf("\n\t\tSuccessfully saved your information...!\n");
    fclose(fp);
}
//searching
void searchBloodGroup()
{

    char searchBloodGroup[20];

    printf("\n\t\tEnter your blood group:");
    fflush(stdin);
    gets(searchBloodGroup);

    FILE *fp;

    fp=fopen("record.txt","r");

    int count=0;

    printf("\n\t\tResult Of Search:\n");
    printf("\n\t\t*****************\n");


    while(fscanf(fp,"%s %s %s %s",&name,&lastName,&bloodGroup,&contactNumber)!=EOF)
    {

        if(strcmp(searchBloodGroup,bloodGroup)==0)
        {
            count++;
            printf("\t\tName: %s %s\n",name,lastName);
            printf("\t\tBlood Group: %s\n",bloodGroup);
            printf("\t\tContact Number: %s\n",contactNumber);
        }

    }

    fclose(fp);

    if(count==0)
        printf("\n\t\tSorry,not found...!\n\n");

}

int main()
{
    display();
    char pas[32]="diuswe";
    char password[32];
    char ch;
    int i;

    logIn:
    printf("\n\t\tLogin System\n");
    printf("\t\tPlease enter your password:");
    fflush(stdin);

    for(i=0;i<32;i++)
    {
       ch=getch();
       if(ch==13)
        break;
       else
       {
           password[i]=ch;
           printf("*");
       }
    }

    if(strcmp(password,pas)==1)
    {
        printf("\n\n\t\tLogin successful...!\n");
        mainMenu();
    }
    else
        goto logIn;
}
