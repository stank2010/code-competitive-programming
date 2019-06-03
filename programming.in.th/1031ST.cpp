#include "stdio.h"
#include "algorithm"
using namespace std;

typedef struct{
int x;
int y;
}st;


bool check(st a,st b)
{
	if(a.x==b.x)return a.y<b.y;
	else return a.x<b.x;
}

st M[100001];
int z[10001]={0};

int main()
{
	int k,n,m;
	scanf("%d %d %d",&k,&n,&m);
	for(int i=0;i<m;i++)scanf("%d %d",&M[i].x,&M[i].y);
	sort(M,M+m,check);
	
	for(int i=0;i<m;i++)
	{
		 if(M[i].x==1)z[M[i].y]=1;
	else if(z[M[i].x]>0)
	    {
		if(z[M[i].x]+1<z[M[i].y]||z[M[i].y]==0)z[M[i].y]=z[M[i].x]+1;
		}	
	}
	
	for(int i=n;i>0;i--)
	{
		if(z[i]<=k&&z[i]>0)
		{
			printf("%d",i);
			break;
		}
	}
	
	return 0;
}
