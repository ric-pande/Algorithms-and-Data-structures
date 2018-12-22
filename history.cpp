#include<iostream>
#include<cstring>
#include<fstream>
#include<conio.h>
using namespace std;

class student
{
      protected:
                char id[10];
                char ans[20];
                int score;
                double perct;
                char grade;
             
      public:
             
             void insertDetail(char i[10],char a[20]);
             void calcScore(char a[20]);            
             void display();
};

void student::insertDetail(char i[10],char a[20])
{
     strcpy(id,i);
     strcpy(ans,a);
}

void student::calcScore(char soln[20])
{
     int i,marks=0;
     float per;
     for(i=0;i<20;i++)
     {
                      if(soln[i]==ans[i])        marks+=2;
                      else
                          if(ans[i]==' ')        continue;
                          else
                              marks-=1;
     }
     
     score=marks;
     per =(float)marks/40;perct=per*100;
     if(per>0.90&&per<=1.0)
                  grade='A';
     else if(per>0.8&&per<=0.9)
                      grade='B';
          else if(per>0.7&&per<=0.8)
                            grade='C';
               else if(per>0.6&&per<=0.7)
                                grade='D';
                    else if(per>0.5&&per<=0.6)
                                    grade='E';
                         else
                                       grade='F';
                 
}
     
void student::display()
{
     cout<<id<<" "<<ans<<" "<<score<<" "<<grade<<" "<<perct<<"\n";
}

void entrytofile(int n,student s[])
{
     ofstream out;
     out.open("HISTORY_CLASS",ios::out);
     
     if(!out)
     {
             cout<<"cannot open history class file \n";
             return;
     }
     
     char answ[20],iid[10];
     cout<<"Enter correct answer";           //first entry contains solutions
     cin>>answ;
     out<<answ;
     
     int i; 
     
     for(i=0;i<n;i++)                        
     {
                     cout<<" \nEnter id and answers of"<<i+1<<" th student";
                     cin>>iid>>answ;
                     out<<iid<<" "<<answ;      //every other entry is id followed by a blank space and then answers
                     s[i].insertDetail(iid,answ);
     }
     
     out.close();
     return ;
}

void readSolution(char ans[])
{
     ifstream in;
     in.open("HISTORY_CLASS",ios::in);
       
     if(!in)
     {
             cout<<"cannot open history class file \n";
             return ;
     }  
     
                       //first entry contains solutions
     in>>ans;
     
     in.close();
     
     
}
              



int main()
{
    int n,i;
    cout<<"enter no. of students in class \n";
    cin>>n;
    
    student s[n];                            //array of objects
    
    entrytofile(n,s);
    
    char soln[20];
    readSolution(soln);
    
    for(i=0;i<n;i++)
                   s[i].calcScore(soln);
    
    cout<<"\n StudentId,answers,score,grade are as follows\n";
    for(i=0;i<n;i++)
    {
                   s[i].display();cout<<"\n";
    }
    getch();
    return 0;
}
    
    
    
    
    
