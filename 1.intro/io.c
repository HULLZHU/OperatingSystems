#include<stdio.h>
#include<unistd.h>
#include<assert.h>
#include<fcntl.h> //use to include the O_XXX key words
#include<sys/types.h>
#define file "/home/hezhu/Documents/tmp/test2.txt"

int main(int argc, char* argv[])
{
    int fd = open(file,O_WRONLY|O_CREAT|O_TRUNC);
    printf("%d\n",fd);
    assert(fd > -1);
    int rc = write(fd,"hello world\n",13);
    assert(rc == 13);
    close(fd);
    return 0;
}