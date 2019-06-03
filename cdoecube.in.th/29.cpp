#include "stdio.h"

int z[1000],set[1000];

int main()
{
	int  k=1,l=0;
	
	int n,a;
	scanf("%d",&n);
	
	while(z[k]==0)
	{
		z[k]=1;
		set[l]=k;
		k=(k*4)%997;
		l++;
	}
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		int s=(set[a%166] + ((a%2==0)?2:-2))%997;
		if(s==-1)printf("996 ");
		else printf("%d ",s%997);
	}
	
	return 0;
}
