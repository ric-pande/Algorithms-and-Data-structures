/*floyds algorithm*/
#include<stdio.h>
int g[10][10],n;
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int main()
{
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int i, j,k;
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);
	int r;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				r=g[i][k]+g[k][j];
				g[i][j]=min(g[i][j],r);
			}
		}
	}
	printf("Shortest distance matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%2d  ",g[i][j]);
		printf("\n");
	}
	return 0;
}
							
