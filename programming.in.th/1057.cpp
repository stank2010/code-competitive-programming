#include "stdio.h"
bool q[1000];
int node[1000][1000],T[1000];


bool deng(int x,bool *a)
{
	if(a[x])
		return 1;
	else
		a[x]=1;
		
	for(int i=0;i<T[x];i++)
	{
		if(deng(node[x][i],a))
			return 1;		
	}
	return 0;
}

int main()
{
	int n,m,a;
	scanf("%d",&n);	
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&T[i]);
		for(int j=0;j<T[i];j++)
		{
			scanf(" %d",&node[i][j]);
			node[i][j]--;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		bool z[1000]={0};
		if(T[i]>0)
			q[i]=deng(i,z);
		else
			q[i]=0;
	}
	
	for(int i=0;i<n;i++)
	if(q[i])
		printf("YES\n");
	else 
		printf("NO\n");
	
	return 0;
}
