#include "stdio.h"
#include "algorithm"

struct Q{
	int x,y;
	bool ch;
}z[1000000];


bool X(struct Q a,struct Q b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x>b.x;	
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	
		scanf(" %d %d",&z[i].x,&z[i].y),z[i].ch=0;
	std::sort(z,z+n,X);
	
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(z[i].y>=max)
		{
			max=z[i].y;
			z[i].ch=1;
		}
	}
	
	for(int i=n;i>=0;i--)
		if(z[i].ch)
			printf("%d %d\n",z[i].x,z[i].y);
	return 0;
}
