#include<iostream>
#include<vector.h>
#include<list.h>
#include<conio.h>
using namespace std;

int main()
{
    vector<int>v1,v2;
    list<int>list1;
    int n;
    cout<<"enter elements (enter -1 to exit)";
    while(1)
    {
            cin>>n;
            if(n==-1) break;
            v1.push_back(n);
            list1.push_back(n);
    }
    list1.sort();
    list<int>::iterator p;
    
    for(p=list1.begin();p!=list1.end();p++)
    {  cout<<*p<<" ";
       if(*p<10)
        v2.push_back(*p);
    }
    cout<<"\n";
    for(n=0;n<v2.size();n++)
          cout<<v2[n]<<" ";
    getch();
    return 0;
}
