#include "stdio.h"

int doing(struct U *a,int lo,int hi);
void quick(struct U *a,int lo,int hi);
bool ch(struct U a,struct U b);
struct U{
	int x,y;
}q[300001];

int z[300001];


void quick(struct U *a,int lo,int hi)
{
	if(lo<hi)
	{
		int p=doing(a,lo,hi);
		quick(a,lo,p-1);
		quick(a,p+1,hi);
	}
}

int doing(struct U *a,int lo,int hi)
{
	struct U pivot=a[hi],swap;
	
	int i=lo;
	
	for(int j=lo;j<hi;j++)
	if(!ch(pivot,a[j]))
	{
		swap=a[j];
		a[j]=a[i];
		a[i]=swap;
		i++;
	}
	
	swap=a[hi];
	a[hi]=a[i];
	a[i]=swap;
		
	return i;
}

bool ch(struct U a,struct U b)
{
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}

int main()
{
	int n,a;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&q[i].x,&q[i].y);
		if(q[i].x>q[i].y)
		{
			a=q[i].x;
			q[i].x=q[i].y;
			q[i].y=a;
		}
	}
	
	quick(q,0,n-2);

	int max=0;
	for(int i=0;i<n-1;i++)//
	if(z[q[i].x]+1>z[q[i].y])
	{
		z[q[i].y]=z[q[i].x]+1;
	}
	
	for(int i=1;i<=n;i++)
		if(z[i]>max)max=z[i];
	//for(int i=0;i<=n-2;i++)printf(" %d %d\n",q[i].x,q[i].y);
	printf("%d",max+1);
	return 0;
}
