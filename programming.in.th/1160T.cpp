#include "stdio.h"
#include<limits.h>
#define MIN(aa,bb) (aa<bb)?aa:bb
#define C(aa) (aa==-2)?1:aa

using namespace std;
int H,T;
struct Q{
	int x,y,r;
};
int k=0,z[200][200],L[200][200],r,c,X,Y,a,b,BB=0,xx,yy;

struct Q q[50000];

void insert(int XX,int YY,int R)
{
	q[T].x=XX;
	q[T].y=YY;
	q[T].r=R;
	T++;
}

int main()
{

	scanf("%d %d ",&r,&c);
	scanf("%d %d ",&Y,&X);	
	scanf("%d %d",&b,&a);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			scanf(" %d",&z[i][j]);
			
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			if(z[i][j]==0)z[i][j]=-2;
			else z[i][j]=0;		
	//Y--,X--,a--,b--;
	
	if(z[Y][X]==-2)z[Y][X]=0;
	
	xx=X,yy=Y;
	insert(X,Y,1);			
	while(H!=T)
	{
		Y=q[H].y;
		X=q[H].x;
		if(z[Y][X]==0)
		{
		L[Y][X]=1;
		z[Y][X]=q[H].r;
		if(X+1<=c)
			insert(X+1,Y,q[H].r+1);
		if(Y+1<=r)
			insert(X,Y+1,q[H].r+1);
		if(X-1>0)
			insert(X-1,Y,q[H].r+1);
		if(Y-1>0)
			insert(X,Y-1,q[H].r+1);
		}
		H++;
	}
	
	H=T=0;
	insert(a,b,1);
	while(H!=T)
	{
		Y=q[H].y;
		X=q[H].x;
		if(z[Y][X]==0)
		{
		L[Y][X]=2;
		z[Y][X]=q[H].r;
		if(X+1<=c)
			insert(X+1,Y,q[H].r+1);
		if(Y+1<=r)
			insert(X,Y+1,q[H].r+1);
		if(X-1>0)
			insert(X-1,Y,q[H].r+1);
		if(Y-1>0)
			insert(X,Y-1,q[H].r+1);
		}
		H++;
	}
	
	int m1,m2,d;
	m1=m2=d=INT_MAX;
	
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
		if(z[i][j]==-2)
		if(L[i][j+1]==1||L[i][j-1]==1||L[i+1][j]==1||L[i-1][j]==1)
		if(L[i][j+1]==2||L[i][j-1]==2||L[i+1][j]==2||L[i-1][j]==2)
		{
			k++;
			m1=m2=INT_MAX;
					if(L[i][j+1]==1)m1=MIN(m1,z[i][j+1]);	
					if(L[i][j+1]==2)m2=MIN(m2,z[i][j+1]);
					
					if(L[i+1][j]==1)m1=MIN(m1,z[i+1][j]);	
					if(L[i+1][j]==2)m2=MIN(m2,z[i+1][j]);
					
					if(L[i][j-1]==1)m1=MIN(m1,z[i][j-1]);	
					if(L[i][j-1]==2)m2=MIN(m2,z[i][j-1]);
					
					if(L[i-1][j]==1)m1=MIN(m1,z[i-1][j]);		
					if(L[i-1][j]==2)m2=MIN(m2,z[i-1][j]);
			d=MIN(d,m1+m2+1);	
			//printf("%d %d %d %d (%d,%d)\n",m1,m2,m1+m2,d,i+1,j+1);
		}
	/*	
		puts(" ");				
	for(int i=1;i<=r;i++)
		{
		for(int j=1;j<=c;j++)	
			printf("%d ",L[i][j]);
		puts(" ");	
		}
	*/	
	printf("%d\n%d",k,d);
	return 0;
}

