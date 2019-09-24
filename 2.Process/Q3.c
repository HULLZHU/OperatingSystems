#include"common.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    int fb = open("Q3.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);

    if(rc < 0)
    {
        fprintf(stderr,"Failed Fork \n");
        exit(1);
    }
    else if(rc == 0)
    {//child process
        printf("Hello");
    }
    else
    {
        Spin(1);
        printf("Good Bye");
    }

    return 0;
}