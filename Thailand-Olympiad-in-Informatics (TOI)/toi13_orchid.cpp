#include "stdio.h"

int sub_seq[1000001],Length;

void LIS(int a)
{
	if(Length==0 || a >= sub_seq[Length-1])
		sub_seq[Length++] = a;
	else 
	{
		int h=0,l=Length-1,mid;
		
		int min_index = Length;
		
		while(h<=l)
		{
			mid = (h+l)/2;
			if(a < sub_seq[mid])
			{
				if(mid < min_index)
					min_index = mid;
				l = mid-1;	
			}
			else 
				h = mid+1;	
		}
		sub_seq[min_index]=a;
	}
}

int main()
{
	int n,a;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		LIS(a);
	}
	printf("%d",n-Length);
	return 0;
}
