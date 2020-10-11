#include <stdio.h>

#define N 10

int main()
{
    char a[20]={'a','b'};
    char b[N]={'c','d'};
    
    char *p=a;
    char *ptr=b;

    while ((*p)!=0){
        //printf("%c",*p);
        ++p;}
    while ((*ptr)!=0)
    {   
        *p=*ptr;
        ++p;
        ++ptr;
        
    }
    printf("%s",a);

    return 0;
}