#include "stdio.h"

int n , mem[1001][1001];
char card[1001];

int div(int left,int right)
{
	if(left >= right)
		return mem[left][right] = 0;
	if(mem[left][right] != -1)
		return mem[left][right];
	
	int Max = 0 , sum = 0;
	for(int i=left+1;i<=right;i++)
		if(card[i] == card[left])
		{
			sum = div(left+1,i-1) + div(i+1,right) + 1;
			if(sum > Max)
				Max = sum;
		}
		
	sum = div(left+1,right);
	if(sum > Max) 
		Max = sum;
	
	return mem[left][right] = Max;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf(" %c",&card[i]);
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			mem[i][j] = -1;
	
	printf("%d",div(0,n-1));
	return 0;
}
