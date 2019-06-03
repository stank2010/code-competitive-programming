#include "stdio.h"
#define A1(A) (A>=0)?A:0
#define A2(A) (A<=1001)?A:1001
int z[1002][1002],qs[1002][1002],ans[1000000];
int n,m,a,b,c,m1=0,m2=0,m3=0;
int ca[1002],cb[1002],cc[1002];

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf(" %d %d",&a,&b);
		z[b+1][a+1]++;
	}
		
	for(int i=1;i<=1001;i++)
		for(int j=1;j<=1001;j++)
			qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+z[i][j];
	
	for(int i=0;i<m;i++)
	{
		scanf(" %d %d %d",&a,&b,&c);
		a++,b++;
		ans[i]=qs[A2(b+c)][A2(a+c)]+qs[A1(b-c-1)][A1(a-c-1)]-qs[A1(b-c-1)][A2(a+c)]-qs[A2(b+c)][A1(a-c-1)];
	}	
	for(int i=0;i<m;i++)
		printf("%d\n",ans[i]);
			
	return 0;
}
