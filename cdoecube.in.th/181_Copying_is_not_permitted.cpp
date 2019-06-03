#include "stdio.h"
#include "vector"
#include "cstring"
struct Eiei
{
	int to,val;
}temp;

std::vector<Eiei> st[40001];

struct Haha
{
	int a,b;
}student[50001];


int max_st[40001];
int n,m,p,mak;

int MAX(int a,int b){return (a>b)?a:b;}

void dfs(int node,int Ans,int lek)
{
	max_st[ node ] = lek;
	int l=st[node].size();
	for(int j=0;j<l;j++)
	{
		if(max_st[ st[node][j].to ] == 0 && st[node][j].val < Ans)
		{
			dfs( st[node][j].to , Ans , lek);
		}
	}
}

bool ch(int Ans)
{
	std::memset(max_st,0,sizeof max_st);
	for(int i=0;i<p;i++)
	{
		if(max_st[ student[i].a ] == 0)
			dfs( student[i].a , Ans , i+1);
		//printf("%d %d\n",max_st[ student[i].a ] ,max_st[ student[i].b ]);
		if(max_st[ student[i].a ] == max_st[ student[i].b ])
			return false;
	}	
	
	return true;
}

int bs()
{
	int H=1,L=mak,Mid,Min=0;
	
	while(H<=L)
	{
		Mid=(H+L)/2;
		
		if(ch(Mid))
		{
			if(Mid>Min)
				Min=Mid;
			H=Mid+1;	
		}
		else L=Mid-1;
	}

	return Min;
}

int main()
{
	scanf("%d %d %d",&n,&m,&p);
	
	int a,b,c;
	
	for(int i=0;i<m;i++)
	{
		
		scanf("%d %d %d",&a,&b,&c);
		
		if(c>mak)
			mak=c;
			
		temp.to=b; 
		temp.val=c;		
		st[a].push_back(temp);	
		
		temp.to=a; 
		temp.val=c;
		st[b].push_back(temp);	
		
	}
	
	for(int i=0;i<p;i++)
		scanf("%d %d",&student[i].a,&student[i].b);
	
	if(ch(mak+1))
		printf("%d",-1);
	else 
		printf("%d",bs());
	
	return 0;
}
