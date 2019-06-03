#include "stdio.h"

int H[300];

int main()
{
	int n,l,h,r,max=0,i,q;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&l,&h,&r);
		for(int j=l;j<r;j++)
			if(h>H[j])H[j]=h;
		if(r>max)max=r;	
	}
	
	i=1;
	while(H[i]<=0)i++;
	q=H[i];
	printf("%d %d ",i,q);
	while(i<=max)
	{
		if(H[i]!=q)
		{
			q=H[i];
			printf("%d %d ",i,q);
		}
		i++;
	}
	return 0;
}
