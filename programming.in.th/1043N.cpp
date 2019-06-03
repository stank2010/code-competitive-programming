#include "stdio.h"
#include "math.h"

#define MAX 10000
#define AR 1300
bool p[MAX];
int P[AR],l;

void tg()
{
	for(int i=2;i<MAX;i++)
	if(!p[i])
	{
		P[l++]=i;
		int j=2;
		while(i*j<MAX)p[i*j++]=1;
	}
}

int gcd(int a,int b)
{
	int c;
	if(a>b)c=a,a=b,b=c;
	while(c!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}



int q[1001];
int main()
{
	int n,a,N;
	//printf("%d",gcd(256,6));
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&q[i]);
	tg();
	for(int i=0;i<N;i++)
	{
		n=q[i];
		int z[AR]={0},k=0;
	int st[AR]={0},L=0,g=1;
	for(int i=0;n>1&&i<l;i++)
	{
		while(n%P[i]==0)n/=P[i],z[i]++;
		if(z[i]>0)st[L++]=z[i];	
		//printf("%d %d %d\n",i,st[i]);
	}
	g=st[0];
	for(int i=1;i<L;i++)g=gcd(g,st[i]);
	if(g>1&&n==1)printf("%d\n",g);
	else printf("NO\n");
	}
	return 0;
}
