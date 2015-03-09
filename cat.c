#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#define BUFFER 1000

int main(int argc, char *argv[])
{
    int n,fd,i,p;
    FILE *fp;
    char buf[BUFFER],ch;

    if (argc > 1) {
        for (i = 1; i < argc; i++) {
            /*Open all files in Read mode*/
            fd=open(argv[i], O_RDONLY | O_SYNC);
            if (fd < 0) {
                printf("%s : No such file or directory\n",argv[i]);
                return(-1);
            }
            /*Read it from buffer and write to standard output*/
            while ((n = read(fd, buf, BUFFER)) > 0)
                write(STDOUT_FILENO, buf, n);
                close(fd);
        }
    } else
        printf("Error :Usage <kdcat> <fname>...\n");

    return(0);
}
