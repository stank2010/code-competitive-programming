#include "stdio.h"


int Q[100000],parent[100001];
long long z[100001];

int find(int x)
{
    if(x!=parent[x])
        return find(parent[x]);
    else
        return x;
}

void win(int x,int y)
{
	int X=find(x),Y=find(y);
	parent[Y]=X;
	z[Y]/=2;
	z[X]+=z[Y];
}

int main()
{
	int m,n,a,b;
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&z[i]);
		parent[i]=i;
	}
	
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		int ha=find(a),hb=find(b);
		
		if(ha==hb)
			Q[i]=-1;
		
		else if(z[ha]==z[hb])
		{
			if(ha<hb)
			{
			win(a,b);
			Q[i]=find(a);	
			}
			else
			{
			win(b,a);
			Q[i]=find(b);
			}	
		}
		
		else if(z[ha]>z[hb])
		{
		win(a,b);
		Q[i]=find(a);	
		}	
		
		else 
		{
		win(b,a);
		Q[i]=find(b);	
		}
		
		//for(int j=1;j<=n;j++)printf("%d ",parent[j]);
		//printf("\n");
	}
	
	
	for(int i=0;i<m;i++)
		printf("%d\n",Q[i]);
	return 0;
}
