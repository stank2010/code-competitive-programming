#include "stdio.h"
#include "string.h"

char z[2001],de[2001];
int k,l,lon;

int main()
{
	scanf("%d %s",&k,z);
	lon=strlen(z);
	
	if(k<=1)
	{
		printf("%s",z);
		return 0;
	}
	int add=4*k-4;
	
	for(int i=k-1;i<lon;i+=add)
	for(int j=0;i+j<lon&&j<k;j++)
	{
		//printf("%d %c\n",i+j,z[l]);	
		de[i+j]=z[l++];
	}
	
	for(int i=k-2;i>0;i--)
	{
		int s=i;
		int in=2*(k-i-2)+k+1;
		int out=2*(i-1)+k+1;
		
		for(int j=0;s<lon;j++)
		{
			de[s]=z[l++];
			//if(l<lon)printf("%d %c\n",s,z[l-1]);
			
			if(j%2==0)s+=in;
			else s+=out;
		}
	}
	
	de[0]=z[l++];
	
	for(int i=3*k-3;i<lon&&l<lon;i+=add)
	{
		for(int j=0;i+j<lon&&j<k;j++)
		{
		//printf("%d %c\n",i+j,z[l]);
			de[i+j]=z[l++];
		}
	}
	
	printf("%s",de);
	//for(int i=0;i<lon;i++)if(de[i]>0)printf("%c",de[i]); 
		//else printf("0");
	return 0;
}
