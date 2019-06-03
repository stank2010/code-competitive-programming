#include "stdio.h"
#include "algorithm"

int z[100001],max=1;
int p,l,num[100001];
int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",&z[i]);	
	std::sort(z,z+n);
	
	p=z[0];
	num[l]=1;
	for(int i=1;i<n;i++)
	{
		if(z[i]!=p)
		{
			p=z[i];
			num[++l]=1;	
		}
		else num[l]++;
		
		if(num[l]>max)max=num[l];	
	}		
	printf("%d",max);
	return 0;
}
