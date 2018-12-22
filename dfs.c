/*dfs order of traversal*/
#include<stdio.h>
int main()
{
	void dfs(int v, int m[20][20], int a[20], int n);
	int n,a[20]={0},m[20][20],i,j,cnt=0;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter adjacency matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&m[i][j]);
	dfs(0,m,a,n);
	printf("\n");
	for(i=0;i<n;i++)
		if(a[i])
			cnt++;
	if(cnt==n)
		printf("Graph is connected\n");
	else
	{
		for(i=0;i<n;i++)
		{
			if(a[i]==0)
			{
				dfs(i,m,a,n);
				printf("\n");
			}
		}
		printf("Graph is disconnected\n");
	}
	return 0;
}
void dfs(int v, int m[20][20], int a[20], int n)
{
	int i;
	printf("%d->",v);
	a[v]=1;
	for(i=0;i<n;i++)
	{
		if(m[v][i] && !a[i])
			dfs(i,m,a,n);
	}
	printf("\n");
	return;
}
