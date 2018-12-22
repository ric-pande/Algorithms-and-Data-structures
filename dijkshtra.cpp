#include<iostream>
using namespace std;

void input(int a[20][20], int &n)
{
	int i,j;
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"Enter weight matrix"<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
	return;
}

void dijkshtra(int a[20][20], int n, int temp[20], int dist[20], int s, int add)
{
	int min=99, vertex,i;
	for(i=0;i<n;i++)
	{
		if(a[s][i]+add<dist[i])
		{
			dist[i]=a[s][i]+add;
			if(min>dist[i] && temp[i]!=1)
			{
				min=dist[i];
				vertex=i;
			}
		}
	}
	if(min!=99)
	{
		temp[vertex]=1;
		dijkshtra(a,n,temp,dist,vertex,min);
	}
}
int main()
{
	int a[20][20], i, n,st, temp[20],dist[20];
	input(a,n);
	cout<<"Enter starting vertex  ";
	cin>>st;
	for(i=0;i<n;i++)
	{
		temp[i]=0;
		dist[i]=99;
	}
	temp[st]=1;
	dist[st]=0;
	dijkshtra(a,n,temp,dist,st,0);
	cout<<"S\tE\tW\n";
	for(i=0;i<n;i++)
		cout<<st<<"\t"<<i<<"\t"<<dist[i]<<endl;
	return 0;
}
