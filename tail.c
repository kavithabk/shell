#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	FILE *fp;
	char ch, s[80];
	int lc = 0, n;
	fp = fopen(argv[1], "r");
	while (fgets(s, 79, fp) != NULL) {
		lc++;

	}
	fclose(fp);
	n = lc - 10;
	printf("%d", n);
	fp = fopen(argv[1], "r");
	lc = 0;
	if (n < 0)
		printf("File doesnot contain so many lines\n");
	else {
		while (fgets(s, 79, fp) != NULL) {
			lc++;
			if (lc > n)
				printf("%s", s);
		}
	}

	fclose(fp);
	return (0);
}
