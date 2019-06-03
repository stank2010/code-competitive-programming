#include "stdio.h"

struct U{
	int x,y,r;
}q[300001],a;

int l;
int z[501][501];
int wall[501][501],t[300001],T,sum;

int main()
{
	int h,w;
	scanf("%d %d",&h,&w);
	for(int i=h-1;i>=0;i--)
		for(int j=0;j<w;j++)scanf("%d",&z[i][j]);
	
	q[0].x=q[0].y=0;
	q[0].r=l=1;
	
	int X,Y;
	while(l>=0)
	{
		a=q[l];
		X=a.x;
		Y=a.y;
		
		if(!z[Y][X]&&wall[Y][X]==0)
		{//printf("(%d %d) %d\n",X,Y,a.r);
			wall[Y][X]=1;
			t[a.r]++;
			if(a.r>T)T=a.r;
			a.r++;
			if(X+1<w)
			{
				q[l]=a;
				q[l++].x++;
			}
			if(Y+1<h)
			{
				q[l]=a;
				q[l++].y++;
			}
		}
		l--;
	}
	for(int i=0;i<=T;i++)sum+=t[i]*t[i];//,printf("%d=%d\n",i,t[i]);
	printf("%d",sum);
	return 0;
}
