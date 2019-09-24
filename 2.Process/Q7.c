#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd =  open("Q7.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
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
        int i = open("Q7.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
        //close(i);//close the descriptor
        //now exec "wc"
        char *myargs[3];
        //strdup(): This function returns a pointer to a null-terminated
        //byte string, which is a duplicate of the string pointed to
        // by s
        printf("Amazing, right?\n");//This one will be run, but overwritten by following commands
        myargs[0] = strdup("wc");
        myargs[1] = strdup("p4.c");
        myargs[2] = NULL;
        execvp(myargs[0],myargs);
        printf("Amazing, right?\n");// This one will not be run
    }
    else
    {
        //parent part
        int wc = wait(NULL);
    }
    return 0;
}