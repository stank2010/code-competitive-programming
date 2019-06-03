#include "stdio.h"

char z[1002][1002];

int main()
{
	int r,c,k=0;
	scanf("%d %d",&r,&c);
	for(int i=0;i<r;i++)
		scanf("%s",z[i]);
	
	for(int i=0;i<r;i++)
	 	for(int j=0;j<c;j++)
	 		{
	 		if(z[i][j]=='+')
	 		{
	 		if(z[i+1][j]=='A')
				z[i+1][j]='.';
		
			if(z[i-1][j]=='A')
				z[i-1][j]='.';
			
			if(z[i][j+1]=='A')
				z[i][j+1]='.';
			
			if(z[i][j-1]=='A')
				z[i][j-1]='.';
			z[i][j]='.';		
			}
	 		
	 		else 
	 			if(z[i][j]=='x')
	 			{
	 			for(int o=1;o<=2;o++)
				 	{
				 	if(z[i+o][j+o]=='A')
	 				   z[i+o][j+o]='.';
	 					
					if(z[i+o][j-o]=='A')
					   z[i+o][j-o]='.';
					
					if(z[i-o][j-o]=='A')
					   z[i-o][j-o]='.';
						
					if(z[i-o][j+o]=='A')
					   z[i-o][j+o]='.';
					}	
	 				z[i][j]='.';
				}		
			 }
			 
				
	for(int i=0;i<r;i++)
	 	for(int j=0;j<c;j++)
	 		if(z[i][j]=='A')
	 		k++;
	 		
	 		printf("%d\n",k);
	for(int i=0;i<r;i++)
		printf("%s\n",z[i]);
	return 0;
}
