#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>

int main( int argc, char * argv[] )
{
    close(STDOUT_FILENO);
    int fd = open("Q2.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);

    write(fd,"(1) Hello World. Main Process\n", strlen("(1) Hello World. Main Process\n"));

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
        int fd = open("Q2.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
        write(fd,"(2) Hello World. Child Process\n", strlen("(2) Hello World. Child Process\n"));
        printf("File Descriptor of Child Process: %d\n",fd);
    }
    else
    {
        /*parent process*/
        close(STDOUT_FILENO);
        int fd = open("Q2.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
        write(fd,"(3) Hello World. parent Process\n", strlen("(3) Hello World. parent Process\n"));
        printf("File Descriptor of Child Process: %d\n",fd);
    }
    //create an file object
    FILE *fp;
    fp = fopen("./Q2.txt","r");
    int ch;
    printf("File Contents: \n");
    while((ch = fgetc(fp))!= EOF)
    {
        printf("%c",ch);
    }

    printf("\n");
    fclose(fp);
    close(fd);
    return 0;

    
    return 0;
}