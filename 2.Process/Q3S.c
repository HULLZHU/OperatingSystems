#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
//C standard Libary, signal process
#include<fcntl.h>
#include<sys/stat.h>

//define a handler function
void sigcont_handler(int signum)
{
    printf("Good Bye\n");
}

int main(int argc, char const* argv[])
{
    int parent_pid = getpid();//assign parent pid 
    int rc = fork();//call the child process
    struct sigaction act;
    act.sa_handler = sigcont_handler;

    if(rc < 0)
    {
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    }
    else if(rc == 0)
    {
        kill(parent_pid, SIGCONT);
        printf("Hello\n");
    }
    else
    {
        //send a SICONT siganl to a process to make it continue
        sigaction(SIGCONT,&act,NULL);
        pause();
    }
    return 0;
}