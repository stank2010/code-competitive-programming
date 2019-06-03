#include "stdio.h"

bool z[1000000];
int num[2]={0};
int main()
{
	int n,a;
	scanf("%d",&n);
	num[0]=num[1]=n;
	
	for(int i=0;i<n*2;i++)
	{
		scanf("%d",&a);
		z[i]=a%2;
		if(i>1&&z[i-1]==z[i-2]&&z[i-1]==z[i])
		 	num[(z[i]+1)%2]-=3;
		else 
		    num[(z[i]+1)%2]--;
		
		if(num[0]<=0)
		{
		printf("1\n%d",a);
		break;		
		}	
		else if(num[1]<=0)
		{
		printf("0\n%d",a);
		break;	
		}	
	}
	 
	return 0;
}
