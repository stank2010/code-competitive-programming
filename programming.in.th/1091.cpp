#include "stdio.h"
#include "algorithm"
struct S{
	int x,y;
}q[300000];


bool ch(struct S a,struct S b)
{
	if(a.x==b.x)
		return a.y<b.y;
	else
		return a.x<b.x;
}

int z[300000];

int main()
{
	int n,M=0,o;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&q[i].x,&q[i].y);
		q[i].x--;
		q[i].y--;
		
		if(q[i].x>q[i].y)
		{
			o=q[i].x;
			q[i].x=q[i].y;
			q[i].y=o;
		}
	}
	std::sort(q,q+n-1,ch);
	
	for(int i=0;i<n-1;i++)
	{
		if(z[q[i].x]+1>z[q[i].y])
			z[q[i].y]=z[q[i].x]+1;
	}
	
	for(int i=0;i<n;i++)
	{
		if(z[i]>M)
			M=z[i];	
	}
	
	printf("%d",M+1);
	return 0;
}
