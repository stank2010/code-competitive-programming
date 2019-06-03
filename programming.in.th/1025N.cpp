#include "stdio.h"

int z[50000],n;
bool p[100001]={0};
int Pr[100001]={0};

void tg(int a){
	for(int i=2;i<=a;i++)
	         {
	 	int u=2;
	 	while(i*u<=a)p[i*u]=1,u++;
		 	 }
}

void check(int a){
int Pl[100001]={0},n=a;
  for(int i=2;i<=a;i++){
  	if(!p[i]){
    	while(a%i==0)a/=i,Pl[i]++;
	         }
	if(Pl[i]>Pr[i])Pr[i]=Pl[i]; 
 }

}


int main(){
	scanf("%d",&n);
if(n==1)scanf("%d",&z[0]),printf("%d",z[0]);

else {
	int max=0;
	for(int i=0;i<n;i++){
		scanf("%d",&z[i]);
	    if(z[i]>max)max=z[i];
	                    }
	tg(max);
	
	for(int i=0;i<n;i++)check(z[i]);
	
	unsigned long long int f=1;
	for(int i=2;i<=max;i++)if(Pr[i]>0&&!p[i])for(int u=0;u<Pr[i];u++)f*=i;
	
	printf("%llu",f);
	}
	return 0;
}
