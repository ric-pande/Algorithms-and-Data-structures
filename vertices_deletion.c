#include<stdio.h>
#include<conio.h>
#define max 100

int g[max][max], a[max], n;

int indeg( int node)
{
	int i, sum=0;
	for(i=0;i<n;i++)
		sum+=g[i][node];
	return sum;
}

int main()
{
	int que_1;
	printf("Enter the number of elements  ");
//	int n;
	scanf("%d",&n);
	int i,flag[100];
	for(i=0;i<n;i++)
	{
		flag[i]=0;
	}
	printf("Enter the adjacency matrix\n");
	int  j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);
	}
	int f=0;
	for(i=0;i<n;i++)
		f+=indeg(i);
	if(f==0)
	{
		printf("Disconnected graph\n");
		return 0;
	}

	int sorted[100];
	i=0;
	while(i<n)
	{
		for(j=0;j<n;j++)
		{
			if(indeg(j)==0 && flag[j]==0)
			{
				que_1=a[j];
				break;
			}
		}	
		
		printf("Element currently in  progress  %d",que_1);
		sorted[i++]=que_1;
		int k;
		for(k=0;k<n;k++)
			g[j][k]=0;
		flag[j]=1;//mark that vertex as visited
	}
	for(j=0;j<n;j++)
	{
		if(flag[j]==0)
		{
			sorted[i++]=a[j];
			break;
		}
	}
	printf("Vertices in sorted order\n");
	for(i=0;i<n;i++)
		printf("%d  ",sorted[i]);
	printf("\n");
	getch();return 0;
}
