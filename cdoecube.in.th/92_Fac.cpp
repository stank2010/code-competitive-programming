#include "stdio.h"
#include "math.h"

double z[100001];

double q[10000];

int main()
{
	int n,a;
	for(int i=1;i<=100000;i++)
	{
		z[i]=log10(i)+z[i-1];	
	}	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		q[i]=z[a];
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%.0lf\n",ceil(q[i]));
	}
	return 0;
}
