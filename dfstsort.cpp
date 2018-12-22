#include<iostream>
#include<conio.h>
using namespace std;

void dfs(int v, int a[][20], int flag[20],int n, int b[20], int c[20], int d[20]);

int main()
{
	int i,n, a[20], flag[20]={0}, g[20][20],v,j,c[20]={0},d[20];
	cout<<"Enter the number of vertices  ";
	cin>>n;
	cout<<"Enter the elements\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter the adjacency matrix\n";
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>g[i][j];
	cout<<"Enter starting vertex  ";
	cin>>v;
	dfs(v,g,flag,n,a,c,d);
	int sum=0;
	for(i=0;i<n;i++)
		sum+=flag[i];
	if(sum==n)
	{
		cout<<"Graph is connected\n";
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(flag[i]==0)
				dfs(i,g,flag,n,a,c,d);
		}
	}
	cout<<"hi";
	cout<<"Elements in sorted order\n";
	for(i=n-1;i>=0;i--)
		cout<<d[i]<<"  ";
	cout<<endl;
	cout<<endl;
	return 0;
}

void dfs(int v, int a[][20], int flag[20], int n, int b[20], int c[20], int d[20])
{
// c for marking a vertex as dead end or not
// d for sorted list
	cout<<b[v]<<"->";
	int i;
	flag[v]=1;
	int flag1=0;
	static int dead=0;
	for(i=0;i<n;i++)
	{
		if(!flag[i] && a[v][i]==1)
		{	dfs(i,a,flag,n,b,c,d);
			flag1++;
		}
	}
	if(flag1==0 && c[v]==0)
	{
		c[v]=1;
		d[dead++]=b[v];
		return;
	}
	if(c[v]==0)
		d[dead++]=b[v];
	getch();return;
}
