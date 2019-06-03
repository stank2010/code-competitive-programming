#include "stdio.h"
unsigned long long int z[2000001]={0};

int main(){
unsigned long long int T=0,a,n,i,A;

//float T=0.0;

scanf("%llu",&n);	
for(i=0;i<n;i++)scanf("%llu",&a),z[a]++;
scanf("%llu",&A);
for(i=0;i<=A/2;i++){
	if(i==A-i){T+=(z[i]*(z[i]-1))/2;}
    else T+=z[i]*z[A-i];
}

printf("%llu",T);
	return 0;
}
