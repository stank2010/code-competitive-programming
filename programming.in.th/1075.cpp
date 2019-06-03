#include "stdio.h"
#include "algorithm"
using namespace std;

double Max=0;
int V=0;
long long S=0,D=0;
struct worm{
	int data,value;
}z[100000];


bool ch(struct worm x,struct worm y)
{
	if(x.value==y.value)return x.data>y.data;
	else return x.value<y.value;
}


int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	scanf("%d %d",&z[i].data,&z[i].value);	
	}
	sort(z,z+n,ch);
	
	for(int i=0;i<n;i++)
	{
	  S+=z[i].data;		
	  	if(double(S)/double(z[i].value)>Max)
	  	{
	  	Max=double(S)/double(z[i].value);
	  	V=z[i].value;
	  	D=S;
		}	
	}
	printf("%lld %d",D,V);
	return 0;
}
