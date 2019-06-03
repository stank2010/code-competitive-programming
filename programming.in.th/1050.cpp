#include "stdio.h"
#include "algorithm"


struct U{
	int arr[11],num;
}z[100001],Ch;

int n,p,ind;

bool sot(struct U a,struct U b)
{
	int i=0;
	while(i<p&&a.arr[i]==b.arr[i])i++;
	return a.arr[i]<b.arr[i];
}

bool ch(int i)
{
	for(int l=0;l<p;l++)
	if(z[i].arr[l]!=Ch.arr[l])return 0;
	return 1;	
}

bool less(struct U a,struct U b)
{
	int i=0;
	while(i<p&&a.arr[i]==b.arr[i])i++;
	return a.arr[i]<b.arr[i];
}

bool equal(struct U a,struct U b)
{
	for(int i=0;i<p;i++)
		if(a.arr[i]!=b.arr[i])return 0;
	return 1;
}

int b_search(int h,int l,struct U a)
{
	if(h>=l)
	{
		if(equal(a,z[h]))return z[h].num;
		if(equal(a,z[l]))return z[l].num;
		return -1;
	}
	int mid=(h+l)/2;	
	if(equal(a,z[mid]))return z[mid].num;
	else if(less(z[mid],a))return b_search(mid+1,l,a);
	else return b_search(h,mid-1,a);
}

int main()
{
	scanf("%d %d",&n,&p);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<p;j++)scanf("%d",&z[i].arr[j]);
		z[i].num=i+1;
	}
	for(int j=0;j<p;j++)scanf("%d",&Ch.arr[j]);
	
	std::sort(z,z+n,sot);
	bool b=1;
	int k;
	struct U K;
	k=b_search(0,n-1,Ch);
	if(k!=-1)printf("%d",k),b=0;
	if(b)
		for(int i=0;i<n&&b;i++)
		{
			for(int j=0;j<p;j++) K.arr[j]=Ch.arr[j]-z[i].arr[j];
			k=b_search(i+1,n-1,K);	
			if(k!=-1)
			{
				if(k==z[i].num)continue;
				if(k<z[i].num)printf("%d %d",k,z[i].num);
				else printf("%d %d",z[i].num,k);
				b=0;
				break;		
			}
		}
	
	if(b)printf("NO");
	return 0;
}
