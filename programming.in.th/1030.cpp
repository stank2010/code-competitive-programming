#include "stdio.h"
#include "algorithm"
using namespace std;

typedef struct{
	int k;
	double p;
}put;



bool ch(put x,put y)
{
	return x.p<y.p;
}

put z[100000];
double x[100000]={0};
int main()
{
	int n,a,r=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	scanf("%d %d",&a,&z[i].k);
	z[i].p=(double)a/(double)z[i].k;
	}
	
	sort(z,z+n,ch);
	
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&a);
		while(a>0)
		{
			 if(a>=z[r].k)
			 {
			 x[i]+=(double)z[r].k*z[r].p;
			 a-=z[r].k;	
			 z[r].k=0;
			 r++;	
			 }
		else if(a<z[r].k)
		{  
		x[i]+=z[r].p*a;
		z[r].k-=a;
		a=0;
		}	
			
		}
	}
	for(int i=0;i<m;i++)printf("%.3lf\n",x[i]);
	
	return 0;
}
