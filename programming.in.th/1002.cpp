#include "stdio.h"
int I=0,V=0,X=0,L=0,C=0;


void check(int n)
{
	int k=0;
 while(n>0)
 {
 	if(k==0)
 	 switch(n%10)
	  {
	  	case 1:I++; break;
	  	case 2:I+=2; break;
	  	case 3:I+=3; break;
	  	case 4:I++,V++; break;
	  	case 5:V++; break;
	  	case 6:V++,I++; break;
	  	case 7:V++,I+=2; break;
	  	case 8:V++,I+=3; break;
	  	case 9:X++,I++; break;
	  }	
	else if(k==1)
	switch(n%10)
	{
		case 1:X++; break;
	  	case 2:X+=2; break;
	  	case 3:X+=3; break;
	  	case 4:X++,L++; break;
	  	case 5:L++; break;
	  	case 6:X++,L++; break;
	  	case 7:L++,X+=2; break;
	  	case 8:L++,X+=3; break;
	  	case 9:X++,C++; break;
	}  
	    else if(k==2)
	    switch(n%10)
		{
			case 1:C++;break;
			case 2:C+=2;break;
			case 3:C+=3;break;
		}
 	k++;
 	n/=10;
 }

}


int main()
{
int n;
scanf("%d",&n);
for(int i=1;i<=n;i++)check(i);
printf("%d %d %d %d %d",I,V,X,L,C);
return 0;	
}
