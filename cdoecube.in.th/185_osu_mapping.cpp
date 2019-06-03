#include "stdio.h"
#include "vector"
#include "queue"
#include "cstring"

#define INF 100000000000
struct U
{
	int val_1,val_2;
	long long dist;
	bool operator<(const U& X) const
	{
		return dist > X.dist;
	}
}temp;

std::priority_queue<struct U> Queue; 
std::vector<struct U> node[10001];

int n,m,t,st,ed;
long long PATH[10001][8],MIN = -1;
bool COME[10001][8];
int main()
{
	scanf("%d %d %d %d %d",&n,&m,&t,&st,&ed);
	for(int i=0;i<m;i++)
	{
		int a;
		scanf("%d %d %d",&a,&temp.val_1,&temp.val_2);
		node[a].push_back(temp);
	}
	
	for(int i=0;i<=n;i++)
		for(int j=0;j<8;j++)
			PATH[i][j] = INF;
	
	temp.val_1 = st;
	temp.val_2 = 1;
	temp.dist = 0;
	Queue.push(temp);
	
	PATH[st][1%t] = 0;
	
	while(!Queue.empty())
	{
		temp = Queue.top();
		Queue.pop();
		int This = temp.val_1 , T = temp.val_2 % t;
		long long dist = temp.dist;
		//printf("%d %d %lld\n",This,T,PATH[This][T]);
		
		if(COME[This][T] == 1)
			continue;
		else 
			COME[This][T] = 1;
			
		int l = node[This].size();
		for(int i=0;i<l;i++)
		{
			int p  = node[This][i].val_1;
			int go = node [This][i].val_2;
			
			if(COME[p][(T+1)%t] == 0 && dist + go < PATH[p][(T+1)%t] )
			{
				
				PATH[p][(T+1)%t] = dist + go;
				//printf("Eiei : %d %lld\n",p,PATH[p][(T+1)%t]);
				temp.val_1 = p; 
				temp.val_2 = (T+1)%t;
				temp.dist = dist + go;
				Queue.push(temp); 
			}
		}
	}
	
	printf("%lld",PATH[ed][0]==INF ? -1 : PATH[ed][0]);
	return 0;
}
