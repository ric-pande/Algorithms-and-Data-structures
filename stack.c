#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 40

struct stack
{
       int a[MAX];
       int top;
};

typedef struct stack* A;
void push(A s,int ele)
{
     if(s->top==MAX-1)
     {
                      printf("stack overflow");
                      return;
     }
     s->a[++(s->top)]=ele;
}

void pop(A s)
{
     int ele;
     if(s->top==-1)
     {
                 printf("stack underflow");
                 return;
     }
     ele=s->a[(s->top)--];
     printf("%d is popped off",ele);
}

void display(A s)
{
     int i;
     if(s->top==-1)
     {
                  printf("stack empty");
                  return;
     }
     for(i=0;i<=s->top;i++)
                          printf("%d ",s->a[i]);
     printf("\n");
}

int main()
{
    printf("1");
    int ch,ele;
    printf("1");
    A s;
    printf("1");
    s->top = -1;
    printf("1");
    while(1)
    {
            printf("eneter choice \n1. push \n2.pop \n 3.display\n");
            scanf("%d",&ch);
            switch(ch)
            {
                      case 1: printf("enter element to be pushed in the stack");
                              scanf("%d",&ele);
                              push(s,ele);
                              break;   
                      case 2: pop(s);
                              break;
                      case 3: display(s);
                              break;
                      default:printf("enter correct choice");
            }
    }
    getch();
    return 0;
}
