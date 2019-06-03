#include "stdio.h"

int main()
{
	long long a,b,c,A,B;
	scanf("%lld %lld",&a,&b);
	A=a;
	B=b;
	while(a!=b&&a>0&&b>0)
	{
		if(a>b)
			a-=b;
		if(b>a)
			b-=a;	
	}
	printf("%lld",B/a*A);
	return 0;
}
