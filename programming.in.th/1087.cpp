#include "stdio.h"

int z[300][300];

int main()
{
	int r,c,k,max;
	bool b=1;
	scanf("%d %d %d",&r,&c,&k);
	for(int i=0;i<r;i++)
	 for(int j=0;j<c;j++)
	   scanf("%d",&z[i][j]);
	   
	   
	for(int i=0;i<r;i++)
	 for(int j=0;j<c;j++)
	 {	
	 	int sum=z[i][j];
	 	for(int a=1;a<=k&&i+a<r;a++)
	 	  if(a%2==1)sum-=z[i+a][j];
	 	  else sum+=z[i+a][j];
	 	  
	 	for(int a=1;a<=k&&i-a>=0;a++)
	 	  if(a%2==1)sum-=z[i-a][j];
	 	  else sum+=z[i-a][j];
	 	
	 	for(int a=1;a<=k&&j+a<c;a++)
	 	  if(a%2==1)sum-=z[i][j+a];
	 	  else sum+=z[i][j+a];
	 	  
	 	for(int a=1;a<=k&&j-a>=0;a++)
	 	  if(a%2==1)sum-=z[i][j-a];
	 	  else sum+=z[i][j-a];
	    if(b)max=sum,b=0;
		else if(sum>max)max=sum; 
	 }
	 
	 printf("%d",max);
	return 0;
}
