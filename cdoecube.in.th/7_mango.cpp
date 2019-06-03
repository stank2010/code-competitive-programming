#include "stdio.h"

char a[1000001],b[1000001];
int z[1000001],l;

int ch(char x,char y)
{
	if(x>'Z')x-=32;
	if(y>'Z')y-=32;
	
	x-='A';
	y-='A';
	
	int i=0;
	
	while((x+i)%26!=y)
	{
		i++;
	}
	z[l++]=i;
}


int main()
{
	scanf("%s %s",a,b);
	bool B=0;
	for(int i=0;a[i]!=0&&b[i]!=0;i++)
	{
		ch(b[i],a[i]);
		if(z[i]>9)B=1;
	}
	
	if(B)printf("R.I.P.");
	else for(int i=0;i<l;i++)printf("%d",z[i]);
	return 0;
}
