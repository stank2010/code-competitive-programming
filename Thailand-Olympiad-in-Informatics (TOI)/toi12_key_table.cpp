#include "stdio.h"
#include "string.h"
bool dp[1005][1005];

char a[1005],b[1005],c[2002];
int A,B,C;

void doing()
{
	dp[0][0] = true;
	 
    for(int i=1;i<=A;i++)
        dp[i][0] = dp[i-1][0] && (c[i]==a[i]);

    for(int i=1;i<=B;i++)
        dp[0][i] = dp[0][i-1] && (c[i]==b[i]);

    for(int i=1;i<=A;i++)
        for(int j=1;j<=B;j++)
            dp[i][j] = (dp[i-1][j] && c[i+j]==a[i]) || (dp[i][j-1]&&c[i+j]==b[j]);

    if(dp[A][B])printf("Yes\n"); else printf("No\n");

    for(int i=0;i<=A;i++)
        for(int j=0;j<=B;j++)
            dp[i][j]=0;
}


int main()
{
    int t;
    scanf("%s %s %d",a,b,&t);
    A=strlen(a);
    B=strlen(b);

    for(int i=A;i>0;i--)a[i]=a[i-1];
    for(int i=B;i>0;i--)b[i]=b[i-1];

    for(int i=0;i<t;i++)
    {
        scanf("%s",c);
        C=strlen(c);
        for(int j=C;j>0;j--)c[j]=c[j-1];
        doing();
    }

    return 0;
}

