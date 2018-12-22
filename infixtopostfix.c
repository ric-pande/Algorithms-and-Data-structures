#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 40

struct stack
{
       int a[MAX];
       int top;
};

void push(struct stack *s,int ele)
{
     if(s->top==MAX-1)
     {
                      printf("stack overflow");
                      return;
     }
     s->a[++(s->top)]=ele;
}

int pop(struct stack *s)
{
     int ele;
     if(s->top==-1)
     {
                 printf("stack underflow");
                 return;
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
                          printf("%d ",s.a[i]);
     printf("\n");
}
int order(char a)
{
    if(a=='+'||a=='-')
             return 1;
    else  if(a=='*'||a=='/')
              return 2;
              else if(a=='^'||a=='$')
                      return 3;
                      else
                          return 4;
}

int main()
{
    int i,y=0,cmp,temp;
    char istr[40],ostr[40],ch,sym;
    struct stack s;
    s.top=-1;
    printf("enter infix string");
    gets(istr);
    for(i=0;istr[i]!='\0';i++)
    {
                               ch=istr[i];
                               if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))
                                             ostr[y++]=ch;
                               else
                               
                                  if(ch=='{'||ch=='(')
                                     push(&s,ch);
                                   else
                                   
                                      if(ch=='}'||ch==')')
                                       {
                                                           if(ch=='}')
                                                           {
                                                                     
                                                                      sym=pop(&s);
                                                                      while(sym!='{')
                                                                      {
                                                                                     ostr[y++]=sym;
                                                                                      sym=pop(&s);
                                                                      }
                                                           }
                                                           if(ch==')')
                                                           {
                                                                     
                                                                      sym=pop(&s);
                                                                      while(sym!='(')
                                                                      {
                                                                                     ostr[y++]=sym;
                                                                                      sym=pop(&s);
                                                                      }
                                                           } 
                                       }
                                        
                                       else   
                                       if(ch=='+'||ch=='-'|| ch=='*'|| ch=='/'|| ch=='^'|| ch=='$')
                                       {
                                                             if(s.top==-1||s.a[s.top]=='(')
                                                                     push(&s,ch);
                                                             else
                                                             {        
                                                                cmp=order(s.a[s.top])-order(ch);
                                                               if(cmp>=0)
                                                               {
                                                                  while(cmp>=0)
                                                                 { sym=pop(&s);
                                                                  ostr[y++]=sym;
                                                                  if(s.top==-1&&s.a[s.top]=='(') break;
                                                                  cmp=order(ch)-order(s.a[s.top]);
                                                                  }
                                                                  
                                                                  push(&s,ch);
                                                               }
                                                               else   push(&s,ch);
                                                             
                                                              
                                                             }
                                       } 
     }
     while(s.top!=-1)
     {
                     temp=s.a[s.top];
                     if(temp=='(')
                                  ch=pop(&s);
                     ostr[y++]=pop(&s);
     }                  
     ostr[y]='\0';
     puts(ostr);                                                                   
     getch();
     return 0;
}

