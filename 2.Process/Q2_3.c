#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include<sys/stat.h>

/*use fopen() rather than open()
(1) fopen() provides buffering I/O, quicker
(2) fopen() returns FILE*, which give the ability to use fscanf() and other stdio functions
(3) compatible with ANSI C environment
(4) fopen() supports line ending translation if the file is not opened in binary mode*/


int main(int argc, char *argv[]) {
    int rc = fork();//call child process
    int fd = open("./2.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
    write(fd,"First Line.\n",strlen("First Line.\n"));

    if( rc < 0 )
    {
        fprintf(stderr,"Fork Failed\n");
        exit(1);
    }
    else if(rc == 0)//child process
    {
        write(fd,"child writes a line. \n",strlen("child writes a line. \n"));
        printf("File Descriptor in Child Process: %d \n", fd);
    }
    else // parent process
    {
        write(fd,"parent writes a line\n", strlen("parent writes a line\n"));
        printf("File Descriptor in Parent Process: %d\n",fd);
    }

    FILE *fp;
    fp = fopen("./2.txt","r");
    int ch;
    printf("File Contents: \n");
    while((ch = fgetc(fp))!= EOF)
    {
        printf("%c",ch);
    }
    printf("\n");
    fclose(fp); //fp is created by fopen()
    close(fd);//fd is created by open() 
    return 0;
    
}