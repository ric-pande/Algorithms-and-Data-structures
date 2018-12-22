#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
       int row,column,value;
       struct node *next;
       struct node *prev; 
};

typedef struct node* N;

N getnode(int r,int c,int v)
{
              N temp;
              temp=(N)malloc(sizeof(struct node));
              temp->row=r;
              temp->column=c;
              temp->value=v;
              temp->next=temp;
              temp->prev=temp;
              return temp;
}

void displaylist(N head)
{
     N temp;
     temp=NULL;
     if(head==NULL)
     {
                   printf("list empty\n");
                   return;
     }
     
     
     printf(" row  column  value \n");
      printf(" %d    %d    %d\n",head->row,head->column,head->value);
      temp=head->next;
     while(temp!=head)
     {
                      printf(" %d    %d    %d\n",temp->row,temp->column,temp->value);
                      temp=temp->next;
     }
    
     return;
}

void displaymatrix(int r,int c,N head)
{
     int i,j;
     N temp;
     temp=head;
     for(i=0;i<r;i++)
     {
                    for(j=0;j<c;j++)
                    {
                                    if((temp->row==i)&&(temp->column==j))
                                    {
                                                                     printf("%d",temp->value);
                                                                     temp=temp->next;
                                    }
                                    else
                                        printf(" 0 ");
                                    
                    }
                    printf("\n");
     }
                                                                  
                              
}

int main()
{
    int r,c,i,j,ele,cnt=0;
    N head,temp,t;
    head=temp=t=NULL;
    printf("enter no. of rows");
    scanf("%d",&r);
    printf("enter no. of columns");
    scanf("%d",&c);
    for(i=0;i<r;i++)
    {
                    for(j=0;j<c;j++)
                    {
                                    printf("enter element");
                                    scanf("%d",&ele);
                                    if(ele!=0)
                                    {
                                              cnt++;
                                              if(head==NULL)
                                                            head=getnode(i,j,ele);
                                              else
                                              
                                                  
                                                  if(head->next==head)
                                                  {
                                                  temp=getnode(i,j,ele);
                                                  temp->prev=head;
                                                  temp->next=head;
                                                  head->next=temp;
                                                  head->prev=temp;
                                                  }
                                                  else
                                                  {temp=getnode(i,j,ele);
                                                      t=head;
                                                      while(t->next!=head)
                                                                    t=t->next;
                                                      temp->next=head;
                                                      temp->prev=t;
                                                      t->next=temp;
                                                      head->prev=temp;                                                  
                                                  }
                                    }
                    }               
    }
    if(cnt>0)
    {
             displaylist(head);
             displaymatrix(r,c,head);
    }
    else
    {
        displaylist(head);
        for(i=0;i<r;i++)
        {
                    for(j=0;j<c;j++)
                    {
                                    printf(" 0 ");
                    }
                    printf("\n");
        }
    }
    
    getch();
    return 0;
}
                        
