#include "stdio.h"

int n,m;
int Map[101][101];
int dp[101][101][5001];

bool find(int x,int y,int t)
{
	//printf("%d %d %d\n",x,y,t);
	if(t==0 and x==0 and y==n/2+1 )
		return true;
	
	if(x<=0 or y<=0 or t<=0)
		return false;
	
	if(Map[y][x]==0)
		return false;
	
	if(Map[y][x] != 0 and t%Map[y][x]!=0)
		return false;
	
	if(dp[x][y][t]!=-1)
		return dp[x][y][t];
	
	if(y%2 == 0)
		return dp[x][y][t] = find(x,y-1,t-1) || find(x,y+1,t-1) || find(x-1,y-1,t-1) || find(x-1,y+1,t-1) || find(x-1,y,t-1) || find(x+1,y,t-1);
	else
		return dp[x][y][t] = find(x,y-1,t-1) || find(x,y+1,t-1) || find(x+1,y-1,t-1) || find(x+1,y+1,t-1) || find(x-1,y,t-1) || find(x+1,y,t-1);			
}
 
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			scanf("%d",&Map[i][j]);
	}
	
	for(int i=1;i<=5000;i++)
		for(int x=1;x<=m;x++)
			for(int y=1;y<=n;y++)
				dp[x][y][i] = -1;
	
	int k = Map[n/2+1][m] ;
	for(int i=1;i<=5000;i++)
	if(i%k==0)
	{
		if(find(m,n/2+1,i)==1)
		{
			printf("%d",i);
			break;	
		}	
	}
	
	return 0;
}
