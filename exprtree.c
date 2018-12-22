#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 40

struct node
{
       char info;
       struct node *left;
       struct node *right;
};

typedef struct node *N;
N tree=NULL;

struct stack
{
       int top;
       N a[MAX];
}optr,oprnd;

N getnode(char ele)
{
              N temp=(N) malloc(sizeof(struct node));
              temp->info=ele;
              temp->left=temp->right=NULL;
              return temp;
}

void push(struct stack *s,N ele)
{
     if(s->top==MAX-1)
     {
                      printf("stack full");
                      return;
     }
     s->a[++(s->top)]=ele;
}

N pop(struct stack *s)
{
     if(s->top==-1)
     {
                   printf("stack empty");
                   return;
     }
     return s->a[(s->top)--];
}

int order(char ch)
{
    if(ch=='+'||ch=='-')
              return 1;
     else if(ch=='*'||ch=='/')
                         return 2;
           else 
                      return 3;
}          

void convert(char str[])
{
     int i;
     char ch;
     N temp=NULL;
     for(i=0;str[i]!='\0';i++)
     {
                              ch=str[i];
                              if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='$'||ch=='^')
                              {
                                    if(optr.top==-1)
                                                        push(&optr,getnode(ch));
                                    else
                                    
                                        if(order(ch)>order(optr.a[optr.top]->info))
                                                         push(&optr,getnode(ch));
                                        else
                                        { while(order(optr.a[optr.top]->info)>order(ch)&&optr.top!=-1)
                                          {
                                               temp=pop(&optr);
                                               temp->right=pop(&oprnd);
                                               temp->left=pop(&oprnd);
                                               push(&oprnd,temp);
                                          }
                                          push(&optr,getnode(ch));
                                        }
                              }
                              else
                                  push(&oprnd,getnode(ch));
     }
     if(optr.top!=-1)
     {
                      while(optr.top!=-1)
                      {
                                          temp=pop(&optr);
                                          temp->right=pop(&oprnd);
                                          temp->left=pop(&oprnd);
                                          push(&oprnd,temp); 
                      }
     }
     if(oprnd.top==-1)
     {
                       printf("invalid string");
                       return;
     }
     tree=pop(&oprnd);
     return;
} 
 
 void infix(N root)
{
     if(root==NULL)
                   return;
     
     infix(root->left);
     printf(" %c",root->info);
     infix(root->right);
}
void prefix(N root)
{
     if(root==NULL)
                   return;
     printf(" %c",root->info);
     prefix(root->left);
     prefix(root->right);
}

void postfix(N root)
{
     if(root==NULL)
                   return;
     postfix(root->left);
     postfix(root->right);
     printf(" %c",root->info);
}                   
int main()
{
    char str[40];
    optr.top=oprnd.top=-1;
    printf("enter the string");
    scanf("%s",str);
    convert(str);
    infix(tree);
    printf("\n");
    prefix(tree);
    printf("\n");
    postfix(tree);
    getch();return;
}
