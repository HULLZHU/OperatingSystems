#define _GNU_SOURCE
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if(rc < 0)
    {
        printf("Fork Failed\n");
        exit(1);
    }
    else if(rc == 0)
    {   
        //Because child process cannot call any more child process, so -1 is returned
        pid_t pid = wait(NULL);
        printf("Child Process; Wait PID: %d\n", (int)pid);
    }
    else
    {   //the PID of the child process is returned
        pid_t pid = wait(NULL);
        printf("Parent Process; Wait PID: %d\n ",(int)pid);
    }

    return 0;
}