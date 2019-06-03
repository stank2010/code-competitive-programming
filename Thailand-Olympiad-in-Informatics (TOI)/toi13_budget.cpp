#include "stdio.h"
#include "vector"
#include "queue"

#define INF 1000000000

struct U
{
	int to,val;
	bool operator<(const U &x) const
	{
		return x.val <val;
	}
	
}temp;

int n,m;
int x,y,z;
int  short_start[100001],short_end[100001];
bool ch_start[100001],ch_end[100001];

std::vector<U> edge[100001];
std::priority_queue<U> Queue;

void set(int N)
{
	for(int i=0;i<=n;i++)
		short_start[i]=short_end[i]=INF;
}

void add(int to,int val)
{
	temp.to  = to;
	temp.val = val;
	Queue.push(temp);
}

void dijkstra(int first,int *shortest,bool *ch)
{
	shortest[first] = 0;
	add(first,0);
	
	while(!Queue.empty())
	{
		struct U node = Queue.top();
		Queue.pop();
		
		if(ch[node.to])
			continue;
		else
			ch[node.to];
		
		int Length = edge[ node.to ].size();
		
		for(int i=0;i<Length;i++)
		{
			int That = edge[ node.to ][i].to;
			int Long = edge[ node.to ][i].val;
			
			if(!ch[That] && shortest[node.to] + Long < shortest[That])
			{
				shortest[That] = shortest[node.to] + Long;
				add(That,shortest[That]);
			}
		}
	}
}


int main()
{
	scanf("%d %d",&n,&m);
	scanf("%d %d %d",&x,&y,&z);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d %d",&a,&b,&temp.val);
		temp.to = b;
		edge[a].push_back(temp);
		temp.to = a;
		edge[b].push_back(temp);
	}
	
	set(n);
	dijkstra(x,short_start,ch_start);
	
	if( short_start[y] <= z )
	{
		printf("%d %d %d",y,short_start[y],0);
	}
	else 
	{
		dijkstra(y,short_end,ch_end);
		
		int min = INF,node_near = -1;
		for(int i=0;i<n;i++)
		if(i!=x && i!=y)
		{
			if( short_start[i] <= z && short_end[i] < min )
			{
				node_near = i;
				min = short_end[i];
			}
		}
		printf("%d %d %d",node_near,short_start[ node_near ],min);
	}
			
	return 0;
}
