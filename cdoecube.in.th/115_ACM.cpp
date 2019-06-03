#include "stdio.h"

int t[100];

int ch(char *a)
{
	int P=0,i,X=0,T=0;
	for(i=0;a[i]!=0;i++)
	{
		if(a[i]=='P')
			P++;
		else if(a[i]=='X')
			X++;
		else if(a[i]=='T')
			T++;				
	}
	if(X)return 3;
	else if(T)return 2;
	else if(P==i)return 0;
	return 1;
}

int main()
{
	int n;
	char a[21];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",a);
		t[i]=ch(a);	
	}	
	for(int i=0;i<n;i++)
	{
	printf("Case #%d: ",i+1);
	if(t[i]==0)printf("Yes\n");
	else if(t[i]==1)printf("No - Wrong answer\n");
	else if(t[i]==2)printf("No - Time limit exceeded\n");
	else if(t[i]==3)printf("No - Runtime error\n");
	}
	return 0;
}
