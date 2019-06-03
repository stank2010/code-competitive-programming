#include "stdio.h"

//"node" link list structure
typedef struct node
{
	node *next;
	int data;
}node;

//input/create and sort list
node* input(node *NODE,int x)
{	
  if(NODE==NULL) //When Emptly
  {
	NODE=new node;
	NODE->data=x;
	NODE->next=NULL;
  }
else
   {
	node *D,*target;
	D=NODE;
	target=new node;
	target->data=x;
	
	if(x>=D->data)    //check x lower than D->data(D:first list)
	{
		target->next=D;	
		NODE=target;
	}
	else 
	{
		while(D->next!=NULL&&x<=D->next->data)D=D->next;
		target->next=D->next;
		D->next=target;
	}
	
   }
  return NODE; 
}

node* del(node *N)
{
	printf("%d\n",N->data);
	N=N->next;
	return N;
}

int main(){
	node *NODE=NULL;
	int n,a;
	char c;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf(" %c",&c);// printf("%c",c);
		if(c=='P')
		{
			scanf("%d",&a);
			NODE=input(NODE,a);
		}
		else if(c=='Q')
		{
			if(NODE==NULL)printf("-1\n");
			else NODE=del(NODE);
		}
		//NODE=input(NODE,i);
	}
	//read(NODE); 
return 0;	              
}
