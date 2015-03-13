#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	/*s-Text string pat-Pattern string */
	char s[80], pat[25];
	FILE *fp;
	int n, m, i, j, flag = 0;
	if (argc == 3) {
		fp = fopen(argv[2], "r");
		if (fp == NULL) {
			printf("File Opening error\n");
			return (0);
		} else {
			/*Read line by line from the file and search the pattern
			   string in each line */
			while (fgets(s, 79, fp) != NULL) {
				n = strlen(s);
				strcpy(pat, argv[1]);
				m = strlen(pat);
				for (i = 0; i < n - m; i++) {
					j = 0;
					while (j < m && pat[j] == s[i + j]) {
						j = j + 1;
					}
					/*If substring found in text string display the line */
					if (j == m) {
						printf("%s", s);
						flag = 1;
						break;
					}

				}

			}
			if (flag == 0)
				printf("Pattern not Found\n");
			fclose(fp);
		}
	} else
		printf("ERROR Usage : grep <pattern> <fname>\n");

	return (0);
}
