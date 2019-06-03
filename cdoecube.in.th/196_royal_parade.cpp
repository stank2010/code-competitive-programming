#include "stdio.h"
#include "vector"
#include "queue"

struct edge
{
	int me,to;
	long long w;
	bool operator < (const edge &Stank)const
    {
        return Stank.w<w;
    }
};

std::vector<edge> node[100001];
std::priority_queue<struct edge> Que;

long long short_path[100001];
std::vector<int> pre[100001];
bool check[100001];

bool black_list[100001];
int n,m,A1,B1,A2,B2;

void dijkstra(int start)
{
	
	//initail clear all value
	for(int i=1;i<=n;i++)
	{
		short_path[i] = check[i] = 0;	
		pre[i].clear();
	}
	
	//push first node in prior queue
	edge A; A.me = start; A.w = 0;
	short_path[A.me] = 0;
	check[A.me] = 1;
	
	Que.push(A);
	
	while(!Que.empty())
	{
		A = Que.top();
		Que.pop();
		check[A.me] = 1;
		
		for(int i=0;i<node[A.me].size();i++)
		{
			if(check[ node[A.me][i].to ] == 0 and black_list[ node[A.me][i].to ] == 0)	
			{
				long long path = A.w + node[A.me][i].w;
				if(path < short_path[ node[A.me][i].to ] or short_path[ node[A.me][i].to ] == 0)
				{
					short_path[ node[A.me][i].to ] = path;	
					
					pre[ node[A.me][i].to ].clear();
					pre[ node[A.me][i].to ].push_back(A.me);
					edge A_new;
					A_new.me = node[A.me][i].to;
					A_new.w = path;
					Que.push(A_new);
				}
				else if(path == short_path[ node[A.me][i].to ])
				{
					pre[ node[A.me][i].to ].push_back(A.me);
				}
			}
		}
	}
}


//delete node that may be shortest path between A1 and B1
void black(int a)
{
	black_list[ a ] = 1;
	for(int i=0;i<pre[a].size();i++)
	{
		black( pre[a][i] );
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		edge A;
		scanf("%d %d %lld",&A.me,&A.to,&A.w);
		node[A.me].push_back(A);
		int c = A.me; A.me = A.to; A.to = c;
		node[A.me].push_back(A);
	}
	scanf("%d %d %d %d",&A1,&B1,&A2,&B2);
	dijkstra(A1);
	
	black(B1);
	
	dijkstra(A2);
	
	if(black_list[A2]==1 or black_list[B2]==1 or short_path[B2]==0)
	{
		printf("-1");
		return 0;	
	}
	
	printf("%lld",short_path[B2]);
	return 0;
}
