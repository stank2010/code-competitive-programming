#include "stdio.h"

long h(long x,long y)
{
	long z;
	while(x!=0)
	{
		z=x;
		x=y%x;
		y=z;
	}
	return y;
}

int a[100000];
int main()
{
	int n;
	long l;
	scanf("%d %d",&n,&a[0]);
	l=a[0];
	for(int i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
		l=(l/h(l,a[i]))*a[i];
	}
	
	printf("%ld",l);	
	return 0;
}
