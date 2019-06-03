#include "stdio.h"
#include "algorithm"
using namespace std;
int l[10000]={0};

typedef struct{
int sp,num,r,lu;	
}st;

st run[100000];

bool check(st x,st y)
{
	if(x.r==y.r)
	{
	 if(x.sp==y.sp)return x.lu<y.lu;
	 else return x.sp>y.sp;	
	}	
	else return x.r<y.r;
}

int main()
{
	int n,m,a,b,c;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		run[i].sp=c;
		run[i].num=a;
	    run[i].r=l[b-1];
        run[i].lu=b-1;
	    l[b-1]++;
	}
	sort(run,run+n,check);
	int l=0;
	for(int i=0;i<n;i++)
	{
		if(l==run[i].r)printf("%d\n",run[i].num),l++;
	}
	
	return 0;
}
