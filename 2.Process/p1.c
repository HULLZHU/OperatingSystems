//unistd.h provides the access to the 
//POSIX (Portable Operating System Interface) 
//operating system API. 
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    //This I/O must occurs
    printf("Hello, world. (pid: %d)\n",(int)getpid());
    //The newly created process is exactly copy of the calling program;
    //The child process does not start running at main() again, but 
    //starts coming into life as if had called fork() itself.
    int rc = fork();
    if(rc < 0 )
    {
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if(rc == 0)//If the process is the child process, rc == 0
    {
        printf("Hello, I am a child. (pid: %d)\n", (int)getpid());
    }
    else//If the process is the parent process, rc is the pid of the child process
    {
        printf("Hello, I am a parent of %d. (pid %d)\n",rc,(int)getpid());
    }
    

}