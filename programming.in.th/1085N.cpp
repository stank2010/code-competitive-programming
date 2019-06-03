#include "stdio.h"

bool r[500001]={0};
int z[500001]={0},w[2][1000000],W[500001]={0};
int n,m,k;
void star(){for(int j=1;j<=n;j++)printf("%d ",z[j]);printf("\n");}

int main(){

scanf("%d %d %d",&n,&m,&k);
int i,j,a,b;
for(i=0;i<m;i++)scanf("%d %d",&a,&b),w[0][i]=a,w[1][i]=b,W[a]=1;

for(i=0;i<k;i++)scanf("%d",&a),r[a]=1;


z[1]=1; int max=1;

for(i=1;i<=n;i++)
if(z[i]==1)
{ 

if(W[i]==1)
	for(j=0;j<m;j++)
		if(w[0][j]==i)
			z[w[1][j]]=1;
				  
if(r[i]==0&&z[i+1]==0)
	z[i+1]=1;

if(i>max)
	max=i;
}
if(max==n)printf("1");
else printf("0 %d",max); 
 
return 0;
}

//PPPPPP-PPPPP-PPPPPPPPPPPPPPPPP
