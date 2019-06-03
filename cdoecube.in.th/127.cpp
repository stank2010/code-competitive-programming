#include "stdio.h"

int main()
{
	int n,x;
	scanf("%d %d",&n,&x);
	
	if(x>=4)
	{
		printf("3-2-1");
		for(int i=4;i<=n;i++)
		if(i!=x)printf("*%d",i);
		printf("+%d",x);
	}
	else if(x==2)
	{
		if(n==2)printf("2*1");
		else if(n==3)printf("3-2+1");
		else if(n>=4)
		{
			printf("4-3-1");
			for(int i=5;i<=n;i++)printf("*%d",i);
			printf("+2");	
		}	
	}
	else if(x==3)
	{
		if(n==3)printf("2-1*3");
		else if(n==4)printf("4-2-1*3");
		else if(n>=5)
		{
			printf("5+1-4-2");
			for(int i=6;i<=n;i++)printf("*%d",i);
			printf("+3");
		}
	}
	else if(x==1)
	{
		if(n==2)printf("2-1");
		else if(n==3)printf("3*1-2");
		else if(n==4)printf("3*2-4-1");
		else if(n>=5)
		{
			printf("5+2-4-3");
			for(int i=6;i<=n;i++)
			printf("*%d",i);
			printf("+1");
		}
	}
	return 0;
}
