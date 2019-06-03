#include "stdio.h"

int main()
{
	int n;
	scanf("%d",&n);
	
	if(n%2)
	{
		for(int i=0;i<n/2;i++)
		{
			for(int j=0;j<i;j++)
			printf(" ");
			for(int j=0;j<2*(n/2-i)+1;j++)
			printf("*");
			printf("\n");
		}
		
		for(int j=0;j<n/2;j++)
		printf(" ");
		printf("*\n");
		
		for(int i=n/2-1;i>=0;i--)
		{
			for(int j=0;j<i;j++)
			printf(" ");
			for(int j=0;j<2*(n/2-i)+1;j++)
			printf("*");
			printf("\n");
		}
	}
	else printf("error");
	
	return 0;
}
