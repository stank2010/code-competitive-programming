#include "stdio.h"

char z[1000][1000];

int main()
{
	int t,a,b,B_left=1,B_right=1,sp_left,sp_right,maxr=0,maxc=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d %d",&a,&b);
		a--;
		if(b>maxr)maxr=b;
		if(a+2*b>maxc)maxc=a+2*b;
		
		B_left=1,B_right=1;
		sp_left=0,sp_right=0;
		
		for(int j=b-1;j>=0;j--)
		{
			if(z[j][a+j]!=0)z[j][a+j]='v',B_left=0;
			else if(B_left)z[j][a+j]='/';

			if(z[j][a+2*b-1-j]!=0)z[j][a+2*b-1-j]='v',B_right=0;
			else if(B_right)z[j][a+2*b-1-j]= '\\';

		}
	}
	
	for(int i=maxr-1;i>=0;i--)
	{
		for(int j=0;j<maxc;j++)
			if(z[i][j]=='v')
			{
				for(int h=i-1;h>=0;h--)z[h][j+(i-h)]=z[h][j-(i-h)]=0;
			}
			else if(z[i][j]=='\\'&&z[i][j+1]=='/')
			{
				for(int h=i-1;h>=0;h--)z[h][j+(i-h)]=z[h][j-(i-h-1)]=0;
			}
	}
	
	
	int l=0;
	for(int i=0;i<maxr;i++)
	{
		l=0;
		for(int j=0;j<maxc;j++)
		{
			if(z[i][j]=='\\'||z[i][j]=='v')l--;
			if(l>0)z[i][j]='X';
			if(z[i][j]=='/'||z[i][j]=='v')l++;
		}
	}
	
	for(int i=maxr-1;i>=0;i--,puts(""))
	{
		for(int j=0;j<maxc;j++)
			printf("%c",(z[i][j]==0?'.':z[i][j]));
	}
	return 0;
}
