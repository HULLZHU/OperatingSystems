#include<stdio.h>
#include<string.h>
int main()
{
    char source[] = "GeeksForGeeks";
    char *target = strdup(source);
    printf("S1: %s (%x) \n",source, (unsigned)&source[0]);
    printf("S2: %s (%x)",target, (unsigned)&target[0]);
    return 0;
}