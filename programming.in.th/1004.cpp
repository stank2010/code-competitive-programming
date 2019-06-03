#include "stdio.h"

typedef  struct Q{
 int num;
 Q *next;	
}Q;

int st[10000],W[10000],U=0;

void add(Q *q[2],int x)
{
	if(q[0]==NULL)
	{
		q[0]=new Q;
		q[0]->num=x;
		q[0]->next=NULL;
        q[1]=q[0];	
	}
	else 
  {
	  Q *a;
	  a=new Q;
	  a->num=x;
	if(st[q[1]->num]!=st[x]) 
	{
		bool B=1;
	  for(Q *A=q[0];A!=NULL;A=A->next)
	  if(st[A->num]==st[x]&&st[A->num]!=st[A->next->num])
	  {
	  	a->next=A->next;
	  	A->next=a;
	  	B=0;
	  	break;
	  }
	  
	  if(B)
	  {
	  	a->next=NULL;	
	    q[1]->next=a;
	    q[1]=a;	
	  }
	} 
	else
	{
	a->next=NULL;	
	q[1]->next=a;
	q[1]=a;		
	}  
	
  }
}

void read(Q *q[2])
{
for(Q *a=q[0];a!=NULL;a=a->next)printf("%d ",a->num);	
}

int deq(Q *q[2])
{
if(q[0]!=NULL){
int x=q[0]->num;	
q[0]=q[0]->next;
return x;
}	
}


int main()
{
	Q *a[2];
	a[0]=a[1]=NULL;
/*	add(a,123);
	add(a,12);
	read(a);*/
  int n,c;
  scanf("%d %d",&c,&n);
  for(int i=0;i<n;i++)
  {
  	int x,y;
  	scanf("%d %d",&x,&y);
  	st[y]=x;
  }	
  
char t;
 do{
   	scanf("%c",&t);
   	if(t=='E')
   	{
    int v; 
    scanf("%d",&v);
    add(a,v);
	}
   	
   	else if(t=='D')
   	{
    W[U]=deq(a); U++;//printf("%d",deq(a));
	}
   	//printf("\n"); read(a); printf("\n");
   }while(t!='X'); 
  
	for(int i=0;i<U;i++)printf("%d\n",W[i]);
	printf("0");
	return 0;
}
