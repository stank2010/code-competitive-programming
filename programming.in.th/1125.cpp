#include "stdio.h"
#include "algorithm"
int x[500000],y[500000],n;

unsigned long long int k[500000],sum;


int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&x[i],&y[i]);
	std::sort(x,x+n);
	std::sort(y,y+n);
	
	n--;
	int l=0;
	for(int i=0;i<n/2+n%2;i++,l++)
		k[l]=k[n-l-1]=(unsigned long long int)(i+1)*(unsigned long long int)(n-i);

	for(int i=0;i<n;i++)
	{
		sum+=k[i]*(unsigned long long int)(x[i+1]-x[i]+y[i+1]-y[i]);
	}
	
	printf("%llu",sum);	
	return 0;
}
