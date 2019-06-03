#include "stdio.h"
#include "algorithm"
using namespace std;

int xp[100000];


int main()
{
	int n,a,b,o=1;
	long long int sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		xp[i]=b-2*a;
		sum+=xp[i];
	}
	sort(xp,xp+n);
	for(int i=0;i<n;i++)
	{
		if(xp[i]<0&&xp[i]*(-1)>(2*o-1))
		{
			sum+=xp[i]*(-1)-(2*o-1);
			o++;
		}
	}
	printf("%lld",sum);
	return 0;
}

//(o*o)-((o-1)*(o-1)) ==(2*o-1)
