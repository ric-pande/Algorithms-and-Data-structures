#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class polynomial
{
      int t[10][2];
      int term;
      public:
             polynomial();
             polynomial operator+(polynomial o);
             polynomial operator*(polynomial o);
             void operator=(polynomial o);
             void value(int x);
             friend ostream &operator<<(ostream &out,const polynomial &o)
             {
                    int i;
                    for(i=0;i<o.term;i++)
                    {
                                         if(o.t[i][1]!=0)
                                                         out<<o.t[i][0]<<"x^"<<o.t[i][1];
                                         else
                                             out<<o.t[i][0];
                                         if(i!=o.term-1)
                                                        out<<"+";
                    }
                    return out;
             }
             friend istream &operator>>(istream &in,polynomial &o)
             {
                    cout<<"Enter the number of terms: ";
                    in>>o.term;
                    cout<<"Enter coefficient and power of terms\n";
                    int i;
                    for(i=0;i<o.term;i++)
                    {
                                         in>>o.t[i][0]>>o.t[i][1];
                    }
                    return in;
             }
};
polynomial::polynomial()
{
                        int i,j;
                        term=0;
                        for(i=0;i<10;i++)
                                         for(j=0;j<2;j++)
                                         t[i][j]=0;
}
polynomial polynomial::operator+(polynomial o)
{
           int i,j,flag;
           polynomial res;
           res=*this;
           for(i=0;i<o.term;i++)
           {
                                  flag=0;
                                  for(j=0;j<res.term;j++)
                                  {
                                                         if(o.t[i][1]==res.t[j][1])
                                                         {
                                                                                   res.t[j][0]+=o.t[i][0];
                                                                                   flag=1;
                                                                                   break;
                                                         }
                                  }
                                  if(flag==0)
                                  {
                                             res.term=res.term+1;
                                             res.t[res.term-1][0]=o.t[i][0];
                                             res.t[res.term-1][1]=o.t[i][1];
                                  }
           }
           return res;
}
void polynomial::operator=(polynomial o)
{
     int i;
     term=o.term;
     for(i=0;i<term;i++)
     {
                        t[i][0]=o.t[i][0];
                        t[i][1]=o.t[i][1];
     }
     return;
}
polynomial polynomial::operator*(polynomial o)
{
           int i,j,k,flag;
           polynomial res;
           res=*this;
           for(i=0;i<term;i++)
           {
                                for(j=0;j<o.term;j++)
                                {
                                                       flag=0;
                                                       for(k=0;k<res.term;k++)
                                                       {
                                                                              if(t[i][1]+o.t[j][1]==res.t[k][1])
                                                                              {
                                                                                                       res.t[k][0]+=t[i][0]*o.t[j][0];
                                                                                                       flag=1;
                                                                                                       break;
                                                                              }
                                                       }
                                                       if(flag==0)
                                                       {
                                                                  res.term+=1;
                                                                  res.t[res.term-1][0]=t[i][0]*o.t[j][0];
                                                                  res.t[res.term-1][1]=t[i][1]+o.t[j][1];
                                                       }
                                }
           }
           return res;
}
void polynomial::value(int x)
{
     int i;
     float value=0;
     for(i=0;i<term;i++)
                        value+=t[i][0]*pow(x,t[i][1]);
     cout<<"Value of the polynomial= "<<value;
}
int main()
{
    polynomial p1,p2,res;
    int ch,x;
    while(1)
    {
            cout<<"\n\n1.ADD\n2.MULTIPLY\n3.ASSIGN\n4.VALUE\n";
            cin>>ch;
            switch(ch)
            {
                      case 1:
                           cout<<"Enter polynomial 1\n";
                           cin>>p1;
                           cout<<"Enter polynomial 2\n";
                           cin>>p2;
                           res=p1+p2;
                           cout<<res;
                           cout<<"Enter the value of x: ";
                           cin>>x;
                           res.value(x);
                           break;
                      case 2:
                           cout<<"Enter polynomial 1\n";
                           cin>>p1;
                           cout<<"Enter polynomial 2\n";
                           cin>>p2;
                           res=p1*p2;
                           cout<<res;
                           cout<<"Enter the value of x: ";
                           cin>>x;
                           res.value(x);
                           break;
                      case 3:
                           cout<<"Enter polynomial 1\n";
                           cin>>p1;
                           res=p1;
                           cout<<res;
                           cout<<"Enter the value of x: ";
                           cin>>x;
                           res.value(x);
                           break;
                      case 4:
                           cout<<"Enter polynomial 1\n";
                           cin>>p1;
                           cout<<"Enter the value of x: ";
                           cin>>x;
                           p1.value(x);
                           break;
                      default:return 0;
                      }
            }
} 
