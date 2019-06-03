#include<stdio.h>

long gcd(long a,long z){
    long c;
   while(a!=0){
   	c=a;
	a=z%a;
	z=c;
   }
    return z;
}
int b[100000];
int main(){
	long i=1,y=-1,x,j=0,N;
	scanf("%ld",&N);   
	for(i=0;i<N;i++)
	{
    	scanf("%ld",&x);
    	b[i]=x;    	
    	if(i>0)
    	{
    	y=gcd(x,y);
		}
		else y=x;
    }
for(i=0;i<N;i++){
	j+=b[i]/y;
}
	printf("%ld",j);
return 0;
}


