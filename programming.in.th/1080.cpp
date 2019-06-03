#include "stdio.h"
#include "algorithm"

int z[30002],sp,max;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&z[i]);
	std::sort(z,z+n);
	
	for(int i=0;i<n;i++)
	{
		if(i-sp>1)
		{
			if(z[sp]+z[sp+1]<=z[i])
			{
				sp++;	
			}
		}
		if(i-sp+1>max)
			max=i-sp+1;
	}
	printf("%d",max);
	return 0;
}
