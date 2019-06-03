#include "stdio.h"

int n,max=-6;
bool b[20][20]={0};


int main()
{
	int z[20][20],x,y;
	scanf("%d %d %d",&n,&x,&y);
	for(int i=0;i<n;i++)
	 for(int j=0;j<n;j++)
	 	scanf("%d",&z[i][j]);
	b[y-1][x-1]=1;
  	max=z[y-1][x-1];
  	
  	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(i-1>=0)
		  if(b[i-1][j]==1&&z[i][j]!=100&&z[i-1][j]<z[i][j])b[i][j]=1;
		  
		if(j-1>=0)
		  if(b[i][j-1]==1&&z[i][j]!=100&&z[i][j-1]<z[i][j])b[i][j]=1;
		  
		if(i+1<n)
		  if(b[i+1][j]==1&&z[i][j]!=100&&z[i+1][j]<z[i][j])b[i][j]=1;
		  
	  	if(j+1<n)
	  	  if(b[i][j+1]==1&&z[i][j]!=100&&z[i][j+1]<z[i][j])b[i][j]=1;
	  	  
	    if(b[i][j]&&z[i][j]>max&&z[i][j]!=100)max=z[i][j];    	  
	} 
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(i-1>=0)
		  if(b[i-1][j]==1&&z[i][j]!=100&&z[i-1][j]<z[i][j])b[i][j]=1;
		  
		if(j-1>=0)
		  if(b[i][j-1]==1&&z[i][j]!=100&&z[i][j-1]<z[i][j])b[i][j]=1;
		  
		if(i+1<n)
		  if(b[i+1][j]==1&&z[i][j]!=100&&z[i+1][j]<z[i][j])b[i][j]=1;
		  
	  	if(j+1<n)
	  	  if(b[i][j+1]==1&&z[i][j]!=100&&z[i][j+1]<z[i][j])b[i][j]=1;
	  	  
	    if(b[i][j]&&z[i][j]>max&&z[i][j]!=100)max=z[i][j];    	  
	} 
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(i-1>=0)
		  if(b[i-1][j]==1&&z[i][j]!=100&&z[i-1][j]<z[i][j])b[i][j]=1;
		  
		if(j-1>=0)
		  if(b[i][j-1]==1&&z[i][j]!=100&&z[i][j-1]<z[i][j])b[i][j]=1;
		  
		if(i+1<n)
		  if(b[i+1][j]==1&&z[i][j]!=100&&z[i+1][j]<z[i][j])b[i][j]=1;
		  
	  	if(j+1<n)
	  	  if(b[i][j+1]==1&&z[i][j]!=100&&z[i][j+1]<z[i][j])b[i][j]=1;
	  	  
	    if(b[i][j]&&z[i][j]>max&&z[i][j]!=100)max=z[i][j];    	  
	} 
  	
  	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(i-1>=0)
		  if(b[i-1][j]==1&&z[i][j]!=100&&z[i-1][j]<z[i][j])b[i][j]=1;
		  
		if(j-1>=0)
		  if(b[i][j-1]==1&&z[i][j]!=100&&z[i][j-1]<z[i][j])b[i][j]=1;
		  
		if(i+1<n)
		  if(b[i+1][j]==1&&z[i][j]!=100&&z[i+1][j]<z[i][j])b[i][j]=1;
		  
	  	if(j+1<n)
	  	  if(b[i][j+1]==1&&z[i][j]!=100&&z[i][j+1]<z[i][j])b[i][j]=1;
	  	  
	    if(b[i][j]&&z[i][j]>max&&z[i][j]!=100)max=z[i][j];    	  
	} 
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(i-1>=0)
		  if(b[i-1][j]==1&&z[i][j]!=100&&z[i-1][j]<z[i][j])b[i][j]=1;
		  
		if(j-1>=0)
		  if(b[i][j-1]==1&&z[i][j]!=100&&z[i][j-1]<z[i][j])b[i][j]=1;
		  
		if(i+1<n)
		  if(b[i+1][j]==1&&z[i][j]!=100&&z[i+1][j]<z[i][j])b[i][j]=1;
		  
	  	if(j+1<n)
	  	  if(b[i][j+1]==1&&z[i][j]!=100&&z[i][j+1]<z[i][j])b[i][j]=1;
	  	  
	    if(b[i][j]&&z[i][j]>max&&z[i][j]!=100)max=z[i][j];    	  
	} 
  	
	printf("%d",max);
	return 0;
}

/*void find(int z[20][20],int x,int y)
{
if(z[y][x]!=100)
{
	if(z[y][x]>max)max=z[y][x];
	//printf("%d (%d %d)\n",z[y][x],x,y);
	if(y+1<n)
	if(!b[y+1][x]){
	b[y+1][x]=1;	
	find(z,x,y+1);
	b[y+1][x]=0;
	}
	
	if(x+1<n)
	if(!b[y][x+1]){
	b[y][x+1]=1;	
	find(z,x+1,y);	
	b[y][x+1]=0;
	}
	if(y-1>=0)
	if(!b[y-1][x]){
	b[y-1][x]=1;	
	find(z,x,y-1);	
	b[y-1][x]=0;	
	}
	if(x-1>=0)
	if(!b[y][x-1]){
	
	b[y][x-1]=1;	
	find(z,x-1,y);	
	b[y][x-1]=0;
	}
}	
}
*/
