#include "stdio.h"
#include "algorithm"
using namespace std;

struct col{
	int num,value;
}z[300000];

int ct[300000]={0},Max=0,cp[300000];
bool ck[300000]={0};

long long sum=0,s=0;

bool ch(struct col x,struct col y)
{
	if(x.value==y.value)return x.num>y.num;
	return x.value>y.value;
}

int main()
{
int i,n,sp;
scanf("%d",&n);

for(i=0;i<n;i++)
{
	z[i].num=i;
	scanf("%d",&z[i].value);
	cp[i]=z[i].value;
	sum+=cp[i];
}	

sum=sum/2;
sort(z,z+n,ch);


	for(int j=0;j<n&&s<=sum;j++)
	{
		ck[z[j].num]=1;
		s+=z[j].value;
		Max++;
	    sp=j;
	}
	
	
for(i=0;i<n;i++)
{

   	  	if(ck[i])
   	  	{
			 ct[i]=Max-1;
		}
		
		else 
		{
			if(s-z[sp].value+cp[i]>sum)ct[i]=Max-1;
			else ct[i]=Max;
		}
	printf("%d\n",ct[i]);		
}	
	
	return 0;
}
