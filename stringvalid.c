#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 40

struct stack
{
       char a[MAX];
       int top;
};

void push(struct stack *s,char ele)
{
     if(s->top==MAX-1)
     {
                      printf("stack overflow");
                      return;
     }
     s->a[++(s->top)]=ele;
}

char pop(struct stack *s)
{
     char ele;
     if(s->top==-1)
     {
                 printf("stack underflow");
                 return -1;
     }
     ele=s->a[(s->top)--];
     
     return ele;
}

void display(struct stack s)
{
     int i;
     if(s.top==-1)
     {
                  printf("stack empty");
                  return;
     }
     for(i=0;i<=s.top;i++)
                          printf("%c",s.a[i]);
     printf("\n");
}

int main()
{
    int ele,i;
    char ch,c1,c2,str[40];
    struct stack s,s1;
    s.top=s1.top=-1;
    printf("enter string");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++)
    {
         push(&s,str[i]);
    }
    ch=pop(&s);
    while(ch!='c'&&s.top!=-1)
    {
                             push(&s1,ch);
                             ch=pop(&s);
    }
    if(ch=='c')
    {
               while(s.top!=-1&&s1.top!=-1)
               {
                                           
               c1=pop(&s);
               c2=pop(&s1);
               if(c1!=c2)
               {
                         printf("invalid");getch();
                         return 0;
                         }}
    }
    if(s.top==-1&&s1.top==-1)
    {
                             printf("valid");getch();
                             return 0;
    }
    printf("invalid");                
    getch();
    return 0;
}
