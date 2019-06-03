#include "stdio.h"
#include "string.h"

int mem[1001][1001];

char X[1001] , Y[1001]; // X size m and Y size n
char Z[2001];

bool LCS(int m,int n)
{
	if(mem[m][n] != -1)
		return mem[m][n];
	
	if(m == 0 and n == 0)
		return mem[m][n] = 1;
	
	if(m == 0)
		return mem[m][n] = (Z[n] == Y[n] and LCS(m,n-1));
	
	if(n == 0)
		return mem[m][n] = (Z[m] == X[m] and LCS(m-1,n));
	
	bool Check = (Z[m+n] == X[m] and LCS(m-1,n)) or (Z[m+n] == Y[n] and LCS(m,n-1));
	
	return mem[m][n] = Check;
}

int main()
{
	int k;
	scanf("%s %s %d",X+1,Y+1,&k);
	int len_X = strlen(X+1), len_Y = strlen(Y+1);
	
	for(int i=0;i<k;i++)
	{
		scanf("%s",Z+1);
		
		
		for(int x=0;x<=len_X;x++)
			for(int y=0;y<=len_Y;y++)
				mem[x][y] = -1;
		
		printf("%s\n", LCS(len_X,len_Y) ?"Yes":"No" );
	}
	return 0;
}
