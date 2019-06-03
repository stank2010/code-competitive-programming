#include "stdio.h"

bool z[100][40],BB=0;
int m,n,t,L[100];


void ride(int l,int T,int a)
{
	if(!z[T][l]&&!BB)
	{
		L[T]=a;
	if(T==t-1)
	{
		for(int i=0;i<t;i++)
			printf("%d\n",L[i]);
		BB=1;
		return;	
	}
	
	if(l+1<m)	
		ride(l+1,T+1,2);	
	if(l-1>=0)	
		ride(l-1,T+1,1);
	ride(l,T+1,3);
	}
}


int main()
{
	scanf("%d %d %d",&m,&n,&t);
	for(int j=0;j<t;j++)
	for(int i=0;i<m;i++)
		scanf("%d",&z[j][i]);
	n--;
	if(n+1<m)	
		ride(n+1,0,2);	
	if(n-1>=0)	
		ride(n-1,0,1);
	ride(n,0,3);
	
	return 0;
}
