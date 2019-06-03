#include "stdio.h"

int z[1000],t[1000];

int main()
{
	int m,n,a,b;
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++)
		scanf("%d ",&z[i]);
	
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		a--;
		for(int j=0;j<b;j++)
			t[j]=z[(j+a)%n];
		for(int j=0;j<b;j++)
			z[(j+a)%n]=t[b-j-1];
	}
	for(int i=0;i<n;i++)
		printf("%d ",z[i]);
	
	return 0;
}
