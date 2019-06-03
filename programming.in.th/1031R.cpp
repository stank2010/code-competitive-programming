#include "stdio.h"
//Use Quick Sort

bool T[10001][10001]={0};
int n,k,m;

int main(){
int z[10001]={0},u,i,a,b;
z[1]=1;
scanf("%d %d %d",&k,&n,&m);

for(i=0;i<m;i++){scanf("%d %d",&a,&b); T[a][b]=1;}

for(i=1;i<n;i++)
 for(u=1;u<=n;u++)if(T[i][u])
if(z[i]>0&&(z[u]>z[i]||z[u]==0))z[u]=z[i]+1;

for(i=n;i>=1;i--)if(z[i]>0&&z[i]<=k+1){printf("%d",i); break;}

scanf(" ");
return 0;
}
