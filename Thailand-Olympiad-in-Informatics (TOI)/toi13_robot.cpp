#include "stdio.h"

struct Que
{
	int x,y,val;
}q[6000001];

int Front,Len;
int n,m;
char Map[2005][2005];
bool ch[2005][2005];
int Short[2005][2005];

void add(int x,int y,int val)
{
	q[Len].x = x;
	q[Len].y = y;
	q[Len].val = val;
	Len++;
}

void bfs()
{
	while(Front<Len)
	{
		Que A = q[Front++];
		int y=A.y,x=A.x,val=A.val;
		
		if(ch[y][x])
			continue;
		ch[y][x] = true;
		Short[y][x] = val;
		
		if(y-1>=0)
		if(ch[y-1][x]==false and Map[y-1][x]!='W' )
			add(x,y-1,val+1), Short[y-1][x] = val+1 ,ch[y-1][x] = true;
		
		if(x-1>=0)
		if(ch[y][x-1]==false and Map[y][x-1]!='W')
			add(x-1,y,val+1), Short[y][x-1] = val+1 ,ch[y][x-1] = true;
		
		if(y+1<n)	
		if(ch[y+1][x]==false and Map[y+1][x]!='W')
			add(x,y+1,val+1), Short[y+1][x] = val+1 ,ch[y+1][x] = true;
		
		if(x+1<m)	
		if(ch[y][x+1]==false and Map[y][x+1]!='W')
			add(x+1,y,val+1), Short[y][x+1] = val+1 ,ch[y][x+1] = true;
	}
}


int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",Map[i]);
		for(int j=0;j<m;j++)
		if(Map[i][j]=='X')
			add(j,i,0);
	}
	
	bfs();
	int sum = 0,num = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		if(Map[i][j]=='A' and ch[i][j]==true)
		{
			sum += Short[i][j]*2;
			num++;
		}
			
	printf("%d %d",num,sum);		
	return 0;
}
