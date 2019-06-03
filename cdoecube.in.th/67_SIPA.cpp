#include "stdio.h"
char z[1001];

int main()
{
	scanf("%s",z);
	int o=0,b=1;
	for(int i=0;z[i]!=0;i++)
	{
		b=1;
		if(z[i]=='s'||z[i]=='S')
			if(z[i+1]=='I'||z[i+1]=='i')
				if(z[i+2]=='p'||z[i+2]=='P')
					if(z[i+3]=='a'||z[i+3]=='A')
						printf("\"%c%c%c%c\"",z[i],z[i+1],z[i+2],z[i+3]),o++,b=0,i+=3;
	if(b)printf("%c",z[i]);
	}
	printf("\n%d",o);
	
	return 0;
}
