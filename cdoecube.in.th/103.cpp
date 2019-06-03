#include "stdio.h"

int j[1000001],k[1000001];

int abs(int a,int b)
{
	if(a>b)return a-b;
	return b-a;
}

int main()
{
	int n,st,a,b,c,l=0;
	scanf("%d %d",&n,&st);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		if(a>b)
		{
			c=a;
			a=b;
			b=c;
		}
		j[a]++;
		k[b]++;
	}
	int s=0,max=0,sp=0;
	
	for(int i=0;i<=1000000;i++)
	{
		s+=j[i];
		if(s>max)
		{
			max=s;
			sp=i;
		}
		else if(s==max)
		{
			if(abs(i,st)<abs(sp,st))
				sp=i;
		}
		s-=k[i];
	}
	
	if(max==n)
	{
		printf("%d",abs(sp,st));
	}
	else printf("-1");
	return 0;
}
