#include "stdio.h"

int main()
{
	int a,b,c;
	scanf("%d %d",&a,&b);
	
	while(a!=b&&a>0&&b>0)
	{
		if(a>b)
			a-=b;
		if(b>a)
			b-=a;	
	}
	printf("%d",a);
	return 0;
}
