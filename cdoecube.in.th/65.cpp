#include "stdio.h"

int n,a[3],max,sp;

bool ch(int A)
{
	return (A<max&&A>0);
}

int main()
{
	
	scanf("%d %d %d %d",&n,&a[0],&a[1],&a[2]);
	
	for(int i=0;i<n;i++)
	{
		max=1000000;sp=-1;
		
		for(int j=0;j<3;j++)
		if(ch(a[j]-a[i%3]) && i%3!=j)
		{
			max=a[j]-a[i%3];
			sp=j;
		}
		
		if(sp!=-1)a[i%3]=a[sp]+a[sp]-a[i%3];
	}
	for(int i=0;i<3;i++)printf("%d\n",a[i]);
	return 0;
}
