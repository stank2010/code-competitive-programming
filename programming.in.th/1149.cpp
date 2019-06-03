#include "stdio.h"
#include "cstring"
#include "algorithm"
int z[1001][1001],n,max;
int map[1001][1001],k1[1000002],l1,M_BT[1000002],L_BT;

struct pair
{
	int x,y;
}st,end;

/*
struct stank
{
	int x,y,a;
}DFS[1000001];
*/

pair set(int X,int Y)
{
	pair a;
	a.x=X;
	a.y=Y;
	return a;
}



void dfs(int X,int Y,int a)
{
	
	
	
	if(map[Y][X]==-1)
	{
		map[Y][X]=1;
		
		if(Y+1<n)
			if(map[Y+1][X]==-1&&z[Y+1][X] <= a)
				dfs(X,Y+1,a);
				
		if(Y-1>=0)
			if(map[Y-1][X]==-1&&z[Y-1][X] <= a)
				dfs(X,Y-1,a);
				
		if(X+1<n)
			if(map[Y][X+1]==-1&&z[Y][X+1] <= a)
				dfs(X+1,Y,a);
				
		if(X-1>=0)
			if(map[Y][X-1]==-1&&z[Y][X-1] <= a)
				dfs(X-1,Y,a);
	}
}

bool ch(int a)
{
	std::memset(map,-1,sizeof map);
	dfs(st.x,st.y,a);
	return map[end.y][end.x]==1;
}

int bs()
{
	z[st.y][st.x] = -1;
	
	int Head=0,Tail=L_BT-1,MID,MIN=M_BT[Tail];
	
	while(Head<=Tail)
	{
		MID=(Head+Tail)/2;
		
		if( ch( M_BT[MID] )) 
		{
			if(M_BT[MID] < MIN)
				MIN = M_BT[MID];
			Tail=MID-1;
		}	
		else 
			Head=MID+1;
	}	
	return MIN;
}

int main()
{
	scanf("%d",&n);
	
	st.x=-1;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&z[i][j]);
			
			k1[l1++]=z[i][j];
			
			if(z[i][j]==0)
			{
				if(st.x==-1)
					st=set(j,i);
				else 
					end=set(j,i);
			}
		}
		
	std::sort(k1,k1+l1);	
	std::memset(map,-1,sizeof map);
	
	for(int i=0;i<l1;i++)
		if(k1[i]!=k1[i+1])
			M_BT[L_BT++]=k1[i];
	
	
	printf("%d",bs());
	return 0;
}
