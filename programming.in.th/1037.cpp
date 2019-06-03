#include "stdio.h"

char z[51][51];
int flood[51][51],go[51][51],R,C;

void tour(int x,int y,int r)
{
	if((r<flood[y][x] || flood[y][x]==0) && (r<go[y][x]||go[y][x]==0))
	{
	go[y][x]=r;
	if(z[y-1][x]=='.' )//&& ( go[y-1][x]>go[y][x]+1 || go[y-1][x]==0))
		tour(x,y-1,r+1);
		
	if(z[y+1][x]=='.' )//&& ( go[y+1][x]>go[y][x]+1 || go[y+1][x]==0))
		tour(x,y+1,r+1);
		
	if(z[y][x-1]=='.' )//&& ( go[y][x-1]>go[y][x]+1 || go[y][x-1]==0))
		tour(x-1,y,r+1);		
		
	if(z[y][x+1]=='.' )//&& (go[y][x+1]>go[y][x]+1 || go[y][x+1]==0))
		tour(x+1,y,r+1);
	}
}

void Water(int x,int y,int r)
{
	if(r<flood[y][x]||flood[y][x]==0)
	{
	flood[y][x]=r;
	if(z[y-1][x]=='.'&& ( flood[y-1][x]>flood[y][x]+1 || flood[y-1][x]==0))
		Water(x,y-1,flood[y][x]+1);
		
	if(z[y+1][x]=='.'&& ( flood[y+1][x]>flood[y][x]+1 || flood[y+1][x]==0))
		Water(x,y+1,flood[y][x]+1);
		
	if(z[y][x-1]=='.'&& ( flood[y][x-1]>flood[y][x]+1 || flood[y][x-1]==0))
		Water(x-1,y,flood[y][x]+1);		
		
	if(z[y][x+1]=='.'&& ( flood[y][x+1]>flood[y][x]+1 || flood[y][x+1]==0))
		Water(x+1,y,flood[y][x]+1);	
	}
}



int main()
{
	bool b=0;
	int X,Y;
	scanf("%d %d",&R,&C);
	for(int i=0;i<R;i++)
		scanf("%s",z[i]);
	
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
		if(z[i][j]=='*')
		{
			Water(j,i,1);
		}
		else if(z[i][j]=='D')
		{
			Y=i;
			X=j;
		}
	
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		 if(z[i][j]=='S')
		 {
		 	tour(j,i,1);
			 b=1;
			 break;	
		 }
		if(b)
			break;
	}	
	/*
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		printf("%d ",go[i][j]);	
		printf("\n");
	}
	printf("\n\n");
	
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		printf("%d ",flood[i][j]);	
		printf("\n");
	}
	printf("\n\n");*/
	int P=9999;
	
	if(go[Y][X+1]>0&&X+1<C&&go[Y][X+1]<P)
		P=go[Y][X+1];
	if(go[Y][X-1]>0&&X-1>=0&&go[Y][X-1]<P)
		P=go[Y][X-1];
	if(go[Y+1][X]>0&&Y+1<R&&go[Y+1][X]<P)
		P=go[Y+1][X];
	if(go[Y-1][X]>0&&Y-1>=0&&go[Y-1][X]<P)
		P=go[Y-1][X];	 
		
	if(P<9999)printf("%d",P);
	else printf("KAKTUS");
	return 0;
}
