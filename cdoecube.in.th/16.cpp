#include "stdio.h"

long long  z[2001];
long long s;

void swap(long long  &a,long long  &b){long long c=a; a=b; b=c;}

int main()
{
	int n;	
	scanf("%lld",&n);
	n*=2;
	for(int i=0;i<n;i++)scanf("%lld",&z[i]);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		if(z[j]>z[j+1])swap(z[j],z[j+1]);
	}
	
	for(int i=0;i<n/2;i++)
	{
		s+=z[i]*z[n-1-i];
	}
	printf("%lld",s);
}
