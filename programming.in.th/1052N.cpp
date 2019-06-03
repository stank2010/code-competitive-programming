#include "stdio.h"
struct domino{
	int x,y;
}z[100000];


struct out{
int v;
int num;
}MAX[2];


int dp[100000];
int main()
{
	int n,cp,Max;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&z[i].x,&z[i].y);	
	
	Max=z[0].x+z[0].y;
	cp=dp[0]=MAX[0].v=MAX[0].num=0;
	//left->Right  (R)
	for(int i=1;i<n;i++)
	{
		if(z[i].x<Max)
			dp[i]=dp[i-1]+1;		
		else
			dp[i]=0,cp=i;	
		
		if(z[i].x+z[i].y>Max)
			Max=z[i].x+z[i].y;	
		
		if(dp[i]>MAX[0].v)
		{
			MAX[0].v=dp[i];
			MAX[0].num=cp;
		}
	}
	
	cp=MAX[1].num=n-1;
	dp[n-1]=MAX[1].v=0;
	Max=z[n-1].x-z[n-1].y;
	//Right to Left (L)
	for(int i=n-2;i>=0;i--)
	{
		if(z[i].x>Max)
			dp[i]=dp[i+1]+1;
		else
			dp[i]=0,cp=i;
	
		if(z[i].x-z[i].y<Max)
			Max=z[i].x-z[i].y;
		
		if(dp[i]>MAX[1].v)
		{
			MAX[1].v=dp[i];
			MAX[1].num=cp;
		}
	}
	//printf("%d %d R\n%d %d L\n",MAX[0].num,MAX[0].v,MAX[1].num,MAX[1].v);
	MAX[0].num++;
	MAX[1].num++;
	
	if(MAX[1].v>MAX[0].v)
		printf("%d L",MAX[1].num);
	else 
		if(MAX[0].v>MAX[1].v)
			printf("%d R",MAX[0].num);
		
		else if(MAX[0].v==0&&MAX[1].v==0)
			printf("1 L");
			else
			{
			if(MAX[1].num<=MAX[0].num)
				printf("%d L",MAX[1].num);
			else
				printf("%d R ",MAX[0].num);
			}
			
	return 0;
}
