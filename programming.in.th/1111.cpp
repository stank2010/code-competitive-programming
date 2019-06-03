#include "stdio.h"

unsigned long long int z[100002]={0};

int main(){
int n,a,b,c,M=1;	
  	scanf("%d",&n);

for(int i=0;i<n-1;i++){
	scanf("%d %d %d",&a,&b,&c);
	if(b>M)M=b;
	if(c+z[a]>z[b]&&(z[a]>0||a==1))z[b]=c+z[a];
}	
unsigned long long int max=z[0];
for(int i=M;i>0;i--)if(z[i]>max){max=z[i];}
printf("%llu",max);
	scanf(" ");
	return 0;
}
