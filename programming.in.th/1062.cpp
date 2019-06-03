#include "stdio.h"
#include "string.h"
int main()
{
char a[127],b[127],key[127];
int L,K;

scanf("%d %d %s %s %s",&L,&K,a,b,key);
for(int i=0;i<L;i++)
{
	for(int u=K-1;u>=0;u--)
	{
		char A[3],j;
		A[0]=a[i];
		A[1]=key[u];
		A[2]=b[i];
		int c,d;
		for(c=0;c<3;c++)
		 for(d=0;d<2;d++)if(A[d]>A[d+1])j=A[d],A[d]=A[d+1],A[d+1]=j;
		key[u]=A[1];
	}
	 
}
	printf("%s",key);
	return 0;
}
