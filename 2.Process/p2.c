#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include"common.h"
/*
(1) stdin: stream data going into a program; file discriptor = 0 
(2) stdout: the stream where a program writes its output data; file discriptor = 0
(3) stderr: used to output error message or diagnostics.; Independent of stdin and stdout
*/

int getTime()
{
    return 10;
}

int main(int argc, char * argv[])
{
    printf("Hello world (pid: %d)\n",(int)getpid());
    int rc = fork();
    if(rc < 0 )
    {
        fprintf(stderr,"Fork Failed\n");
        exit(1);
    }
    else if(rc == 0 )
    {
        printf("Hello, I am child (pid: %d)\n",(int)getpid());
    }
    else
    {   //Wait for a child to die. When one does, put its status in *STAT_LOC  
        //and return its process ID. For errors, return (pid_t) -1
        int status;
        int wc = wait(&status);
        //rc and wc are both the PID of the child process
        printf("Hello, I am parent of %d(wc: %d) (pid: %d)", rc, wc,(int)getpid());
        printf("The Status Code of Child Process is : %d\n",status); 
    }
    
    return 0;
}