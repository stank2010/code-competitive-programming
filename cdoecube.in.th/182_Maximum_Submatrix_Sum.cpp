#include "stdio.h"

int n,h,w,temp;
int z[100001],mod=100001;

long long val(int fix)
{
	int a=0;
	long long sum_a=0,max=0;
	
	for(int i=0;i<n;i++)
	{
		int p = i%mod;
		
		scanf("%d",&z[p]);
		
		if(i<fix)	
			sum_a+=z[p];
		else 
		{
			sum_a = sum_a-z[a]+z[p];
			a=(a+1)%mod;
			
		}	
		if(sum_a>max)
			max=sum_a;	
		//printf(" (%d) ",sum_a);
	}
	
	return max;
}


int main()
{
	scanf("%d %d %d",&n,&h,&w);
	
	long long a=val(h);
	long long b=val(w);
	printf("%lld",a*w+b*h);
	return 0;
}
