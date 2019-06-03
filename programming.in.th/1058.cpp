#include "stdio.h"

int t,r,c,a,b,q[5];
char z[1001][1001];
int A[1000][1000],B[1000][1000],C[1000][1000],D[1000][1000],I,J;
void clear()
{
	for(a=0;a<r;a++)
		for(b=0;b<c;b++)
			A[a][b]=B[a][b]=C[a][b]=D[a][b]=0;
}

int main()
{
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d %d",&r,&c);
		for(a=0;a<r;a++)
			scanf("%s",z[a]);
		
		for(a=0;a<r;a++)
			for(b=0;b<c;b++)
			if(z[a][b]=='1')
			{
				if(a>0)
					B[a][b]=B[a-1][b]+1;
				else 
					B[a][b]=1;
				
				if(b>0)
					A[a][b]=A[a][b-1]+1;
				else 
					A[a][b]=1;	
			}	
			
		for(a=r-1;a>=0;a--)
			for(b=c-1;b>=0;b--)
			if(z[a][b]=='1')
			{
				if(a<r-1)D[a][b]=D[a+1][b]+1;
				else D[a][b]=1;
				
				if(b<c-1)C[a][b]=C[a][b+1]+1;
				else C[a][b]=1;
			}
			
		int x,y;	
		for(a=0;a<r;a++)	
			for(b=0;b<c;b++)
			if(z[a][b]=='1')
			{
				/*
				if(z[a+1][b]=='1'&&z[a][b+1]=='1')		
						
				if(z[a+1][b]=='1'&&z[a][b-1]=='1')
				
				if(z[a-1][b]=='1'&&z[a][b+1]=='1')
				
				if(z[a-1][b]=='1'&&z[a][b-1]=='1')
				*/
				if(A[a][b]+B[a][b]>q[i])
					q[i]=A[a][b]+B[a][b];
					
				if(A[a][b]+D[a][b]>q[i])
					q[i]=A[a][b]+D[a][b];
					
				if(B[a][b]+C[a][b]>q[i])
					q[i]=B[a][b]+C[a][b];
					
				if(C[a][b]+D[a][b]>q[i])
					q[i]=C[a][b]+D[a][b];
			}	
		clear();
	}
	for(int i=0;i<t;i++)
		printf("%d\n",q[i]-1);
	return 0;
}
