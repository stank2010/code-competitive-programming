#include "stdio.h"
#include "algorithm"

using namespace std;

typedef struct{
int x;
int y;
}play;

play st[7];

bool ch(play a,play b)
{
if(a.y==b.y)return a.x<b.x;
else return a.y>b.y;
}

int k=7,b=0;

void check()
{

int min,o=0,p=0,sp=6;

for(int i=6;i>=0;i--)
if(st[i].y>=0)
{
min=st[i].y; 
sp=i; 
break;
} //find min & num. index


for(int i=6;i>=0;i--)
if(st[i].y<min && st[i].y>=0)
min=st[i].y,sp=i;

for(int i=0;i<7;i++)
if(st[i].y==min)
sp=i,o++; 
else if(st[i].y>=0)p++;

if(o==1&&p>=1)
st[sp].y=-1,k--;
}

int main()
{
for(int i=0;i<7;i++)st[i].x=i,st[i].y=0;

while(1)
{
char a[100001];
scanf("%s",a);
if(a[0]=='!')break;

for(int i=0;a[i]!='\0';i++)
if(st[a[i]-'A'].y>=0)
st[a[i]-'A'].y++;

if(k>1)check();
}	

sort(st,st+7,ch);
printf("%d\n",k);
for(int i=0;i<k;i++)printf("%c %d\n",st[i].x+'A',st[i].y);
return 0;
}
