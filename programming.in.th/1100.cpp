#include "stdio.h"

long long int a[10][10][10],b0[10][10],b1[10][10],b2[10][10],c[3][10],d[3];
long long int t=0,x=0,y=0,z=0,s=0;

int main()
{
	int n;
	char p[4];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	scanf(" %s",p);	
	c[0][p[0]-'0']++;
	c[1][p[1]-'0']++;
	c[2][p[2]-'0']++;

	a[p[0]-'0'][p[1]-'0'][p[2]-'0']++;
	b0[p[0]-'0'][p[2]-'0']++;
	b1[p[0]-'0'][p[1]-'0']++;
	b2[p[1]-'0'][p[2]-'0']++;
	}

	for(int i=0;i<3;i++)
		for(int j=0;j<10;j++)
			if(c[i][j]>1)d[i]+=c[i][j]*(c[i][j]-1)/2;
		
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		if(b0[i][j]>1)x+=b0[i][j]*(b0[i][j]-1)/2;
	
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		if(b1[i][j]>1)y+=b1[i][j]*(b1[i][j]-1)/2;

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		if(b2[i][j]>1)z+=b2[i][j]*(b2[i][j]-1)/2;	
	

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++)
				if(a[i][j][k]>1)s+=a[i][j][k]*(a[i][j][k]-1)/2;

	printf("%lld",d[0]+d[1]+d[2]+s-x-y-z);
//	printf("\n%lld %lld %lld\n%lld %lld %lld\n%lld",d[0],d[1],d[2],x,y,z,s);
return 0;
}
