#include "stdio.h"

int P[100],T[100],play[20]={0},n,k;

void input()
{
for(int i=0;i<n;i++)
  scanf("%d",&P[i]);
for(int i=0;i<n;i++)
  scanf("%d",&T[i]);
}

void loop()
{
int o,here=0,i,u=0;

for(i=0;i<n;i++)
{
	//printf("%d->",(here)%n+1);
 int w=0;	
 
 while(w<T[i]||P[here]<=0)
 {
 	if(P[here]>0)w++;
 	here=(here+1)%n;
 }
 
play[i%k]+=P[here];
P[here]=0;	
//printf("%d\n",(here)%n+1);
}

}
int main()
{
scanf("%d %d",&n,&k);
input();
loop();
for(int i=0;i<k;i++)
 printf("%d\n",play[i]);
return 0;
}
