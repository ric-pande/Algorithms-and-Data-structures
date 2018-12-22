#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct node
{
       char name[20];
       long int num;
       char add[40];
       struct node* next;
};

typedef struct node* N;

N getnode(char nm[20],long int n,char addr[40])
{
           N temp;
           temp=(N) malloc (sizeof(struct node));
           strcpy(temp->name,nm);
           temp->num=n;
           strcpy(temp->add,addr);
           temp->next=NULL;
           return temp;
}

void freenode(N h)
{
     free(h);
}
N createContact(N h)
{
               N temp,q;
               temp=NULL;
               int i;
               char nm[20],addr[40];
               long int n;
               printf("enter name: ");
               scanf("%s",nm);
               printf("enter number: ");
               scanf("%d",&n);
               printf("enter address: ");
               scanf("%s",addr);
               q=getnode(nm,n,addr);
               
               if(h==NULL)
               {
                         
                          h=q;
                          return h;
               }
               temp=h;
               while(temp->next!=NULL)
                          temp=temp->next;
               temp->next=q;
               return h;
}

void search(char a[20],N h)
{
     N temp;
     int x=1,i;
     if(h==NULL)
     {
                printf("no contacts entered");
                return;
     }
     temp=h;
     if(temp->next==NULL)
     {
                         x=strcmp(a,temp->name);
                         if(x==0)
                         {
                                 printf("contact found\n");
                                 printf("%d  %s",temp->num,temp->add);
                         }
                         else
                         {
                             printf("contact not found");
                             return;
                         }
     }
     else
     {
         while(temp!=NULL)
         {
                      x=strcmp(a,temp->name);
                         if(x==0)
                         {
                                 printf("contact found\n");
                                 printf("%d  %s",temp->num,temp->add);return;
                         } 
                         temp=temp->next;    
         }
         printf("contact not found");
     }
}

void delete(char a[20],N h)
{
     N temp,p;
     int x=1,i;
     if(h==NULL)
     {
                printf("no contacts entered");
                return;
     }
     temp=p=h;
     if(temp->next==NULL)
     {
                         x=strcmp(a,temp->name);
                         if(x==0)
                         {
                                 printf("contact  found and deleted\n");
                                 freenode(temp);
                                 h=NULL;
                         }
                         else
                         {
                             printf("contact not found");
                             return;
                         }
     }
     else
     {
         while(temp!=NULL)
         {
                      p=temp->next;
                      x=strcmp(a,temp->name);
                         if(x==0)
                         {
                                 printf("contact found and deleted\n");
                                 h->next=p;
                                 freenode(temp);
                                 return;
                         } 
                         temp=temp->next;    
         }
         printf("contact not found");
     }
}

void modify(char a[20],N h)
{
     N temp;
     int x=1,i;
     if(h==NULL)
     {
                printf("no contacts entered");
                return;
     }
     temp=h;
     if(temp->next==NULL)
     {
                         x=strcmp(a,temp->name);
                         if(x==0)
                         {
                                 printf("contact found\n");
                                 printf("Enter new number");
                                 scanf("%d",&temp->num);
                                 printf("enter new address");
                                 scanf("%s",temp->add);
                                 printf("contact modified");
                                 printf("%s %d %s",temp->name,temp->num,temp->add);
                                 return;
                         }
                         else
                         {
                             printf("contact not found");
                             return;
                         }
     }
     else
     {
         while(temp!=NULL)
         {
                      x=strcmp(a,temp->name);
                         if(x==0)
                         {
                                 printf("contact found\n");
                                 printf("Enter new number");
                                 scanf("%d",&temp->num);
                                 printf("enter new address");
                                 scanf("%s",temp->add);
                                 printf("contact modified");
                                 printf("%s %d %s",temp->name,temp->num,temp->add);
                                 return;
                         } 
                         temp=temp->next;    
         }
         printf("contact not found");
     }
}
     
void display(N h)
{
     N temp;
     if(h==NULL)
     {
                printf("No contacts entered");
                return;
     }
     temp=h;
     printf("   NAME      NUMBER     ADDRESS\n");
     while(temp!=NULL)
     {                printf("  %4s     %3d     %3s\n",temp->name,temp->num,temp->add);
                      temp=temp->next;
     }
}

int main()
{
    int ch;char n[20];
    N head=NULL;
    while(1)
    {
            printf("\nenter \n1. Creating contact \n2. Searching contact \n3. Deleting contact\n4. Modifying contacts\n5. Displaying all contacts \n");
            scanf("%d",&ch);
            switch(ch)
            {
                      case 1: head=createContact(head);
                              break;
                      case 2: printf("enter name");
                              scanf("%s",n);
                              search(n,head);
                              break;
                      case 3: printf("enter name");
                              scanf("%s",n);
                              delete(n,head);
                              break;
                      case 4: printf("enter name");
                              scanf("%s",n);
                              modify(n,head);
                              break;
                      case 5: display(head);
                              break;
                              
                      default: printf("enter correct choice");
            }
    }
    getch();
    return 0;
}       
