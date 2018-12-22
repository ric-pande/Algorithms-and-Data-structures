#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
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
           temp=(N)malloc(sizeof(struct node));
           temp->info=ele;
           temp->next=NULL;
           return temp;
}

void createlist(N h)
{
            N temp,p;
            printf("enter -1 to exit");
            while(1)
            {
                    printf("enter element");
                    scanf("%d",&ele);
                    if(ele!=-1)
                    {
                               temp=getnode(ele);
                               if(h==NULL)
                                          h=temp;
                               else
                               {
                                   p=h;
                                   while(p->next!=NULL)
                                               p=p->next;
                                   p->next=temp;
                               }
                    }
                    else
                    {
                        return h;
                    }
            }
}
                               
void commonele(N h1,N h2)
{
     N t1,t2;
     int flag=0;
     t1=h1;
     while(t1!=NULL)
     {
                    t2=h2;
                    while(t2!=NULL)
                    {              if(t1->info==t2->info)
                                   {
                                                         printf("%d",t1->info);
                                                         flag=1;
                                   }
                                   t2=t2->next;
                    }
                    t1=t1->next;
     }
     if(flag==0)
                printf("no common element");
                
}

int main()
{
    N h1,h2;
    h1=h2=NULL;
    printf("creating sll1");
    createlist(h1);
    printf("creating sll2");
    createlist(h2);
    commonele(h1,h2);
    getch();
    return 0;
}
