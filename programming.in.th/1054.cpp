#include "stdio.h"
#include "algorithm"

struct Cir{
	int x,y,r;
}z[100001];
int p(int a){return a*a;}

bool ch(struct Cir a,struct Cir b)
{
	
	if(a.x==b.x)return a.y>b.y;	
	return a.x<b.x;
	/*return !(p(a.x-b.x) + p(a.y-b.y) < p(a.r+b.r));*/
}

int main()
{
	int n,o=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d %d",&z[i].x,&z[i].y,&z[i].r),z[i].x-=z[i].r;
	std::sort(z,z+n,ch);
	//puts(" ");
	for(int i=0;i<n;i++)
	{
		//printf("(%d %d) %d\n",z[i].x,z[i].y,z[i].r);
		z[i].x+=z[i].r;
		int j=i+1;
		while(j<n&& z[j].x < z[i].x + z[i].r)
		{
			//printf("(%d %d)\n",z[j].x,z[j].y);
			if( p(z[i].x-z[j].x-z[j].r) + p(z[i].y-z[j].y) < p(z[i].r+z[j].r) )o++;  //p(z[i].x-z[j].x) + p(z[i].y-z[j].y) < p(z[i].r+z[j].r)
			j++;
		}
	}
	printf("%d",o);
	return 0;
}
