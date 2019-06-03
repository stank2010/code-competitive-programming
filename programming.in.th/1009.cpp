#include "stdio.h"

char A[4][200],B[4][200],C[200];

char a[11][4][4];

void set()
{
	a[0][0][1]=a[0][2][1]='_';
	a[0][1][0]=a[0][1][2]=a[0][2][0]=a[0][2][2]='|';
	
	a[1][1][2]=a[1][2][2]='|';

	a[2][1][2]=a[2][2][0]='|';
	
	a[3][1][2]=a[3][2][2]='|';
	
	a[4][1][2]=a[4][2][2]=a[4][1][0]='|';
	a[4][1][1]='_';
	
	a[5][1][0]=a[5][2][2]='|';
	
	a[6][1][0]=a[6][2][0]=a[6][2][2]='|';
	
	a[7][1][2]=a[7][2][2]='|';
	a[7][0][1]='_';
	
	a[8][1][0]=a[8][1][2]=a[8][2][0]=a[8][2][2]='|';
	
	a[9][1][2]=a[9][2][2]=a[9][1][0]='|';
	int n[6]={2,3,5,6,8,9};
	for(int i=0;i<6;i++)
		a[n[i]][0][1]=a[n[i]][1][1]=a[n[i]][2][1]='_';
}

bool show(int l)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			if(a[l][i][j]!=0)
				printf("%c",a[l][i][j]);
			else printf(" ");
		puts(" ");
	}
}

bool ch(int l,int x,int y,char z[4][200])
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(z[y+i][x+j]!=a[l][i][j])
			return 0;
	return 1;
}

int main()
{
	set();
	
	long long c=0,aa=1,bb=1;
	
	int n,m;
	scanf("%d %d",&n,&m);
	gets(C);
	for(int i=0;i<3;i++)
		gets(A[i]);
	for(int i=0;i<3;i++)
		gets(B[i]);
	
	for(int i=0;i<3;i++)
		for(int j=0;j<4*n;j++)
			if(A[i][j]==' ')A[i][j]=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<4*m;j++)
			if(B[i][j]==' ')B[i][j]=0;
	
	for(int i=4*n-4;i>=0;i-=4)		
	for(int j=0;j<10;j++)
	{
		if(ch(j,i,0,A))
		{
			c+=aa*j;
			aa*=10;
			break;	
		}	
	}
	
	
	for(int i=4*m-4;i>=0;i-=4)		
	for(int j=0;j<10;j++)
	{
		if(ch(j,i,0,B))
		{
			c+=bb*j;
			bb*=10;
			break;	
		}	
	}
	printf("%lld",c);
	return 0;
}
