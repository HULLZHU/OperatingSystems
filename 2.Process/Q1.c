#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc, char *argv[])
{
    printf("Hello world, this is the parent process. PID(%d)\n",(int)getpid());
    int x = 0;
    printf("(1)x : %d\n",x);
    //If fork() returns a negative value, the creation of the child process was unsuccessful
    //fork() returns a zero to the newly created child process
    //fork() return the PID (a positive number) of the child process to the parent
    int rc = fork();
    x = 200;
    if(rc < 0)
    {
        printf("Child Process Creation Failed \n");
        exit(1);
    }
    else if(rc == 0)
    {
        printf("This is the child process. PID:%d, rc:%d\n", (int)getpid(),rc);
        x = 100;
        printf("(2)x: %d\n",x);
    }
    else
    {   
        int wc = wait(NULL);
        printf("This is the parent process. PID: %d, wc: %d\n",(int)getpid(),wc);
        printf("(3)x: %d\n",x);
    }

    return 0;
}