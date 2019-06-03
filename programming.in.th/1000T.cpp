#include "stdio.h"
#include "string.h"
int main()
{
int l,n,i,u,k=0,o=0;
bool b=1;
char a[2][1001],ans[1001]="1";
scanf("%d %d",&l,&n);
for(i=0;i<n;i++)
{
if(i>0)
 {
	if(i%2)scanf("%s",a[1]);
	else scanf("%s",a[0]);
if(b){	
	o=0;
 for(u=0;u<l&&o<=2;u++)if(a[0][u]!=a[1][u])o++;	

if(o>2)
 {
 if(i%2)strcpy(ans,a[0]);
 else strcpy(ans,a[1]);
 b=0;
 }
     }
 
 }
else scanf("%s",a[0]);   	
}
if(b)printf("%s",a[(n-1)%2]);
else printf("%s",ans);
return 0;
}
