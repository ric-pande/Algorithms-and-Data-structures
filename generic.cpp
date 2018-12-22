#include<iostream>
#include<conio.h>
using namespace std;

template<class T>
class queue
{
      T a[20];
      int rear,front;
      
      public:
             
      queue()
      {
             rear=-1;
             front=0;
      }
      
      void insertq()
      {
           T ele;
           cout<<"enter element to be inserted";
           cin>>ele;
           
           a[++rear]=ele;
      }
      
      void deleteq()
      {
           if(front>rear)
           {
                         cout<<"queue underflow";
                         return;
           }
           cout<<"element deleted ="<<a[front++];
      }
      
      void display()
      {
          int i;
          if(front>rear)
           {
                         cout<<"queue underflow";
                         return;
           }
           for(i=front;i<=rear;i++)
                    cout<<a[i]<<" ";
      }
      
};

int main()
{
    queue<int>intq;
    queue<float>fq;
    queue<char>cq;
    int optype,op;
    cout<<"enter choice 1.integer 2. float 3. char";
    cin>>optype;
    while(1){
    cout<<"enter 1 push 2 pop 3.display";
    cin>>op;
    
    switch(op)
    {
              case 1: if(optype==1)
                                   intq.insertq();
                                   if(optype==2)
                                                fq.insertq();
                                                if(optype==3)
                                                             cq.insertq();
                                                             break;
              case 2: if(optype==1)
                                   intq.deleteq();
                                   if(optype==2)
                                                fq.deleteq();
                                                if(optype==3)
                                                             cq.deleteq();
                                                             break;
              case 3: if(optype==1)
                                   intq.display();
                                   if(optype==2)
                                                fq.display();
                                                if(optype==3)
                                                             cq.display();
                                                             break;
              default:cout<<"enter correct choice";
    }}
    getch();return 0;
}
