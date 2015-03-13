#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/termios.h>
#include<dirent.h>
#include<errno.h>
#include<pwd.h>
#include<grp.h>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;
	char *ptr;
	int count = 0;
	printf("entered\n");
	if (argc > 2) {
		printf("error\n");
		return (0);
	}
	if (argc == 2) {
		if (!(strcmp(argv[1], "-x"))) {
			dp = opendir(".");

			while ((dirp = readdir(dp)) != NULL) {
				if ((count % 3) == 0)
					printf("\n");
				count++;
				printf("%-25s", dirp->d_name);
			}
		}
	}

	if (argc == 1)
		argv[1] = ".";
	dp = opendir(argv[1]);

	if (dp == NULL) {
		printf("dir cannot be opened\n");
		return (0);
	}
	while ((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);
	closedir(dp);
	return (0);
}
