#include "stdio.h"

int mem[256][256][3];
char st[256];
int segi[3][3] = { {2,1,0} , {2,1,1} , {1,2,1} };

bool find(int left,int right,int key)
{
	if(mem[left][right][key] != -1)
		return mem[left][right][key];
		
	if(left == right)
		return mem[left][right][key] = key == st[left]-'0';
	
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		if(segi[i][j] == key)
		{
			bool check = false;
			for(int k=left;k<right;k++)
				if(find(left,k,i) and find(k+1,right,j))
					return mem[left][right][key] = true;
		}
		
	return mem[left][right][key]=false;
}

void input()
{
	int n;
	scanf("%d %s",&n,st);
	
	for(int i=0;i<256;i++)
		for(int j=0;j<256;j++)
			mem[i][j][0] = mem[i][j][1] = mem[i][j][2] = -1;
	if(find(0,n-1,0))
		printf("yes\n");
	else
		printf("no\n");
}

int main()
{
	for(int i=0;i<20;i++)
		input();
	return 0;
}
