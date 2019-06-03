#include "stdio.h"
#include "string.h"
#include "math.h"

double x=0.000,y=0.000;
int k=0;

void travel(int n,char a[3])
{
     if(strcmp(a,"N")==0)y+=n;
else if(strcmp(a,"S")==0)y-=n;
else if(strcmp(a,"E")==0)x+=n;
else if(strcmp(a,"W")==0)x-=n;
else if(strcmp(a,"NE")==0)x+=n*(sqrt(2)/2),y+=n*(sqrt(2)/2);
else if(strcmp(a,"NW")==0)x-=n*(sqrt(2)/2),y+=n*(sqrt(2)/2);
else if(strcmp(a,"SE")==0)x+=n*(sqrt(2)/2),y-=n*(sqrt(2)/2);
else if(strcmp(a,"SW")==0)x-=n*(sqrt(2)/2),y-=n*(sqrt(2)/2);
//printf("%d,%d\n",x,y);
}

int main(){
	
	int n=0,i;
	do{
		char a[6];
		
		scanf("%s",a);
	if(a[0]=='*')break;
	else{
		k=n=0;
		int t=1,u=0;
		char z[3];
		z[1]=z[0]='\0';
		while(a[k]>='0'&&a[k]<='9')k++;
		
		for(i=k-1;i>=0;i--)n+=(a[i]-'0')*t,t*=10;
			
		for(i=k,u=0;a[i]!='\0';i++,u++)z[u]=a[i];
		travel(n,z);
	    }	
	  }while(1);
	
	
double z;
z=sqrt(x*x+y*y);
printf("%.3f %.3f\n%.3f",x,y,z);

	return 0;
}
