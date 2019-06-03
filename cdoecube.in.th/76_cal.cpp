#include "stdio.h"
#include "string.h"
/*
char a[1002],b[1002],c[1002];
int l[3];

void set(char *z,int L)
{
	for(int i=l[L];i<=1000;i++)
		z[i]='0';	
}*/

int main()
{
	/*
	scanf("%s %s %s",a,b,c);	
	l[0]=strlen(a);
	l[1]=strlen(b);
	l[2]=strlen(c);
	set(a,0);
	set(b,1);
	set(c,2);
	
	for(int i=1000;i>=0;i--)
	{
		
	}*/
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	
	if(a+b<=c+0.00000000001&&a+b>=c-0.00000000001)printf("Correct");
	else printf("Wrong");
	
	return 0;
}
