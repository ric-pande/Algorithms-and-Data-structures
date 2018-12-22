#include<stdio.h>
#include<stdlib.h>

struct tree
{
       int info;
       struct tree* right;
       struct tree* left;
};

typedef struct tree* N;

N maketree(int ele)
{
               N temp;
               temp=(N) malloc(sizeof(struct tree));
               if(temp==NULL)
               {
                             printf("memory unavailable");return NULL;
               }
               temp->info=ele;
               temp->left=temp->right=NULL;
               return temp;
}

void setright(N p,int ele)
{
             if(p==NULL)
                        printf("void insertion");
             else  if(p->right!=NULL)
                                     printf("insertion not possible");
                   else
                                     p->right=maketree(ele);  
}                
void setleft(N p,int ele)
{
             if(p==NULL)
                        printf("void insertion");
             else  if(p->left!=NULL)
                                     printf("insertion not possible");
                   else
                                     p->left=maketree(ele);  
}              

N insert(N tree,int ele)
{
     N p,q;
     p=q=tree;
     if(tree==NULL)
     {
                   tree=maketree(ele);
                   return tree;
     }                  
     while(p->info!=ele&&q!=NULL)
     {
                                 p=q;
                                 if(ele>p->info)
                                                q=p->right;
                                 else
                                                q=p->left;
     }
     if(ele==p->info)
                     setleft(p,ele);
     else  if(ele>p->info)
                          setright(p,ele);
           else
                          setleft(p,ele);
}  
void display(N p)
{
     display(p->left);
     printf("%d ",p->info);
     display(p->right);
}
                   

int main()
{
    N tree;
    int ch,ele;
    while(1)
    {
            printf("1.insert 2.display");
            scanf("%d",&ch);
            switch(ch)
            {
                      case 1: printf("enter element to be inserted");
                              scanf("%d",&ele);
                              tree= insert(tree,ele);
                              break;
                      case 2: display(tree);
                              break;
                      default:printf("enter valid option");
            }
            return 0;
    }
}
