#include<stdio.h>
#include<conio.h>
#define queuesize 100
int rear=-1,pq[queuesize];
void heapify()
{
     int n,k;
     int key,pos,j;
     n=rear+1;//NO of elements
     for(k=1;k<n;k++)
     {
                     key=pq[k];
                     pos=k;
                     j=(pos-1)/2;
                     while(pos>0&&key>pq[j])
                     {
                           pq[pos]=pq[j];
                           pos=j;
                           j=(pos-1)/2;                    
                     }
                     pq[pos]=key;
     }
}
void insert(int ele)
{
     if(rear==queuesize-1)
     {
                          printf("Queue overflow");
                          return;
     }
     rear=rear+1;
     pq[rear]=ele;
     heapify();
     return;
}
int delete()
{
    int x;
    if (rear==-1)
    {
                 printf("Empty queue");
                 return -1;
    }
    x=pq[0];
    if(rear==0)
               rear=-1;
    else
    {
        pq[0]=pq[rear];
        rear--;
        heapify();
    }
    return x;
}
void display()
{
     int i;
     if(rear==-1)
     {
                 printf("Queue empty");
                 return;
     }
     for(i=0;i<=rear;i++)
                         printf("%d  ",pq[i]);
     printf("\n");
     return;
}
int main()
{
    int ch,ele;
    printf("\n\nDescending priority queue");
    while(1)
    {
            printf("\n1.Insert\t2.Delete\t3.Display\nEnter your choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
                      case 1:
                           printf("Enter the element: ");
                           scanf("%d",&ele);
                           insert(ele);
                           break;
                      case 2:
                           ele=delete(ele);
                           printf("%d deleted",ele);
                           break;
                      case 3:
                           display();
                           break;
                      default:
                              return 0;
            }
    }
}
