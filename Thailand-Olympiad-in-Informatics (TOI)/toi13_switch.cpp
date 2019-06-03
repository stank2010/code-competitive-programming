#include "stdio.h"

int n;
char z[5000001];

int main()
{
	scanf("%d %s",&n,z);
	
	for(int i=1;i<=n;i++)
	if(n%i==0)
	{
		bool ch = 1;
		
		for(int j=0;j<i;j++)
		{
			for(int I=0;I<n;I+=i)
				if(z[I+j]!=z[j])
					ch = 0;
	
		}
		
		if(ch)
		{
			printf("%d",i);
			break;
		}
	}
	
	return 0;
}
