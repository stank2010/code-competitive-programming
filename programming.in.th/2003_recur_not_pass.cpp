#include "stdio.h"

int A1[4],A2[4],n,max=0;
char foods[200001];
int mem[50000][3][3][3];


void fill(int *A,int val)
{
	if(A[0]==0)A[0]=val;
	else if(A[1]==0)A[1]=val;
	else if(A[2]==0)A[2]=val;
	else 
	{
		A[0]=A[1];
		A[1]=A[2];
		A[2]=val;
	}
}

int value(int *A)
{
	int type[4]={0},k=0;
	
	for(int i=0;i<3;i++)
	if(A[i]==0)
		break;
	else 
	{
		if(type[A[i]]==0)
			type[A[i]]++,k++;
	}
	return k;
}

int val_food(char A)
{
	if(A=='M')return 1;
	else if(A=='F')return 2;
	else if(A=='B')return 3;
}


void recur(int R,int a1,int a2,int val,int *A1,int *A2)
{
	
	int AA1[3],AA2[3];
	
	for(int i=0;i<3;i++)
		AA1[i]=A1[i],AA2[i]=A2[i];
	
	if(a1==1)
	{
		fill(AA1,val_food(foods[R]));
		val+=value(AA1);
	}
	
	else 
	if(a2==1)
	{
		fill(AA2,val_food(foods[R]));
		val+=value(AA2);
	}
	
	//printf("[%d]%d\n",R,val);	
	
	if(R==n-1)
	{
		if(val>max)
			max=val;
		
	}
	else 
	{
		recur(R+1,1,0,val,AA1,AA2);
		recur(R+1,0,1,val,AA1,AA2);
	}
}

int main()
{
	scanf("%d %s",&n,foods);
	recur(0,1,0,0,A1,A2);
	recur(0,0,1,0,A1,A2);
	printf("%d",max);
	return 0;
}
