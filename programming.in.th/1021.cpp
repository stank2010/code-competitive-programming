#include "stdio.h"

int z[300000],print[300000];

int main(){
    int o,i=0,k=0,p,I=0,max,sp,sum=0;
    char a;
    scanf("%d",&o);
    
    
    while(i<o){
            getchar(); scanf("%c",&a);
           if(a=='P'){scanf("%d",&p); z[k]=p; k++;}
      else if(a=='Q'){
          if(k>0){
              max=z[0]; 
              sp=0;
              
              for(int i=1;i<k;i++){
                      if(z[i]>=max){max=z[i]; sp=i;}
                      }
                      
              for(int i=sp;i<k;i++)z[i]=z[i+1];
              k--;
              print[I]=max; I++;
              }
          else {print[I]=-1; I++;}       
              
                      }      
      else {print[I]=-1; I++;}    
            i++;
              }
    for(i=0;i<I;i++)printf("%d\n",print[i]);
    
    scanf(" ");
 return 0;   
}
