#include "stdio.h"

int z[2505],q[2505],n,max=-1000000,sp,ep;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&z[i]);
		q[i]=q[i-1]+z[i];
	}
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(q[j]-q[i-1]>max)max=q[j]-q[i-1],sp=i,ep=j;
		}
	}
	if(max>0)
	{
		for(int i=sp;i<=ep;i++)printf("%d ",z[i]);	
		printf("\n%d",max);
	}
	else printf("Empty sequence");
}
