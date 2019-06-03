#include "stdio.h"

int z[1001],k,n;

void swap(int &x,int &y)
{
	int a=x;
	x=y;
	y=a;
}

void check(int i)
{
	if(z[i]==i)
	{
		k++;
		return;
	}
	
	int sp;
	for(int j=1;j<=n;j++)
		if(i==z[j])sp=j;
		
	for(int j=sp;j<n;j++)
		z[j]=z[j+1];

	for(int j=n;j>i;j--)
		z[j]=z[j-1];
	z[i]=i;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&z[i]);
		
	for(int i=1;i<=(n+1)/2;i++)
	{
		check(i);
		if(n-i+1!=i)check(n-i+1);
	}	
	
	//if(n%2==1)check(n/2+1);
	//for(int i=1;i<=n;i++)printf("%d ",z[i]);
	printf("%d",k);
}
