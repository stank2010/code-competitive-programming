#include "stdio.h"

int a,b,k,match[2]={0},z[100000];


void sp(int n,int a)
{
	z[n]=a;
	if((match[0]==k||match[1]==k)&&n<2*k)
	{
		for(int i=0;i<=n;i++)
		 printf("%c ",z[i]);
		 printf("\n");
		return;
	}
	
	match[0]++;
	sp(n+1,'W');
	match[0]--;
	
	match[1]++;
	sp(n+1,'L');
	match[1]--;
}

int main()
{
	scanf("%d %d %d",&k,&a,&b);
 	match[0]=a;
 	match[1]=b;
 	
 	match[0]++;
	sp(0,'W');
	match[0]--;
	
	match[1]++;
	sp(0,'L');
	match[1]--;
 	
	return 0;
}
