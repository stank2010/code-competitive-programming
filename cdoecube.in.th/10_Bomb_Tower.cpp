#include "stdio.h"

bool z[500001]={0};

int main()
{
	int n,m,o=0;
	scanf("%d %d",&n,&m);
	
		for(int i=2;i<=n;i++)	
		if(z[i]==0)
		{
		o++;	
			for(int j=i;j<=n;j+=i)
				if(z[j]==0)
				z[j]=1;
		}
	
	if(m>=o)
	printf("0");
	else
	printf("%d",o-m);
	return 0;
}
