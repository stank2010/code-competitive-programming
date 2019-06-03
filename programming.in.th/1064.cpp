#include "stdio.h"
#include "math.h"
char z[66][66];
int a[66][66],b[66][66],k=0,c,r,water[100000],t,st[100000],sta;

void dfs(int x,int y)
{
	if(z[y-1][x-1]=='P'&&b[y][x]==0)
	{
		
		b[y][x]=k;
		if(x-1>0)dfs(x-1,y);
		if(y-1>0)dfs(x,y-1);
		if(x+1<=c)dfs(x+1,y);
		if(y+1<=r)dfs(x,y+1);
	}
}

int main()
{
	int i,j;
	scanf("%d %d",&c,&r);
	for(i=0;i<r;i++)
		scanf("%s",z[i]);
	
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			
			if(z[i][j]=='P'&&b[i+1][j+1]==0)
			{
				
				k++;
				dfs(j+1,i+1);
			}
			a[i+1][j+1]=a[i][j+1]+a[i+1][j]-a[i][j]+1;
		}
	
	int r1,r2,max=0,l=0,w,h,y;
	
	for(r1=1;r1<=r;r1++)
		for(r2=1;r2<=c;r2++)
			for(i=r1+1;i<=r;i++)
				for(j=r2+1;j<=c;j++)
				if(i-r1==j-r2)
				{
					sta=t=0;
					for(h=r1;h<=i;h++)
						for(w=r2;w<=j;w++)
						{
							if(z[h-1][w-1]=='T')t=1;
							if(b[h][w]>0&&water[b[h][w]]==0)
							{
							water[b[h][w]]=1;
							st[sta++]=b[h][w];
							}
						}
					//printf("%d ",sta);	
					if(t==0)
					{
					int o=a[i][j]-a[i][r2-1]-a[r1-1][j]+a[r1-1][r2-1];
					if(o>=max)
					{
						
						if(o==max)
						{
							if(sta<l)
								l=sta;
						}	
						else
						{
							max=o;
							l=sta;
						}
						//printf("%d %d (%d %d) to (%d %d)\n",max,l,r2,r1,j,i);				
					}
					}
					for(h=0;h<sta;h++)
						water[st[h]]=0;
				}
	/*
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
			printf("%d ",b[i][j]);
		puts(" ");	
	}
	*/	
	printf("%d %d",max,l);
	return 0;
}
