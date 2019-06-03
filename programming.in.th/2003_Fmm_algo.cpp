#include "stdio.h"

int dp[2][4][4][4][4],n;
char z[100001];

int max(int a,int b){return (a<b)?b:a;}

int food(char a)
{
	if(a=='F')return 1;
	if(a=='B')return 2;
	if(a=='M')return 3;
	return 0;
}

int val(int a,int b,int c)
{
	int num=0;
	
	if(a==1||b==1||c==1)
		num++;
	if(a==2||b==2||c==2)
		num++;
	if(a==3||b==3||c==3)
		num++;
	
	return num;
}

void set()
{
	int N=food(z[0]);
	dp[0][N][0][0][0] = 1;
	dp[0][0][0][N][0] = 1;
}


int main()
{
	
	scanf("%d %s",&n,z);
	
	set();
	
	int This=0,That=1;
	
	for(int a=1;a<n;a++)
	{
		int N=food(z[a]);
		
		for(int i=0;i<=3;i++)
			for(int j=0;j<=3;j++)
				for(int k=0;k<=3;k++)
					for(int l=0;l<=3;l++)
					if( dp[This][i][j][k][l] > 0 )
					{
		
							if(l!=0)
								dp[That][i][j][l][N] = max( dp[That][i][j][l][N] , dp[This][i][j][k][l] + val(k,l,N) );
							else 
							 	dp[That][i][j][k][N] = max( dp[That][i][j][k][N] , dp[This][i][j][k][l] + val(k,N,0) );
							 	
							if(j!=0)
								dp[That][j][N][k][l] = max( dp[That][j][N][k][l] , dp[This][i][j][k][l] + val(i,j,N) );
							else
							  	dp[That][i][N][k][l] = max( dp[That][i][N][k][l] , dp[This][i][j][k][l] + val(i,N,0) );
					}
					
		This=!This;
		That=!That;
	}
	
	int val_max=0;
	for(int i=0;i<=3;i++)
		for(int j=0;j<=3;j++)
			for(int k=0;k<=3;k++)
				for(int l=0;l<=3;l++)
					val_max = max( val_max , dp[This][i][j][k][l] );
	
	printf("%d",val_max);
	return 0;
}
