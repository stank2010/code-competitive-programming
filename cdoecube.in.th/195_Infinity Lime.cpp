#include "stdio.h"
#include "algorithm"

struct xy{
	int x,y,num;
}pair[700001];

struct ans
{
	int target,val,NO;
}real[700001];

int L;
int M,K;
int temp[700001];

bool sort_by_target(ans A,ans B)
{
	return A.target<B.target;
}

bool sort_by_NO(ans A,ans B)
{
	return A.NO<B.NO;
}


int main()
{
	scanf("%d %d",&M,&K);
	
	for(int i=0;i<M;i++)
		scanf("%d",&temp[i]);
	
	std::sort(temp,temp+M);
	
	int MAX = temp[M-1]+1;
	
	if(temp[0]!=1)
		pair[L].x = 1,pair[L].y = temp[0]-1 , pair[L].num = pair[L].y - pair[L].x + 1, L++;
	
 	for(int i=1;i<M;i++)
	{
		if(temp[i-1]+1 != temp[i])
		{
			pair[L].x = temp[i-1]+1;
			pair[L].y = temp[i]-1;
			pair[L].num = pair[L].y - pair[L].x + 1;
			L++;
		}
	}
	
	for(int i=0;i<K;i++)
	{
		scanf("%d",&temp[i]);
		real[i].target = temp[i];
		real[i].NO = i;
	}
	
	std::sort(real,real+K,sort_by_target);
	
	int LR = 0;
	int tt=0;
	
	for(int i=0 ; i<L and LR<K; i++)
	{
		while(LR<K and real[LR].target <= tt + pair[i].num)
		{
			real[LR].val = pair[i].x + (real[LR].target-tt-1);
			LR++;
		}
		tt += pair[i].num;
	}
	
	while(LR<K)
	{
		real[LR].val = MAX + (real[LR].target-tt-1);
		LR++;	
	}
	
	std::sort(real,real+K,sort_by_NO);
	
	for(int i=0;i<K;i++)
		printf("%d ",real[i].val);
		
	return 0;
}
