#include "stdio.h"


int f[100][100],n,m,k,Q[20],x=0,y=0;

void tis(int a)
{
	if(a==1)y--;
	else if(a==2)x++;
		else if(a==3)y++;
			else x--;
}


int main()
{
	scanf("%d %d %d",&n,&m,&k);	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&f[i][j]);
			
	for(int i=0;i<k;i++)
	{
	bool b[100][100]={0};	
	scanf("%d %d",&x,&y);
	x--;
	y--;
		while(1)
		{
		b[y][x]=1;
		tis(f[y][x]);
		//debug =w= 
		if(x<0){Q[i]='W'; break;}
		else if(x>=n){Q[i]='E'; break;}
		else if(y<0){Q[i]='N'; break;}
		else if(y>=m){Q[i]='S'; break;}
		else if(b[y][x]==1){Q[i]=0; break;}	
		//debug =w=
		}
	}
	
	for(int i=0;i<k;i++)
	if(Q[i]==0)printf("NO\n");
	else printf("%c\n",Q[i]);	
}
