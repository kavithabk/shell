#include<stdio.h>
#include<fcntl.h>

#define BUFFER 80

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	int i = 0;
	char buf1[BUFFER], buf2[BUFFER];

	if (argc == 3) {
		fp1 = fopen(argv[1], "r");

		if (fp1 == NULL) {
			printf("%s : File opening Error\n", argv[1]);
			return -1;
		}

		fp2 = fopen(argv[2], "r");
		if (fp2 == NULL) {
			printf("%s : File opening Error\n", argv[2]);
			return -1;
		}

		while (((fgets(buf1, 79, fp1)) != NULL)
		       && ((fgets(buf2, 79, fp2)) != NULL)) {
			/*Center column strings which are equal */
			if (!strcmp(buf1, buf2)) {
				printf("\t\t %s\n ", buf1);
				continue;
			} else {
				/*1st column for strings which are unique to 1st file */
				printf("%s\n", buf1);
				/*3rd column for strings which are unique to 2nd file */
				printf("\t\t\t%s\n", buf2);
			}

		}
		fclose(fp1);
		fclose(fp2);
	} else
		printf("Error : Usage comm <fname1> <fname2>\n");
	return (0);
}
