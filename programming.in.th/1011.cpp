#include "stdio.h"
char z[6][6];
int p,m,n,a;
bool che;

void ch(char &a,char &b)
{
	if(a==b)p+=5,che=1,a='-'; 
}

bool check(int x,int y)
{
	che=0;
	ch(z[y][x+1],z[y][x]);
	ch(z[y][x-1],z[y][x]);
	ch(z[y+1][x],z[y][x]);
	//ch(z[y-1][x],z[y][x]);
	if(che)
	{
		z[y][x]='-',p+=5;
		//printf("%d %d\n",x,y);
	}
}

int drop(int x,int y)
{
	while(y+1<m&&z[y+1][x]=='-')
	{
		z[y+1][x]=z[y][x];
		z[y][x]='-';
		y++;
	}
	return y;
}

void show()
{
	for(int i=0;i<m;i++,puts(""))
	for(int j=0;j<n;j++)
	printf("%c ",z[i][j]);
}

void all()
{
	int k=0,count=0;
	do
	{
		k=0;
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)	
		if(z[i][j]>='A'&&z[i][j]<='Z')
		{
			int y=drop(j,i);
			if(i!=y)k++,check(j,y);
		}
		//printf("%d\n",k);
	}while(k>0);
}

main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	scanf(" %c ",&z[i][j]);
	scanf("%d",&a);
	int x,y,k;
	char c;
	for(int i=0;i<a;i++)
	{
		scanf("%d %d %c",&y,&x,&c);
		//printf("%d %d %c\n",y,x,c);
		if(c=='L')x--,k=1; else x++,k=-1;
		
		if(x<0||x>=n||z[y][x]!='-'||z[y][x+k]<'A'||z[y][x+k]>'Z')p-=5;
		else{
				z[y][x]=z[y][x+k];
				z[y][x+k]='-';
				//show();printf("B %d\n\n",p);
				y=drop(x,y);
	   			check(x,y);
	   			all();//show();printf("A %d\n\n",p);
			}
	}
	printf("%d\n",p);
	show();
}
