#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    char name[100];
    int id;
    char email[100];
    char cell[15];
    char blood[5];
    struct Node *next;
} student;
// inserting node in linked list
student* insert(student *head, char Name[], int Id, char Email[], char Cell[], char Blood[])
{
    student *newRecord = (student*)malloc(sizeof(student));
    strncpy(newRecord->name, Name, sizeof(newRecord->name));
    newRecord->id = Id;
    strncpy(newRecord->email, Email, sizeof(newRecord->email));
    strncpy(newRecord->cell, Cell, sizeof(newRecord->cell));
    strncpy(newRecord->blood, Blood, sizeof(newRecord->blood));
    newRecord->next = NULL;
    if (head == NULL)
    {
        head = newRecord;
    }
    else
    {
        student *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newRecord;
    }
    return head;
}

// print full linked list
void displayList(student *head)
{
    student *temp = head;
    while (temp != NULL)
    {
        printf("Name: %s\n", temp->name);
        printf("ID: %d\n", temp->id);
        printf("Email: %s\n", temp->email);
        printf("Cell: %s\n", temp->cell);
        printf("Blood Type: %s\n", temp->blood);
        printf("\n");
        temp = temp->next;
    }
}
//searching by blood type
void searchByBloodType(student *head,char sBlood[])
{
    student *temp=head;
    int f=0;
    while(temp!=NULL)
    {
        if(strcmp(temp->blood,sBlood)==0)
        {
            printf("Name = %s\n",temp->name);
            printf("Id = %d\n",temp->id);
            printf("Email = %s\n",temp->email);
            printf("Cell = %s\n",temp->cell);
            printf("Blood Type = %s\n",temp->blood);
            f=1;
        }
        temp=temp->next;
    }
    if(f==0)
    {
        printf("No students with %s bloof type is found\n",sBlood);
    }
}
//searching by name
void searchByName(student *head, char sName[])
{
    student *temp = head;
    int found = 0;
    while (temp != NULL)
    {
        if (strcmp(temp->name, sName) == 0)
        {
            printf("Name = %s\n",temp->name);
            printf("Id = %d\n",temp->id);
            printf("Email = %s\n",temp->email);
            printf("Cell = %s\n",temp->cell);
            printf("Blood Type = %s\n",temp->blood);
            found = 1;
        }
        temp = temp->next;
    }
    if (found==0)
    {
        printf("No students with Name %s found.\n", sName);
    }
}
// searching by ID
void searchById(student *head, int sID)
{
    student *temp = head;
    int found = 0;
    while (temp != NULL)
    {
        if (temp->id == sID)
        {
            printf("Name = %s\n",temp->name);
            printf("Id = %d\n",temp->id);
            printf("Email = %s\n",temp->email);
            printf("Cell = %s\n",temp->cell);
            printf("Blood Type = %s\n",temp->blood);
            found = 1;
        }
        temp = temp->next;
    }
    if (found==0)
    {
        printf("No students with ID %d found.\n", sID);
    }
}
int main()
{
    student *head = NULL;
    head=insert(head,"Sourov",5740,"01631899223","mhsourov@gmail","O+");
    head=insert(head,"Taifur",5750,"0166435783","taifur@gmail","A+");
    head=insert(head,"Turzo",5785,"016783423","turzo@gmail","B+");
    head=insert(head,"Shuvo",5428,"0174563223","shuvo@gmail","AB+");
    head=insert(head,"Nahid",5334,"0153547323","nahid@gmail","O+");
    head=insert(head,"Mahafuj",5448,"0153546323","mahafuj@gmail","A+");
    head=insert(head,"Emon",5557,"0193547323","emon@gmail","B-");
    int choice,searchId;
    char searchName[50],searchBlood[5];
    while (1)
    {
        printf("Menu:\n");
        printf("1. Search by Name\n");
        printf("2. Search by ID\n");
        printf("3. Search by blood group\n");
        printf("4. Show full list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the name to search: ");
            scanf("%s", searchName);
            searchByName(head, searchName);
            break;
        case 2:
            printf("Enter the ID to search: ");
            scanf("%d", &searchId);
            searchById(head, searchId);
            break;
        case 3:
        {
            printf("Enter Blood type to search:");
            scanf("%s",searchBlood);
            searchByBloodType(head,searchBlood);
            break;
        }
        case 4:
        {
            displayList(head);
            break;
        }
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
