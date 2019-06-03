#include "stdio.h"

int main(){
	int n,z[1000],Q[1000],s[3]={0},M=2001,p[2];
scanf("%d",&n);

for(int i=0;i<n;i++){
    scanf("%d",&z[i]);
  if(i==0)Q[0]=z[0];
  else Q[i]=z[i]+Q[i-1];
}

for(int i=1;i<n-2;i++)
  for(int u=i+1;u<n-1;u++){
  	s[0]=Q[i-1];
  	s[1]=Q[u-1]-Q[i-1];
  	s[2]=Q[n-1]-Q[u-1];
  	
	  int max=s[0],min=s[0];
  for(int y=0;y<3;y++){
  	if(s[y]>max)max=s[y];
  	if(s[y]<min)min=s[y];
  }	
 	if(max-min<M)p[0]=i,p[1]=u,M=max-min;//,printf("%d %d %d\n",s[0],s[1],s[2]);
}
printf("%d %d",p[0]+1,p[1]+1);

	scanf(" ");
	return 0;
}
