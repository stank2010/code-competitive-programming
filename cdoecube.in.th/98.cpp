#include "stdio.h"

int z[1000001];
int A[1000001];

int main()
{
	int n,m,a,k=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&z[i]);
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a);
		if(i-A[a]>=z[a])k++,A[a]=i;
	}
	printf("%d",k);
	return 0;
}
