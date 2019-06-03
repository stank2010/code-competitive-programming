#include "stdio.h"

int n,m,z[20][20],mem[20],min=99;

bool cp(int a,int b)
{
	return (a>0&&b<0)||(a<0&&b>0);
}

void re(int N,int ans,int *peo,int num)
{
	if(num>=min)return;
	
	
	if(N==m)
	{
		if(num<min)
			min=num;
	//	for(int i=0;i<n;i++)printf("%d ",peo[i]);
	//	printf(" : %d\n",num);
		return;
	}
	
	int st[20],l=0;
	
	for(int i=0;i<n;i++)
	if(!peo[i])
	if(cp(z[i][N],ans))
	{
		st[l++]=i;
		peo[i]=1;
		num++;
	}
	
	re(N+1,1,peo,num);
	
	re(N+1,-1,peo,num);	
	while(l>0)
	{
		peo[st[l-1]]=0;
		l--;	
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			scanf("%d",&z[i][j]);
	}
	int peo[20]={0};
	re(0,1,peo,0);
	re(0,-1,peo,0);
	printf("%d",min);
	return 0;
}
