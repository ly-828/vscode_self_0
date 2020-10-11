#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void pop_1(int*p,int x){
    
    int i=0,n=0,swap=0;

    for(i=0;i<x;i++)
        for(n=1;n<x;n++){
        if (p[i]<p[n])
        {
            swap=p[n];
            p[n]=p[i];
            p[i]=swap;
        }
        }
        
}

void pop_2(int*p,int x){
   
    int i=0,n=1,swap=0;

    for(i=0;i<x;i++)
        for(n=0;n<x;n++){
        if (p[i]>p[n])
        {
            swap=p[n];
            p[n]=p[i];
            p[i]=swap;
        }
        }
        
}

int main()
{
    int rd=0;
    int cnt =0,x=0,y=0;
    int sig[100],dob[100];

    for(cnt =0;cnt<99;cnt++){
        int a=0;
       
        a =rand()%(99)+1;
        
        if(a%2!=0)
        {
            sig[x]=a;
            x++;
        }
        else if(a%2==0){
            dob[y]=a;
            y++;
        }
    }
        
         pop_1(dob,y);
         pop_2(sig,x);

        int num =0;

        printf("single\n");
        while (num<x)
        { 
            printf("%d\n",sig[num]);
            num++;
        }
        printf("double\n");
        while (num<y)
        { 
            printf("%d\n",dob[num]);
            num++;
        }

        return 0;
}