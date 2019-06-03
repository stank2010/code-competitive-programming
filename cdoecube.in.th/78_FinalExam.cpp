#include "stdio.h"

int main()
{
	int z[5],x,sum=0;
	bool b=0;
	scanf("%d",&x);
	
	for(int i=0;i<5;i++)
	{
		scanf("%d",&z[i]);
		sum+=z[i];
	}
	
	if(sum==x)b=1;
	else
	for(int i=0;i<5;i++)
	if(sum-z[i]==x)
	{
		z[i]=0;
		b=1;
		break;
	}
	
	if(b)
	{
		for(int i=0;i<5;i++)printf("%d ",z[i]);
	}
	else printf("-1");
	
	return 0;
}
