#include "stdio.h"

struct sakan
{
	int count,num;
}tree[1100001],Null;

int z[200000],n;

int make_tree(int h,int l,int index)
{
	if(h==l)
	{
		tree[index].num = z[h];
		tree[index].count = 1;
	}
	else 
	{
		int mid=(h+l)/2;
		tree[index].count += make_tree(h,mid,2*index+1);
		tree[index].count += make_tree(mid+1,l,2*index+2);	
		return tree[index].count;
	}		
	return tree[index].count;
}

int del_tree(int index,int seq)
{
	int index_left  = 2*index + 1;
	int index_right = 2*index + 2;
		
	if(tree[index_left].count == 0 && tree[index_right].count == 0)
	{
		int parent = (index - 1)/2 , val = tree[index].num;
		
		tree[index] = Null;
		
		if(index == parent*2 + 1)
			tree[parent] = tree[ parent*2 + 2 ];
		else 
			tree[parent] = tree[ parent*2 + 1 ];
		
		return val;
	}
	
	tree[index].count--;
	if(seq <= tree[index_left].count)
	{
		return del_tree( index_left , seq );
	}
	else 
	{
		return del_tree( index_right , seq - tree[index_left].count );
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&z[i]);
	
	make_tree(0,n-1,0);
	int a;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		printf("%d\n",del_tree(0,a));
	}
	return 0;
}
