#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if(rc < 0 )
    {
        fprintf(stderr,"Fork Fail\n");
        exit(1);
    }
    else if(rc == 0)
    {
        //child part
        close(STDOUT_FILENO);
        open("p4.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);

        //now exec "wc"
        char *myargs[3];
        //strdup(): This function returns a pointer to a null-terminated
        //byte string, which is a duplicate of the string pointed to
        // by s
        myargs[0] = strdup("wc");
        myargs[1] = strdup("p4.c");
        myargs[2] = NULL;
        execvp(myargs[0],myargs);
    }
    else
    {
        //parent part
        int wc = wait(NULL);
    }
    return 0;
}