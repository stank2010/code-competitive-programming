#include "stdio.h"
int n;
char z[15],x[15];

void read(char a,int r)
{
	z[r]=x[r]=a;
	if(r==n-1)
	{
		for(int i=n-1;i>=0;i--)
		{
			if(x[i]=='0')
			{
				x[i]='1';
				printf("%s %s\n",z,x);
				x[i]='0';
			}
		}
	}
	else
	{
		read('0',r+1);
		read('1',r+1);
	}
}
int main()
{
	scanf("%d",&n);	
	read('0',0);
	read('1',0);
	return 0;
}
