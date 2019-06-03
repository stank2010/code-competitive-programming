#include "stdio.h"

int main()
{
	int n,z[25],st[21]={0},k=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&z[i]);
	
	for(int i=2;i<=n;i++)
	{
		if(z[i-1]==0)
		{
			z[i-1]=1;
			z[i]=(z[i]+1)%2;
			z[i+1]=(z[i+1]+1)%2;
			k++;
		}
	}
	
	int b=1;
	for(int i=1;i<=n;i++)
		if(z[i]==0){b=0; break;}
	if(b)printf("%d",k); else printf("-1");
	return 0;
}
