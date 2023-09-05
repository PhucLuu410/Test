#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Contact_list
{
    char name[50];
    char phone[50];
    char addr[100];
};

void AddContact(FILE *f,struct Contact_list contact)
{
    fprintf(f,"%s\n%s\n%s\n",&contact.name,&contact.phone,&contact.addr);
}

void DisplayContact(FILE *f,struct Contact_list contact)
{
    printf("Contact list:\n");
    rewind(f);
    while(fscanf(f," %[^\n]%[^\n]%[^\n]",contact.name,contact.phone,contact.addr) != EOF)
    {
        printf("%s\n%s\n%s\n",contact.name,contact.phone,contact.addr);
    }
}

void Findcontact(FILE *f,struct Contact_list contact,char *input)
{
    while(fscanf(f," %[^\n]%[^\n]%[^\n]",contact.name,contact.phone,contact.addr) != EOF)
    {
        if(strcmp(contact.name,input)==0)
        {
            printf("%s\n%s\n%s\n",contact.name,contact.phone,contact.addr);
        }
    }
}
int main()
{
    struct Contact_list cl;
    char choice;
    printf("Choice:");
    scanf("%s",&choice);
    FILE *f;
    f=fopen("ContactList.txt","a+");
    if(f==NULL)
    {
        printf("Cannot open file!");
        return 1;
    }
    switch (choice)
    {
        case '1':
        printf("Name:");
        scanf("%s",&cl.name);
        printf("Phone number:");
        scanf("%s",&cl.phone);
        printf("Address:");
        scanf("%s",&cl.addr);
        AddContact(f,cl);
        printf("Contact add successfully!\n");
        break;

        case '2':
        DisplayContact(f,cl);
        fclose(f);
        break;

        case '3':
        char input[50];
        printf("Name:");
        scanf("%s",&input);
        Findcontact(f,cl,input);
        break;

        case '4':
        break;
    }
}