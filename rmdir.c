#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
	char p[10];
	int i = 1, j = 1, k = 0;
	if (argc < 2) {
		printf("USAGE rmdir <dir_name> ...\n");
		return (0);
	}
	k = strcmp(argv[1], "-i");
	for (i = 1; i < argc; i++) {
		if (k != 0) {
			j = rmdir(argv[i]);
			if (j == 0)
				printf("%s directory removed\n", argv[i]);
			else
				printf("No such file or directory\n");
		} else if (k == 0 && i > 1) {

			printf("Do you want to delete %s dir:Y/N\n", argv[i]);
			fflush(stdin);
			scanf("%s", &p);
			if (!strcmp(p, "y") || !strcmp(p, "Y")) {
				j = rmdir(argv[i]);
				if (j == 0)
					printf("%s dir removed\n", argv[i]);
				else
					printf("No such file or directory");
			}
		} else
			continue;

	}
}
