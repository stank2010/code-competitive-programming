#include "stdio.h"

int z[1001][1001],n,m;

int abs(int a)
{
	if(a<0)return 0;
	else if(a>1000)return 1000;
	else return a;
}

int main()
{
	int a,b,r;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d %d",&a,&b),z[b][a]++;
	for(int j=0;j<m;j++)
	{
		scanf("%d %d %d",&a,&b,&r);	
		
		int ma=abs(a+r),mb=abs(b+r),k=0;
		
		for(int i=abs(b-r);i<=mb;i++)
			for(int l=abs(a-r);l<=ma;l++)
			if(z[i][l]>0)
			{
				k+=z[i][l];
				z[i][l]=0;
			}
		printf("%d\n",k);
	}	
	return 0;
}
