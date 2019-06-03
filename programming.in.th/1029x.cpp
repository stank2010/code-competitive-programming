#include "stdio.h"
#include "algorithm"
struct U{
	int x,r;
}z[300000],Q[100001],eiei[100001];

int l,ans[100001],ei,st,s[100001];

bool ch(U a,U b)
{
	if(a.x==b.x)return a.r>b.r;
	return a.x<b.x;
}

int main()
{
	int n,m,q,a,b;
	scanf("%d %d %d",&n,&m,&q);
	
	z[l].x=0;	z[l].r=0;	l++;
	z[l].x=1;	z[l].r=0;	l++;
	z[l].x=n+1;	z[l].r=0;	l++;
	
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		z[l].x=a;	z[l].r=1;	l++;
		z[l].x=a+b; z[l].r=-1;	l++;	
	}
	
	for(int i=0;i<q;i++)scanf("%d",&Q[i].x),Q[i].r=q-i;
	
	std::sort(z,z+l,ch);
	std::sort(Q,Q+q,ch);
	int qq=0;
	
	for(int i=1;i<l;i++)
	if(z[i].x!=z[i-1].x)
	{
		eiei[++ei].x=z[i].x;
		eiei[ei].r=eiei[ei-1].r+z[i].r;
	}
	else eiei[ei].r+=z[i].r;
	
	s[st++]=0;
	s[st++]=eiei[1].x;
	for(int i=2;i<=ei;i++)
	if(eiei[i].r%2!=eiei[i-1].r%2)
	{
		s[st++]=eiei[i].x;
	}
	s[st++]=n+1;
	/*for(int i=0;i<=ei;i++)
		printf("%d(%d)\n",eiei[i].x,eiei[i].r%2);*/
	for(int i=1;i<st;i++)
	{
		if(s[i]>Q[qq].x)
		{
			while(qq<q&&s[i]>Q[qq].x)
			{
				ans[q-Q[qq].r]=s[i]-s[i-1];
				//printf("%d %d\n",ans[q-Q[qq].r],q-Q[qq].r);
				qq++;
			}
		}
		//printf("%d ",s[i]);
	}
	for(int i=0;i<q;i++)
		printf("%d\n",ans[i]);
	return 0;
}
