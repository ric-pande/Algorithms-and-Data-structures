#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
       int info;
       struct node* next;
};

typedef struct node* N;

N getnode(int ele)
{
              N temp;
              temp=(N) malloc(sizeof(struct node));
              temp->info=ele;
              temp->next=temp;
              return temp;
}

void freenode(N p)
{
     free(p);
     return;
}

void addfront(N h,int ele)
{
     N temp;
     temp=NULL;
     if(h==NULL)
     {printf("working1");
                   h=getnode(ele);return;
     }
    temp=getnode(ele);
    printf("working2");     temp->next=h->next;
     h->next=temp;
     h=temp;
}

void display(N head)
{
     N temp;
     temp=NULL;
     
     if(head==NULL)
     {
                   printf("empty list");
                   return;
     }
     temp=head->next;
     while(temp!=head)
     {
                   printf("%d ",temp->info);
                   temp=temp->next;
     }
     printf("%d ",temp->info);
     return;
}

int main()
{
    int ele,ch;
    N head;
    head=NULL;
    while(1)
    {
            printf("enter choice \n 1. Insert front\n2.display\n");
            scanf("%d",&ch);
            switch(ch)
            {
                      case 1:printf(" enter element to be inserted");
                             scanf("%d",&ele);
                             addfront(head,ele);break;
                      case 2:display(head);break;
                      default: printf("enter valid choice");
            }
    }
    getch();
    return 0;
}
                                                     
     
