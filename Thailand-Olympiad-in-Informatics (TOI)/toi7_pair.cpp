#include "stdio.h"
#include "algorithm"

struct U
{
    int A,B;
}arr[100001];

int z[100001],x[100001];

double k=0;

bool ch(struct U a,struct U b)
{
    return a.B<b.B;
}

void Swap(int &a,int &b){int c=a; a=b; b=c;}
void Merge(int h,int L);

void Sort(int h,int l)
{
    if(h>=l)return;
    if(h+1==l)
    {
        if(z[h]>z[l])Swap(z[h],z[l]),k+=(z[h]+z[l]);
        return;
    }

    int mid=(h+l)/2;
    Sort(h,mid);
    Sort(mid+1,l);
    Merge(h,l);
}

void Merge(int h,int L)
{
    int st=h;
    int l=(h+L)/2,H=l+1;
    int len=0;

    double cmd=0;

    while(h<=l||H<=L)
    {
        if(h>l)
            x[len++]=z[H++];
        else
            if(H>L)
            {
                k+=cmd*z[h];
                x[len++]=z[h++];
            }

        else
            if(z[h]>z[H])
            {
                //for(int j=h;j<=l;j++)
                k+=z[H]*(l-h+1);
                x[len++]=z[H++];
                cmd++;
            }

        else
        {
            k+=cmd*z[h];
            x[len++]=z[h++];
        }

    }

    for(int i=0;i<len;i++)z[st+i]=x[i];
}


void doing()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d %d",&arr[i].A,&arr[i].B);
    std::sort(arr,arr+n,ch);

    for(int i=0;i<n;i++)z[i]=arr[i].A;

    Sort(0,n-1);
    printf("%.0lf",k);
}

int main()
{
    doing();
    return 0;
}
