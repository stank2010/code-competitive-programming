#include "stdio.h"

int n,z[21][21],k,H,L;

int dfs(int x,int y,int h,int l)
{
	if(z[y][x]==k)
	{
		z[y][x]=0;
		if(h>H)H=h;  if(l>L)L=l;
		int s=0;
		if(x-1>=1)dfs(x-1,y,h,l+1);
		if(y-1>=1)dfs(x,y-1,h+1,l);
		if(x+1<=n)dfs(x+1,y,h,l+1);
		if(y+1<=n)dfs(x,y+1,h+1,l);
	}
}


int main()
{
	int o=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&z[i][j]);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(z[i][j])
		{
			k=z[i][j];	
			H=L=0;
			dfs(j,i,0,0);
			if(H==L&&H==1)o++; 
		}
	printf("%d",o);
	return 0;
}
