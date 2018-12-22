#include<stdio.h>
#include<string.h>
int search(char*str, char str1, int len)
{
	int i;
	for(i=len-1;i>=0;i--)
		if(str1==str[i])
			return i;
	return -1;
}

void horsepool(char*str, char *str1)
{
	int len=strlen(str);
	int len1=strlen(str1);
	int a[10];
	int i, chr=0,j,jmp;
	for(i=len1-1;i>=0;i--)
		a[i]=len1-i-1;
	for(i=0;i<len1;i++)
	printf("%d ", a[i]);
	i=0;
	while(str[i]!='\0' && i<len)
	{
		chr=0;
		j=len1-1;
		while(str[i+j]==str1[j] && j>=0)
		{
			printf("Processing %c from str at position and %c from str1 at position %d\n",str[i+j],i+j,str1[j],j);
			j--;
			chr++;
		}
		if(j==-1 && chr==len1)
		{
			printf("Substring found\n");
			return ;
		}
		else
		{
			int loc=search(str1, str[i+j],len1);
			if(loc==-1)
				jmp=len1;
			else
				jmp=a[loc];
			i=i+jmp;
		}
	}
	printf("substring not found\n");
	return;
}
int main()
{
	char str[100], str1[100];
	gets(str);
	gets(str1);
	horsepool(str, str1);
	return 0;
}
