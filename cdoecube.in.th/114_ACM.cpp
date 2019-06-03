#include "stdio.h"

int q[100];

void ch(int l)
{
	int n,m,min;
	scanf("%d %d",&m,&n);
	if(m<n)
	{
		int M=n,k=0,co=0;
		while(M>m)
		{
			M-=20;
			k++;
		}
		
		while(M>=0)
		{
			//printf("%d \n",M);
			co++;
			M-=20;
		}
		q[l]=co;
	}
	else
	{
		q[l]=n/20+1;
		if(n==20)q[l]=0;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
		ch(i);
	for(int i=0;i<t;i++)
	{
		printf("Case #%d: %d\n",i+1,q[i]);
	}
		
	return 0;
}
