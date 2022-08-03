#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
 
int main(int argc, char *argv[])
{
    struct stat st;
    FILE *fp;
 
    if (access("temp", F_OK | W_OK) == 0)
        remove("temp");
 
    if ((fp = fopen("temp", "a")) == NULL)
    {
        fprintf(stderr, "Can't open file.");
        exit(EXIT_FAILURE);
    }
 
    fprintf(fp, "%s\n", argv[1]);
    fprintf(stderr, "Write Success!!!\n");
    fclose(fp);
 
    remove("temp");
    exit(EXIT_SUCCESS);
}

