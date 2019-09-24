//for compilation, run : 
//(1) gcc -o cpu cpu.c -Wall
//(2) ./cpu A & ./cpu B & ./cpu C
//(3) ./cpu A 
#ifndef __commom__h
#define __common__h
#include<sys/time.h>
#include<sys/stat.h>
#include<assert.h>
#include<stddef.h>

double GetTime()
{   //timeval is a struct
    //with 2 members:
    //tv_sec and tv_usec
    struct timeval t;
    int rc = gettimeofday(&t,NULL);
    assert(rc == 0);
    return (double)t.tv_sec + (double)t.tv_usec/1e6;
}

void Spin(int howlong)
{
    double t = GetTime();
    while((GetTime()-t) < (double)howlong);
}

#endif