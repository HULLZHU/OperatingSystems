#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>

int main( int argc, char * argv[] )
{
    close(STDOUT_FILENO);
    open("Q2.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);

    char *myargs[3];
    myargs[0] = "wc";
    myargs[1] = "Q2.c";
    myargs[2] = NULL;
    execvp(myargs[0],myargs);

    int rc = fork();
    if( rc < 0 )
    {
        printf("Fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        /* child process */
        close(STDOUT_FILENO);
        open("Q2.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);

        char *myargs[3];
        myargs[0] = "wc";
        myargs[1] = "Q2.c";
        myargs[2] = NULL;
        execvp(myargs[0],myargs);
    }
    else
    {
        /*parent process*/
        char *myargs[3];
        myargs[0] = "wc";
        myargs[1] = "Q2.c";
        myargs[2] = NULL;
        execvp(myargs[0],myargs);
    }
    
    return 0;
}