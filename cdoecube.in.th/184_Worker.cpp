#include "stdio.h"
#include "algorithm"

struct SUMMER
{
	int SUM,a,b;
}st[1001000];

struct pair
{
	int B,T,led;
}z[1001];

int n,l;
long long sum;

void Add(int a,int b,int SUM)
{
	st[l].a=a;
	st[l].b=b;
	st[l].SUM=SUM;
	l++;
}

int find(int key)
{
	if(key != z[key].led)
		return z[key].led = find(z[key].led);
	else 
		return key;
}

bool CH(SUMMER A,SUMMER B)
{
	return A.SUM<B.SUM;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&z[i].T);
	
	for(int i=1;i<=n;i++)
		scanf("%d",&z[i].B),z[i].led=i;	

	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
			Add(i,j,z[i].B+z[j].B);
		
		Add(0,i,z[i].T);
	}	
	
	std::sort(st,st+l,CH);
	
	int count=0;
	
	for(int i=0;i<l;i++)
	{
		int A=find(st[i].a),B=find(st[i].b);
		
		if(A!=B)
		{
			z[A].led = B;
			sum+=st[i].SUM;
			if(++count == n+1)	
				break;
		}	
	}

	printf("%lld",sum);	
	return 0;
}
