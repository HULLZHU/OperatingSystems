#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include "common.h"
//Compilation cmd: "gcc -pthread -o thread thread.c -Wall -pthread"
//how to run "./thread 10000"

//"volatile" key word is a low level keyword
//dealing with devices:


//(1)Compiler cannot do any optimization on 
//the variable with "volatile" keyword


//(2)When to use the "volatile" keyword:

//(2.1): Global variables modified by any
//interrupt service rountine outside the scope

//(2.2): Gloabl varible within a multi-thread 
//application


volatile int counter = 0;

int loops;
//void* declares a pointer without specifying
//which datatype it is pointing to.
void* worker(void *arg)
{
    int i;
    for(i = 0 ; i < loops; i ++ )
    {
        counter ++;
    }

    return NULL;
}


//argc: the count of arguments
//argv: an array of strings
//the program itsel is the first argument argv[0]
//so argc>= 1;
//if argc = 2, then the program is run with one command-line argument
//if argc !=2, then the program run with number of argument = 0 or >1
int main(int argc, char *argv[])
{
    if(argc !=2)
    {
        fprintf(stderr,"Usage: threads <value>\n");
        exit(1);
    }
    //int atoi(const char *str)
    //converts a string parameter to an integer
    //Get the number of loops
    loops = atoi(argv[1]);

    pthread_t p1,p2;
    printf("Initial Value: %d\n",counter);

    //each thread starts running running in a routine called worker()
    pthread_create(&p1,NULL,worker,NULL);
    pthread_create(&p2,NULL,worker,NULL);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    printf("Final Value: %d\n", counter);
    
    return 0;
;}