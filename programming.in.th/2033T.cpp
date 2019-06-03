#include "stdio.h"
#include "algorithm"
using namespace std;
 
struct play{
int point;
int test;
int num;	
}z[2000];


int ch[2000][2000],n,t,p,T[2000];

bool check(struct play a,struct play b)
{
	if(a.point==b.point)
	{
		if(a.test==b.test)return a.num<b.num;
		else return a.test>b.test;
	}
	else return a.point>b.point;
}


int main()
{
	scanf("%d %d %d",&n,&t,&p);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<t;j++)
	 	{
	 	scanf("%d",&ch[i][j]);
	 		if(ch[i][j]==0)
	 		{
	 		T[j]++;
			}
	 	}
		z[i].num=i;	
		z[i].point=0;
		z[i].test=0;
	}
	
	for(int i=0;i<n;i++) 
		for(int j=0;j<t;j++)
		{
			if(ch[i][j]==1)
			{
			z[i].point+=T[j];	
			z[i].test++;	
			}
		}
		
	sort(z,z+n,check);
	
	for(int i=0;i<n;i++)
		if(z[i].num+1==p)
		{
			printf("%d %d",z[i].point,i+1);
		}
	return 0;
}
