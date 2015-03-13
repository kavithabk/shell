#include<sys/stat.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
	int j = 1, i;
	/*If only command is given with no arguments */
	if (argc < 2) {
		printf("USAGE:mkdir <dir_name>\n");
		return (0);
	}

	for (i = 1; i < argc; i++) {
		/*Enable read,write and execute permision for the user */
		j = mkdir(argv[i], S_IRUSR | S_IWUSR | S_IXUSR);
		if (j == 0)
			printf("%s directory created successfully\n", argv[i]);
		else
			printf("Already exists\n");
	}
	return (0);
}
