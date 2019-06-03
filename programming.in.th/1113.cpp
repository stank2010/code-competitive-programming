#include "stdio.h"
#include "map"
char z[1000001];
long long int x[1000002];
std::map<long long int,int> q;

int main()
{
int n,k,s=0,h=0,j;

scanf("%d %d ",&n,&k);	
scanf("%s",z);
int fm;
for(int i=1;i<=n;i++)
{
	if(z[i-1]=='R')x[i]=x[i-1]-k;	
	else x[i]=x[i-1]+1;
	fm = q[x[i]];
	if(fm>0)
	{
		if(i-fm>s)s=i-fm;	
	}
	else if(x[i]==0)
	{
		if(i > s)s=i;
	}
	else q[x[i]]=i;
}

printf("%d",s);
return 0;
}
