#include "stdio.h"
int r,c,h,t,p[101][101];

struct T{
	int x,y,R;
}q[10010],time[10010];

struct C{
	bool left,right,up,down;
}P[101][101];


void add(int X,int Y,int ro)
{
	q[t].x=X;
	q[t].y=Y;
	q[t].R=ro;
	t++;
}

int main()
{
	bool b=1;
	char z[101][101];	
	scanf("%d %d",&r,&c);
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			scanf(" %c",&z[i][j]);
			if(z[i][j]=='B'||z[i][j]=='R')
				if(j+1<c)
					P[i][j].right=1,P[i][j+1].left=1;
				
			if(z[i][j]=='B'||z[i][j]=='D')
				if(i+1<c)P[i][j].down=1,P[i+1][j].up=1;	
		}
	
	add(0,0,1);
	while(h<t)
	{
		if(p[q[h].y][q[h].x]==q[h].R)
		{
			printf("%d\n",q[h].R);
			printf("%d %d",q[h].y+1,q[h].x+1);
			b=0;
			break;
		}
		
		p[q[h].y][q[h].x]=q[h].R;
	
		if(P[q[h].y][q[h].x].right==1)//&&q[h].x+1<c)
			if(q[h].R+1<=p[q[h].y][q[h].x+1]||p[q[h].y][q[h].x+1]==0)
			add(q[h].x+1,q[h].y,q[h].R+1);
	
		if(P[q[h].y][q[h].x].down==1)//&&q[h].y+1<r)
			if(q[h].R+1<=p[q[h].y+1][q[h].x]||p[q[h].y+1][q[h].x]==0)
			add(q[h].x,q[h].y+1,q[h].R+1);
			
		if(P[q[h].y][q[h].x].left==1)//&&q[h].x-1>=0)
			if(p[q[h].y][q[h].x-1]==0)
			add(q[h].x-1,q[h].y,q[h].R+1);
			
		if(P[q[h].y][q[h].x].up==1)//&&q[h].y-1>=0)
			if(p[q[h].y-1][q[h].x]==0)
			add(q[h].x,q[h].y-1,q[h].R+1);
		h++;
	}
	if(b)printf("%d\n%d %d",r+c-1,r,c);
		
	return 0;
}
