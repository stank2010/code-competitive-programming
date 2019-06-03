#include "stdio.h"

int q[1000][1000],z[1000][1000],max=0;

int main()
{
	int m,n,k,x,y;
	scanf("%d %d %d",&m,&n,&k);
	//k--;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&z[i][j]);
			
				q[i][j]=z[i][j];
			if(i>0)
				q[i][j]+=q[i-1][j];			
			if(j>0) 
				q[i][j]+=q[i][j-1];
			if(j>0&&i>0)
				q[i][j]-=q[i-1][j-1];		
		}
	}
	/*
	printf("\n\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		printf("%d ",q[i][j]);
		printf("\n");
	}*/
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		if(i+k<m&&j+k<n)
			if(q[i+k][j+k]-q[i+k][j]-q[i][j+k]+q[i][j]>max) //-q[i+k][j]-q[i][j+k]+q[i][j]
				max=q[i+k][j+k]-q[i+k][j]-q[i][j+k]+q[i][j];
				
	printf("%d",max);
	
	return 0;
}
