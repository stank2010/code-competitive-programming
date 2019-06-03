#include "stdio.h"

char x[3000001],g[3001];

int main()
{
	int n,m,z[63]={0},t[63]={0},h=0,o=0,b=0;
	scanf("%d %d ",&n,&m);
	scanf("%s %s",g,x);
	
	for(int i=0;i<n;i++)
	{
		t[g[i]-'A']++;	
	}
	
	for(int i=0;i<m;i++)
	{
		z[x[i]-'A']++;
		if(i-h==n-1)
		{
			b=1;
			for(int j=0;j<63;j++)
				if(z[j]!=t[j])
				{
					b=0;
					break;
				}
			if(b)o++;	
			z[x[h]-'A']--;
			h++;
		}
	}
	printf("%d",o);
	return 0;
}
