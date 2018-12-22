#include<iostream.h>
#include<conio.h>
using namespace std;

class invalid
{
      public:invalid()
      {
              cout<<"negative number entered";
      }
};

void fact(int n)
{
     int fact=1,i;
     if(n==0)
             cout<<"factoial =1";
     else
     {
         for(i=1;i<=n;i++)
                         fact*=i;
         cout<<"factorial = "<<fact;
     }
}

int main()
{
    while(1){
    try
    {
         
          int i;
          cout<<"\nenter a number\n";
          cin>>i;
          
          if(i>=0)
                  fact(i);
          else
                  throw invalid();
    }
    catch(invalid e)
    {
         cout<<"\nexception encountered";
    }}
    getch();return 0;
}   
