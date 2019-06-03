#include "stdio.h"
#include "vector"

struct data_LIS
{
	int temp;
	long long int sum;
}data[100001];

std::vector<data_LIS> data_2[100001];

int Len;
int input[100001],n;
long long Max;

void LIS(int val)
{
	if(Len == 0)
	{
		data_LIS A;
		
		A.temp = A.sum = val;
		data_2[Len].push_back(A);
		
		Len++ ; 
	}
	else
	{
		if(val >= data_2[Len-1][ data_2[Len-1].size()-1 ].temp)
		{
			data_LIS A;
			
			A.temp = val;
			
			long long Min = 0;
			
			for(int i=0;i<data_2[Len-1].size();i++)
			{
				data_LIS B = data_2[Len-1][i];
				if(B.sum + val > Min and val >= B.temp)
					Min = B.sum + val;
			}
			
			A.sum = Min ;
			data_2[Len].push_back(A);
			Len++;
		}
		else if(val < data_2[0][ data_2[0].size()-1 ].temp)
		{
			data_LIS A;
			A.temp = A.sum = val;
			data_2[0].push_back(A);
		}
		else
		{
			int h = 1 , l = Len-1 , mid = (h+l)/2;	
			int mid_max = l;
						
			while(h <= l)
			{
				mid = (h+l)/2;
				if(val < data_2[mid][ data_2[mid].size()-1 ].temp )
				{
					if(mid < mid_max)
						mid_max = mid;		
					l = mid - 1;	
				}
				else
					h = mid + 1;
			}
			
			data_LIS St;
			St.temp = val;
			//data[mid_max].temp = val;
			
			long long Min = 0;
			
			for(int i=0;i<data_2[mid_max-1].size();i++)
			{
				data_LIS B = data_2[mid_max-1][i];
				if(B.sum + val > Min and val >= B.temp)
					Min = B.sum + val;
			}
			
			St.sum = Min;
			data_2[mid_max].push_back(St);
		}
	}
/*
	for(int i=0;i<Len;i++)
		printf("%2d(%2d) ",data[i].temp,data[i].sum);
	puts("");	
*/	
}



int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&input[i]);
		LIS(input[i]);
	}
	
	long long Max=0;
	
	for(int i=0 ; i < data_2[Len-1].size() ; i++)
	{
		data_LIS A = data_2[Len-1][i];
		if(A.sum > Max)
			Max = A.sum;	
	//	printf("%d %d\n",A.sum,A.temp);
	}
	
	
	printf("%d %lld",Len,Max);
	return 0;
}

/*
wrong case5
1 4 7 5 9

*/
