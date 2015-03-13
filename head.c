#include<stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char ch, ch1, str[1];
	int lc = 0, n, l;

	switch (argc) {
	case 2:
		fp = fopen(argv[1], "r");
		while ((ch = fgetc(fp)) != EOF)
		{
			printf("%c", ch);
			if (ch == '\n') {
				++lc;
			}
			if (lc >= 10)
				break;
		}
		fclose(fp);
		break;
	case 4:
		if (!(strcmp(argv[1], "-n"))) {

			fp = fopen(argv[3], "r");

			while ((ch = fgetc(fp)) != EOF)
			{
				printf("%c", ch);
				if (ch == '\n') {
					lc++;
				}

				l = atoi(argv[2]);

				if (l == lc)
					break;
			}
		}
		fclose(fp);
		break;
	default:
		printf("Error: Usage head <fname>\t");
		printf("OR Usage : head -n no <fname>\n");
		break;
	}

	return (0);
}
