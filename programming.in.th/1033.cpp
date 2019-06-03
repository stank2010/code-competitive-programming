#include "stdio.h"
int z[101][101],n,k;
char walk[5001];

struct U{
	int x,y,tam;
}play[5];


bool com(int pi,int X,int Y)
{
	for(int i=1;i<=4;i++)
		if(i!=pi&&X==play[i].x&&Y==play[i].y)return 0;
	return 1;
}

void ch(int pi,char a)
{
	     if(a=='N'&&play[pi].y>0  &&com(pi,play[pi].x,play[pi].y-1))play[pi].y--;
	else if(a=='S'&&play[pi].y<n-1&&com(pi,play[pi].x,play[pi].y+1))play[pi].y++;
	else if(a=='E'&&play[pi].x<n-1&&com(pi,play[pi].x+1,play[pi].y))play[pi].x++;
	else if(a=='W'&&play[pi].x>0  &&com(pi,play[pi].x-1,play[pi].y))play[pi].x--;
	z[play[pi].y][play[pi].x]=pi;
}

int total()
{
	int max=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(z[i][j]==0)return 0;
			else 
			{
				play[z[i][j]].tam++;
				if(play[z[i][j]].tam>max)max=play[z[i][j]].tam;	
			}
	return max;
}

int main()
{
	scanf("%d %d",&n,&k);
	play[4].x=play[4].y=0; z[0][0]=4;
	play[2].x=play[2].y=n-1; z[n-1][n-1]=2;
	play[3].x=play[1].y=0;  z[0][n-1]=1;
	play[3].y=play[1].x=n-1; z[n-1][0]=3;
	/*
	for(int i=0;i<n;i++,puts(""))
		for(int j=0;j<n;j++)
			{
				printf("%d ",z[i][j]);
			}
	*/
	for(int i=0;i<4*k;i++)
	scanf(" %c",&walk[i]);
	//printf("%s",walk);
	for(int i=0;i<k;i++)
	{
		ch(1,walk[i]);
		ch(2,walk[k+i]);
		ch(3,walk[2*k+i]);
		ch(4,walk[3*k+i]);
	}
	
	int max=total(),val=0;
	
	if(max)
	{
		for(int i=1;i<=4;i++)if(play[i].tam==max)val++;
		printf("%d %d\n",val,max); for(int i=1;i<=4;i++)if(play[i].tam==max)printf("%d\n",i);
	}
	else printf("No");
	
	return 0;
}
