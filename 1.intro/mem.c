#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include "common.h"

int main(int argc, char *argv[])
{
    int *p = malloc(sizeof(int));
    //assert(int expression);
    //if expression evaluates to false
    //(1) standard error occurs
    //(2) abort function is called
    assert(p!=NULL);

    //cast from pointer to integer
    printf("(%d) memomru address of p: %08x\n",getpid(),(unsigned int)p);
    
    //change the pointed object of p to be 0
    * p = 0;
    
    //repeatedly print the value of *p
    while(1)
    {
        Spin(1);//pause for 1 second
        *p = *p + 1;
        printf("(%d) p: %d \n",getpid(),*p);
    }

    return 0;
}