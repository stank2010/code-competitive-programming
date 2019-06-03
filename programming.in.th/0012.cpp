#include "stdio.h"
#include "string.h"

void first(int L)
{
	int k=0;
	for(int i=0;i<L;i++)
	{
		if((i-2)%4==0)
		{
			k++;
			if(k%3==0)printf("*");
			else printf("#");	
		}	
		else printf(".");
	}
	printf("\n");
}

void second(int L)
{
	int k=0;
	for(int i=0;i<L;i++)
	{
		if(i%2==1)
		{
			if(k%6==4||k%6==5)printf("*");
			else printf("#");
			k++;
		}
		else printf(".");
	}
	printf("\n");
}


int main()
{
	char z[25];
	int l,kuy=0,L,k=8,count=0;
	scanf("%s",z);
	l=strlen(z);
	L=l*4+1;
	first(L);
	second(L);
	
	for(int i=0;i<L;i++)
	{
		if(i%2==0)
		{
			if((i-2)%4==0)printf("%c",z[kuy++]);
			else if(i==k&&count/2<l/3)printf("*"),k+=12,count++;
			else if(count/2<l/3&&i%12==0&&i)printf("*"),count++;
			else printf("#");
		}
		else printf(".");
	}
	printf("\n");
	
	second(L);
	first(L);
	return 0;
}
