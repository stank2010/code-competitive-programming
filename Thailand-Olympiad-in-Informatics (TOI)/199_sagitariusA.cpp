#include "stdio.h"
#include "algorithm"

struct line
{
	int a,b,w,NO;	
}data[100001];

int head[100001],n,m;
int ans[100001],L;

bool ch(line A,line B)
{
	return A.w>B.w;
}

int find_head(int k)
{
	if(head[k]!=0)
		return head[k] = find_head(head[k]); 
	return k;
}

int main()
{
	int T;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&data[i].a,&data[i].b,&data[i].w);
		data[i].NO = i+1;
	}
	scanf("%d",&T);
	std::sort(data,data+m,ch);
	
	int count=0;
	long long int val=0;
	bool use = 0;
	for(int i=0;i<m;i++)
	{
		int Ah = find_head(data[i].a) , Bh = find_head(data[i].b);
		if(Ah != Bh)
		{
			head[Ah] = Bh;
			ans[L++] = data[i].NO;
			count++;
			val += data[i].w;
		}
		else if(!use)
		{
			count++;
			val += data[i].w;
			ans[L++] = data[i].NO;
			use = true;
		}
	}
	
	if(count == n)
	{
		printf("%lld\n",val);
		if(T==2)
			for(int i=0;i<L;i++)
				printf("%d ",ans[i]);
	}
	else
		printf("-1");
	
	return 0;
}
