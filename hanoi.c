#include<stdio.h>
#include<conio.h>


int count=0;
void move(int n,char a,char b,char c)
{
     if(n==1)
     {
             printf("\n move disk %d from %c to %c",n,a,c);
             count++;
             return;
     }
     move(n-1,a,c,b);
     printf("\n move disk %d from %c to %c",n,a,c);
     count++;
     move(n-1,b,a,c);
}

int main()
{
    int n;
    printf("enter no.of disks");
    scanf("%d",&n);
    move(n,'A','B','C');
    printf("count =%d",count);
getch();
return 0;

}
