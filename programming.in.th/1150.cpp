#include "stdio.h"

int a[100001];
int z[1001],q[60000],Q;

int main()
{
	
	int n,o;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf(" %d",&z[i]);
	}

	
	for(int i=0;i<n;i++)
	{
		for(int j=-30000;j<=30000;j++)
		if(a[j+30000])
		{
			if(j+z[i]<-30000)
			{
				q[Q++]=90000+z[i]+j+1;
			}
			else if(j+z[i]>30000)
			{
				q[Q++]=(z[i]+j+30000)%60001;
			}
			else
			{
				q[Q++]=z[i]+j+30000;
			}	
		}
		else if(j==z[i])
		{
			a[z[i]+30000]=1;
		}
		
		
		while(Q>0)
		{
			a[q[Q-1]]=1;
			Q--;
		}
		
	}
	
	for(int i=60000;i>=30000;i--)
		if(a[i])
		{
			printf("%d ",i-30000);
			return 0;
		}
	printf("0");
	return 0;
}	

/*//printf("%d ",(z[i]+30000+j)%60001);
	if(j>z[i]+30000)
		a[(j-z[i]-30000)%60001]=1,printf("%d\n",(j-z[i]-30000)%60001);
	else 
		a[(z[i]+30000-j)%60001]=1,printf("%d\n",(z[i]+30000-j)%60001);
*/
