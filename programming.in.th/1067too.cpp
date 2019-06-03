#include "stdio.h"

int z[101][101],n,m;

void dfs(int x,int y,bool ch[101][101])
{
	if(ch[y][x]==0)
	{
		ch[y][x]=1;
		if(z[y][x]==1)
		{
			if(y==0)printf("N\n");
			else dfs(x,y-1,ch);
		}
		else if(z[y][x]==2)
		{
			if(x+1==m)printf("E\n");
			else dfs(x+1,y,ch);
		}
		else if(z[y][x]==3)
		{
			if(y+1==n)printf("S\n");
			else dfs(x,y+1,ch);	
		}
		else if(z[y][x]==4)
		{
			if(x==0)printf("W\n");
			else dfs(x-1,y,ch);
		}
	
	}
	else printf("NO\n");
}

main()
{
	int k,a,b;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&z[i][j]);
	
	for(int i=0;i<k;i++)	
	{
		bool ch[101][101]={0};
		scanf("%d %d",&a,&b);
		dfs(a-1,b-1,ch);	
	}
	
	return 0;
}
