#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
       int info;
       struct node* next;
};

typedef struct node* N;
N gp;

N getnode(int ele)
{
           N temp;
           temp=(N) malloc (sizeof(struct node));
           if(temp==NULL)
           {
                         printf("memory full");return;
           }
           temp->info=ele;
           temp->next=NULL;
           return temp;
}

void display(N h)
{
     N temp;
     if(h==NULL)
     {
                printf("empty linked list");
                return;
     }
     temp=h;
     while(temp!=NULL)
     {                printf("%d\t  ",temp->info);
                      temp=temp->next;
     }
}

N createlist(N p)
{
               N temp;
               if(p==NULL)
               {
                          p=gp;gp=gp->next;
                          p->next=NULL;
                          return p;
               }
               else
               {
                   temp=p;
                   while(temp->next!=NULL)
                                       temp=temp->next;
                   temp->next=gp;
                   gp=gp->next;
                   (temp->next)->next=NULL;
                   return p;
               }
}
                          
                          
int main()
{
    N head,p,h1,h2,h3,h4,temp;
    head=h1=h2=h3=h4=NULL;
    temp=head;
    int i,n,mod;
    printf("enter no of nodes");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
                     p=getnode(i);
                     if(head==NULL)
                     {
                                   head=p;
                     }
                     else
                     {
                         temp=head;
                         
                        while(temp->next!=NULL)
                                         temp=temp->next; 
                        temp->next=p;
                     }
    }
    gp=head;
    for(i=1;i<=n;i++)
    {
                     mod=i%4;
                     switch(mod)
                     {
                                case 1:h1=createlist(h1);break;
                                case 2:h2=createlist(h2);break;
                                case 3:h3=createlist(h3);break;
                                case 0:h4=createlist(h4);break; 
                                default:printf("");
                     }
    }
    printf("\n");
    display(h1);printf("\n");
    display(h2);printf("\n"); 
    display(h3);printf("\n"); 
    display(h4);                                
    getch();
    return 0;
}       
