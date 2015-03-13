#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>

#define BUFFER 1024

int main(int argc, char *argv[])
{
	int fd1, fd2, d[5], d1[5], n, p, j, i;
	char buf[BUFFER];
	/*copy <fname1> <fname2> format */
	if (argc == 3) {
		fd1 = open(argv[1], O_RDONLY | O_SYNC);
		if (fd1 == -1) {
			printf("%s : NO such file\n", argv[1]);
			return (0);
		}
		p = creat(argv[2], 0755);
		fd2 = open(argv[2], O_WRONLY);
		if (fd1 == -1 || fd2 == -1)
			printf("file opening error\n");
		else {		/*Reading from fname1 to buffer and writing it to
				   from buffer fname2 */
			while ((n = read(fd1, buf, BUFFER)) > 0)
				write(fd2, buf, n);
		}
		close(fd1);
		close(fd2);
	}
	/* Copy fn1 fn2 ... dir(copy many files to directory) */
	else if (argc > 3) {

		char dir[100];
		/*Get Current Working Directory */
		getcwd(dir, 100);
		j = mkdir(argv[argc - 1], S_IRUSR | S_IWUSR | S_IXUSR);
		for (i = 1; i < argc - 1; i++)
			d[i] = open(argv[i], O_RDONLY | O_SYNC);
		/*Change to the Directory specified in the command
		   line */
		chdir(argv[argc - 1]);
		/*Copy all files to the current directory */
		for (i = 1; i < argc - 1; i++) {
			creat(argv[i], 0755);
			d1[i] = open(argv[i], O_WRONLY);

			while ((n = read(d[i], buf, BUFFER)) > 0)
				write(d1[i], buf, n);
		}
		/*Change back to parent directory */
		chdir(dir);

	} else
		printf("Error : Usage <kdcp> <fname>...<dir>\n");

	return (0);
}
