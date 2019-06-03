#include "stdio.h"

int z[3001][3001];

int main()
{
	int n,x,y,X,Y;
	scanf("%d",&n);
	x=X=1500;
	y=Y=1500;
	z[y][x]=1;
	
	if(n>1)
	{
		int l=0,w;
		while(l<n-1)
		{
			if(l%4==0)
			{
				w=Y-y+1;
				for(int i=y;i<y+w;i++)
					for(int j=X+1;j<=X+w;j++)
						z[i][j]=l+2;
				Y=y+w-1;
				X=X+w;
			}
			
			else if(l%4==1)
			{
				w=X-x+1;
				for(int i=Y+1;i<=Y+w;i++)
					for(int j=x;j<x+w;j++)
						z[i][j]=l+2;
				Y=Y+w;
			}
			
			else if(l%4==2)
			{
				w=Y-y+1;
				for(int i=y;i<=y+w;i++)
					for(int j=x-1;j>=x-w;j--)
						z[i][j]=l+2;
				x=x-w;
			}	
			else if(l%4==3)
			{
				w=X-x+1;	
				for(int i=y-1;i>=y-w;i--)
					for(int j=x;j<=x+w;j++)
						z[i][j]=l+2;
				y=y-w;
				
			}
			
			l++;
		}
	}
	for(int i=y;i<=Y;i++,printf("\n"))
		for(int j=x;j<=X;j++)printf("%c",z[i][j]+'A'-1);
	return 0;
}
