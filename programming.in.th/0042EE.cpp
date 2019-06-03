#include "stdio.h"

int main()
{
	int n,A;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A);
		
		long double a=1; 
		while(A-- > 0)
			a*=2;

		printf("%.0Lf\n",a);
	}
	return 0;
}
