#include "stdio.h"

char st[100001],z[100][10001];
int k=0;
bool Q[10];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	bool B=1;
	k=0;
		scanf("%s",z[i]);
		for(int j=0;z[i][j]!=NULL;j++)
		{
			
			if(z[i][j]=='{'||z[i][j]=='('||z[i][j]=='[')st[k]=z[i][j],k++;
			else
			{
				if(k>0)
				{
					if((st[k-1]=='['&&z[i][j]==']')||(st[k-1]=='('&&z[i][j]==')')||(st[k-1]=='{'&&z[i][j]=='}'))
					  st[k-1]='\0',k--;
				    else {B=0; break;}
				}
				else {B=0; break;}
			}
		}
		if(k>0)B=0;
		Q[i]=B;
	}
	for(int i=0;i<n;i++)
	 if(Q[i])printf("yes\n");
	 else printf("no\n");
	return 0;
}
