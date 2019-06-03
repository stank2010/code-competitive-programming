#include "stdio.h"

int n,m,max=-1;
int map[100][100],nmap[100][100];

void row(int a)
{
int o=0;	
for(int i=0;i<n;i++)
{
	if(i==a-1||i==a+1)
		for(int j=0;j<m;j++)	
			o+=nmap[i][j]+map[i][j];
	else if(i!=a)
		for(int j=0;j<m;j++)
			o+=map[i][j];
}	

if(o>max)	
max=o;
}

void col(int a)
{
int o=0;	
for(int j=0;j<m;j++)
{
	if(j==a-1||j==a+1)
		for(int i=0;i<n;i++)	
			o+=nmap[i][j]+map[i][j];
	else if(j!=a)
		for(int i=0;i<n;i++)
			o+=map[i][j];
}

if(o>max)	
max=o;	
}

int main()
{
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		scanf("%d",&map[i][j]);
	
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)	
		scanf("%d",&nmap[i][j]);
	
	for(int i=0;i<n;i++)
	row(i);	
	for(int i=0;i<m;i++)
	col(i);
	
	printf("%d",max);
	return 0;
}
