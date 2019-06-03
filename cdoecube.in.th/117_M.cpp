#include "stdio.h"

int q[10],num[200008],z[1000],l[200008],L;

int main()
{
	int t,n,k,max;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf(" %d %d",&n,&k);
		for(int j=0;j<k;j++)
			num[j]=0;
			
		for(int j=0;j<n;j++)
			scanf(" %d",&z[j]);
		
		for(int p=0;p<n;p++)
		{
			for(int j=0;j<k;j++)
			if(num[j]==1)
			{
				if(!num[(j+z[p])%k])l[L++]=(j+z[p])%k;
			}
			else if(j==z[p]%k&&!num[j])
			{
				num[j]=1;
			}
			
			while(L>0)
				num[l[--L]]=1;	
		}	
		
		
		
		for(int j=k-1;j>=0;j--)
		if(num[j]==1)
		{
			q[i]=j;
			break;
		}
	}
	for(int i=0;i<t;i++)
		printf("Case #%d: %d\n",i+1,q[i]);
	return 0;
}
