#include "stdio.h"

int w,h;
char z[100][100];


void pung(int x,int y,int l)
{
	bool b=0;
	if(z[y][x]=='.')
	{
		if(l%2==0)
			z[y][x]='-';
		else
			z[y][x]='|';	
		b=1;
	}
	
	else if((z[y][x]=='-'&&l%2==1)||(z[y][x]=='|'&&l%2==0))
	{
		z[y][x]='+';
		b=1;
	}
	
	if(b)
	{
		if(l==1&&y-1>=0)
			pung(x,y-1,l);
			
	else if(l==2&&x+1<w)
			pung(x+1,y,l);
			
	else if(l==3&&y+1<h)
			pung(x,y+1,l);
			
	else if(l==4&&x-1>=0)
			pung(x-1,y,l);				
	}
}


int main()
{
	scanf("%d %d",&w,&h);
	
	for(int i=0;i<h;i++)
		scanf("%s",z[i]);
	
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		{
			if(z[i][j]=='^'&&i-1>=0)
				pung(j,i-1,1);
				
		else if(z[i][j]=='V'&&i+1<h)
				pung(j,i+1,3);
				
		else if(z[i][j]=='>'&&j+1<w)			
				pung(j+1,i,2);
				
		else if(z[i][j]=='<'&&j-1>=0)			
				pung(j-1,i,4);
		
		else if(z[i][j]=='B')
				z[i][j]='*';
		}	
		
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)	
			printf("%c",z[i][j]); 
		printf("\n");  
	}
			
	return 0;
}
