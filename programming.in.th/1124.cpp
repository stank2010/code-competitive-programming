#include "stdio.h"

int n;
bool BOOL=0,ch[21];
long long z[21];

long long abs(long long a){return (a<0)?-a:a;}
int unit(long long a){return (a>0)?-1:1;}

void re(long long cost,long long val,int count)
{
	if(BOOL)return;
	
	//for(int i=0;i<19;i++)
	//printf(" = %lld %lld %d\n",cost,val,count);
	
	if(cost!=0)
	{
		int U=unit(cost),EIEI=1;
		for(int i=0;i<=19;i++)
		if(z[i]>=abs(cost))
		{
			EIEI=0;
			if(!ch[i])ch[i]=1,re(cost+U*z[i],val+((U<0)?z[i]:0),count+1),ch[i]=0;
			
			if(i>0)
			{
				if(!ch[i-1])ch[i-1]=1,re(cost+U*z[i-1],val+((U<0)?z[i-1]:0),count+1),ch[i-1]=0;
			}
			
			break;
		}
		
		if(EIEI)
		for(int i=19;i>=0;i--)
		if(!ch[i])
		{
			ch[i]=1,re(cost+U*z[i],val+((U<0)?z[i]:0),count+1),ch[i]=0;
			break;
		}
	}
	else 
	{
		printf("%d %lld",count,val);
		BOOL=1;
	}
}

int main()
{
	z[0]=1;
	for(int i=1;i<=19;i++)
		z[i]=z[i-1]*3;
	
	scanf("%d",&n);
	re((long long)n,0,0);
	return 0;
}
