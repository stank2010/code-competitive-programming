#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
typedef struct point{
 int x,y,level;
};
int a[201][201],b[201][201],n,m,map[201][201];
point q[50001];
main()
{
 scanf("%d %d",&m,&n);
 int x1,y1,x2,y2;
 scanf("%d %d",&x1,&y1);//start point
 scanf("%d %d",&x2,&y2);//end point
 for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)scanf("%d",&map[i][j]);
 int first,last = first = 0,level=1;
 //checking from the starting point.
 q[last].x = x1;
 q[last].y = y1;
 q[last++].level = level;
 for(;first!=last;)
 {
  int x = q[first].x,y = q[first].y,level = q[first++].level;
  if(a[x][y]==0)
  {
   a[x][y] = level++;
   if(x>1&&map[x-1][y]==1)
   {
    q[last].x = x-1;
    q[last].y = y;
    q[last++].level = level;
   }
   if(x<m&&map[x+1][y]==1)
   {
    q[last].x = x+1;
    q[last].y = y;
    q[last++].level = level;
   }
   if(y<n&&map[x][y+1]==1)
   {
    q[last].x = x;
    q[last].y = y+1;
    q[last++].level = level;
   }
   if(y>1&&map[x][y-1]==1)
   {
    q[last].x = x;
    q[last].y = y-1;
    q[last++].level = level;
   } 
  }
 }
 //first part displaying
 
 /*printf("\n");
 for(int i=1;i<=m;i++)
 {
  for(int j=1;j<=n;j++)printf("%d ",a[i][j]);
  printf("\n");
 }*/
 first = last = 0;
 level=1;
 q[last].x = x2;
 q[last].y = y2;
 q[last++].level = level;
 for(;first!=last;)
 {
  int x = q[first].x,y = q[first].y,level = q[first++].level;
  if(b[x][y]==0)
  {
   b[x][y] = level++;
   if(x>1&&map[x-1][y]==1)
   {
    q[last].x = x-1;
    q[last].y = y;
    q[last++].level = level;
   }
   if(x<m&&map[x+1][y]==1)
   {
    q[last].x = x+1;
    q[last].y = y;
    q[last++].level = level;
   }
   if(y<n&&map[x][y+1]==1)
   {
    q[last].x = x;
    q[last].y = y+1;
    q[last++].level = level;
   }
   if(y>1&&map[x][y-1]==1)
   {
    q[last].x = x;
    q[last].y = y-1;
    q[last++].level = level;
   } 
  }
 } 
 //second part displaying
/* printf("\n");
 for(int i=1;i<=m;i++)
 {
  for(int j=1;j<=n;j++)printf("%d ",b[i][j]);
  printf("\n");
 }*/

 //main display;
 int count=0,minn1,minn2,dist;
 dist = INT_MAX;
 for(int i=1;i<=m;i++)
 {
  for(int j=1;j<=n;j++)
  {
   if(map[i][j]==0)
   {
    int x=i,y=j;
    if(a[x][y+1]!=0||a[x][y-1]!=0||a[x-1][y]!=0||a[x+1][y]!=0)
    {
     if(b[x][y+1]!=0||b[x][y-1]!=0||b[x-1][y]!=0||b[x+1][y]!=0)
     {
      count++;
      minn1 = minn2 = INT_MAX;
      if(a[x][y+1]!=0)minn1 = min(minn1,a[x][y+1]);
      if(a[x][y-1]!=0)minn1 = min(minn1,a[x][y-1]);
      if(a[x+1][y]!=0)minn1 = min(minn1,a[x+1][y]);
      if(a[x-1][y]!=0)minn1 = min(minn1,a[x-1][y]);
      
      if(b[x][y+1]!=0)minn2 = min(minn2,b[x][y+1]);
      if(b[x][y-1]!=0)minn2 = min(minn2,b[x][y-1]);
      if(b[x+1][y]!=0)minn2 = min(minn2,b[x+1][y]);
      if(b[x-1][y]!=0)minn2 = min(minn2,b[x-1][y]);
      
      //printf("%d %d %d\n",minn1,minn2,minn1+minn2);
      dist = min(dist,minn1+minn2+1);
     }
    }
   }
  }
 }
 printf("%d\n%d",count,dist); 
}
