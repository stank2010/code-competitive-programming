#include "stdio.h"
#define ch(g) (g>=0)?g:1000001
int z[1000002];

struct oe{
	int odd,even;
}v[2000002];

unsigned long long l;
int main()
{
	int i=1,n,A,k,sp=1,p;
	scanf("%d %d",&n,&k);
	/*
	for(int i=0;i<=2000001;i++)
		v[i].even=v[i].odd=0;
	*/	
	for(i=1;i<=n;i++)
	{
		scanf(" %d",&A);
		if(A<k)z[i]=z[i-1]-1;
	else if(A>k)z[i]=z[i-1]+1;
	else sp=i,z[i]=z[i-1];
	}
	
	for(i=0;i<=n;i++)
	{
		p=z[i]+1000000;
	//if(v[p].even&&v[p].odd)
		if(i%2)v[p].odd++;
		else v[p].even++;
		
		if(i%2==0)l+=v[p].odd;
		else l+=v[p].even;		
	//printf("%d : %dO %dE\t%d\n",z[i],v[p].odd,v[p].even,l);
	}
	
	
	printf("%llu",l);	
	return 0;
}
