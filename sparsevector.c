#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
       int index,value;
       struct node *next;
};

typedef struct node* N;

N getnode(int i,int v)
{
              N temp;
              temp=(N)malloc(sizeof(struct node));
              temp->index=i;
              temp->value=v;
              temp->next=temp;
              return temp;
}

void displaylist(N head)
{
     N temp;
     temp=NULL;
     if(head==NULL)
     {
                   printf("\nempty linked list\n");return;
     }
     temp=head->next;
     printf("index  value\n");
     while(temp!=head)
     {
                      printf("%d  %d\n",temp->index,temp->value);
                      temp=temp->next;
     }
     printf("%d  %d\n",temp->index,temp->value);
}

void displayvector(int n,N head)
{
     int i;
     N temp;
     temp=head->next;
     for(i=0;i<n;i++)
     {
           if(temp->index==i)
           {
                             printf(" %d ",temp->value);
                             temp=temp->next;
           }
           else
               printf(" 0 ");
     }   
}       
                      
int main()
{
    int i,ele,n,cnt=0;
    N temp,head,p;
    temp=head=NULL;
    printf("enter the elements to be inserted");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
                    printf("enter element");
                    scanf("%d",&ele);
                    if(ele!=0)
                    {
                                 cnt++;
                                 temp=getnode(i,ele);
                                 if(head==NULL)
                                               head=temp;
                                 else
                                 {
                                     temp->next=head->next;
                                     head->next=temp;
                                     head=temp;
                                 }
                    }
    }
    
            if(cnt>0)
            {
             displaylist(head);
             displayvector(n,head);
             }
             else
             {displaylist(head);
              for(i=0;i<n;i++)
                              printf(" 0 ");
              }
    getch();
    return;
}                                   
