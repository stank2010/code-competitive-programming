#include "stdio.h"

int z[9][9],n,o[100],k=0;

void ch(int l)
{
	int u[9][9],w[3]={1,4,7};
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			scanf("%d",&u[i][j]);
	
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			int num[10]={0};
			int x=w[i],y=w[j];
			
			for(int a=-1;a<2;a++)
				for(int b=-1;b<2;b++)
				{
					if(u[x+a][b+y]==z[x+a][b+y]||z[x+a][b+y]==0)
						num[u[x+a][b+y]]++;
					else return;
					 	
					if(num[u[x+a][b+y]]>1)return;	
				}			
		}
	o[k]=l;
	k++;
}



int main()
{
	scanf("%d",&n);
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			scanf("%d",&z[i][j]);
	for(int i=0;i<n;i++)
		ch(i);		
	for(int i=0;i<k;i++)
		printf("%d\n",o[i]+1);
	printf("END");	
	return 0;
}
