#include "stdio.h"

struct T
{
	int num,val;
	int L,R,Master;
}tree[600000],null;



int set(int h,int l,int index)
{
	//printf("%d\n",index);
	if(h==l)
	{
		tree[index].val = h;
		return tree[index].num = 1;
	}
	
	tree[index].L = index*2+1;
	tree[index].R = index*2+2;
	
	tree[ tree[index].L ].Master = index; 
	tree[ tree[index].R ].Master = index;
	
	int mid=(h+l)/2;
	return tree[index].num = set(h,mid,tree[index].L) + set(mid+1,l,tree[index].R);
}

int del(int index,int temp_k,bool walk)
{	
	//printf("%d \n",index);
	if(tree[index].val)
	{
		int Value = tree[index].val;
		int Mas = tree[index].Master;
		
		if(walk==0)
			tree[Mas] = tree[ tree[Mas].R ];		
		else 
			tree[Mas] = tree[ tree[Mas].L ];
		tree[index] = null;
		return Value;
	}
	
	tree[index].num--;
	int L=tree[index].L;
	if(temp_k <= tree[L].num)
		return del( tree[index].L , temp_k , 0);
	else 
		return del (tree[index].R , temp_k - tree[L].num , 1);
}


bool ch[200001];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	set(1,n,0);
	
	int seq=k,found=1;
	for(int i=n;i>1;i--)
	{
		seq = (seq-1 + found-1)%i +1;
		found = del(0,seq,0);
		ch[found] = 1;
		//printf(" = %d %d\n",found,seq);
	}
	
	for(int i=1;i<=n;i++)
		if(!ch[i])
		{
			printf("%d",i);
			return 0;
		}
	
	
	return 0;
}
