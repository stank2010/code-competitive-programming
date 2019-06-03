#include "stdio.h"

int kg[2000],mon[100],car[2000],st[1000000],h=0,t=0,g=0;
unsigned long long int sum=0;
bool p[100],b=0; 

int main()
{
	int n,m,a;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&mon[i]);
	for(int i=0;i<m;i++)
		scanf("%d",&kg[i]);
	
	for(int i=0;i<2*m;i++)
	{
		scanf("%d",&a);	
		if(a>0)
		{
			b=0;
			
			if(g<m)
			for(int j=0;j<n;j++)
				if(!p[j])
				{
					car[a-1]=j;
					sum+=mon[j]*kg[a-1];
					p[j]=1;
					b=1;
					g++;
					break;
				}
			if(!b)
			{
				st[t]=a-1;
				t++;	
			}	
		}
		else  
		{
		if(g==m)
		{
			if(t-h>0)
			{
				sum+=mon[car[-a-1]]*kg[st[h]];
				car[st[h]]=car[-a-1];
				p[st[h]]=1;
				h++;
			}
			else g--;
		}
		else
		{
			p[car[-a-1]]=0;
			g--;
			if(t-h>0)
			{
				for(int j=0;j<n;j++)
				if(!p[j])
				{
					sum+=mon[j]*kg[st[h]];
					car[st[h]]=j;
					p[j]=1;
					h++;
					break;
				}
			}
		}
				
		}
	}	
			printf("%llu",sum);
	return 0;
}
