#include "stdio.h"
#include "limits.h"
int mem[300000],n,m,H,L;
int tree[800000];

int max(int a,int b){return a > b ? a : b;}

void make_tree(int h,int l,int index)
{
	if(h==l)
	{
		mem[h]=index;
		return;
	}
	
	int mid=(h+l)/2;
	make_tree(h,mid,index*2);
	make_tree(mid+1,l,index*2+1);
}

void update(int i,int k)
{
	tree[i] = k;
	i/=2;
	while(i>=1)
	{
		tree[i] = max(tree[2*i],tree[2*i+1]);
		i/=2;
	}
}

int Find(int h,int l,int index)
{
	if( l < H || L < h || h > l) //[h,l][H,L] [H,L][h,l] 
	{
		return INT_MIN;
	}
	
	if(H<=h && l<=L)  // [H [h,l] L]
		return tree[index];
	int mid=(h+l)/2;
	return max( Find(h,mid,index*2) , Find(mid+1,l,index*2+1) );
}

int main()
{
	scanf("%d %d",&n,&m);
	make_tree(1,n,1);
	for(int i=0;i<m;i++)
	{
		char a;
		int A,B;
		scanf(" %c %d %d",&a,&A,&B);
		if(a == 'U')
			update(mem[A],B);
		else if(a == 'P')
		{
			H=A;
			L=B;
			printf("%d\n",Find(1,n,1));
		}
	}

	return 0;
}
