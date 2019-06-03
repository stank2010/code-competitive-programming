#include "stdio.h"

int z[1001];
bool ch[1001];
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",&z[i]);
	
	for(int i=0;i<k;i++)
	{
		int sp=-1,max=-100001;
		
		for(int j=0;j<n-1;j++)
		if(z[j]>z[j+1])
		{
			sp=j;
			break;
		}
		
		if(sp==-1)
		for(int j=0;j<n;j++)
		if(z[j]>max)
			max=z[j],sp=j;
		
		
		for(int i=sp;i<n;i++)
		{
			z[i]=z[i+1];
		}
		n--;
		//if(sp!=-1)ch[sp]=1;
	}
	
	for(int i=0;i<n;i++)
		printf("%d ",z[i]);
	
	return 0;
}
