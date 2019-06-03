#include "stdio.h"

int z[201][201],mark[201][201],r,c;
char ei[201][201];

int count(int i,int j,int C)
{
	return z[i+C][j+C]+z[i][j]-z[i+C][j]-z[i][j+C];
}

int main()
{
	scanf("%d %d ",&r,&c);
	for(int i=1;i<=r;i++)
	{	
		scanf("%s",ei[i]);
		for(int j=c;j>0;j--)
			ei[i][j]=ei[i][j-1];
		ei[i][0]=0;
	}	
	
	for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
	{
		z[i][j]=z[i-1][j]+z[i][j-1]-z[i-1][j-1];
		if(ei[i][j]=='x')z[i][j]++;
	}

	for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
	if(ei[i][j]=='x'&&ei[i][j-1]!='x'&&ei[i-1][j]!='x'&&ei[i-1][j-1]!='x')
	{
		int C=1;
		while(count(i-1,j-1,C)==C*C)C++;
		mark[i][j]=C-1;
	}
	else if(ei[i][j]=='x'&&ei[i][j+1]!='x'&&ei[i+1][j]!='x'&&ei[i+1][j+1]!='x')
	{
		int C=1;
		while(i-C>0&&j-C>0&&count(i-C,j-C,C)==C*C)C++;
		if(C-1 > mark[i-(C-2)][j-(C-2)])mark[i-(C-2)][j-(C-2)]=C-1;
		//printf("val= %d  %d %d %d(%d %d)\n",mark[i-(C-1)][j-(C-1)],i-(C-1),j-(C-1),C,i,j);
	}
	/*
	else if(ei[i][j]=='x'&&ei[i][j-1]!='x'&&ei[i+1][j]!='x'&&ei[i+1][j-1]!='x')
	{
		int C=1;
		while(count(i-C,j-1,C)==C*C)C++;
		//printf("%d %d %d\n",i-(C-1),j,C);
		if(C-1>mark[i-(C-2)][j])mark[i-(C-2)][j]=C-1;
	}
	else if(ei[i][j]=='x'&&ei[i][j+1]!='x'&&ei[i-1][j]!='x'&&ei[i-1][j+1]!='x')
	{
		
		int C=1;
		while(count(i-1,j-C,C)==C*C)C++;
		if(C-1>mark[i][j-(C-2)])mark[i][j-(C-2)]=C-1;	
	}*/

	for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
	if(mark[i][j]>0)
	{
		printf("%d %d %d\n",i,j,mark[i][j]);
	}
	
	//puts("");for(int i=1;i<=r;i++,puts(""))for(int j=1;j<=c;j++)printf("%d ",mark[i][j]);
	
	return 0;
}
