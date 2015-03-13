#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include "kdpwd.c"
#include "kdcd.c"
#include "kdecho.c"
#include "kdman.c"
#include "login.c"
#define path "/home/kavitakr/Downloads/project/bond"
#define BUFSIZE  200
#define ARGVSIZE 40
#define DELIM "\n\t\r "

int main()
{
	int i = 0, n, returnval;
	char *args[ARGVSIZE], *str;
	char buf[BUFSIZE + 1];
	int flag;
	f_login();
	while (1) {
		n = 1;
		printf("\nBOND$");
		gets(buf);

		if (!(strcmp(buf, "kdexit")))
			exit(0);

		args[0] = strtok(buf, DELIM);

		while ((args[n] = strtok(NULL, DELIM)) != NULL) {
			n++;
		}
		args[n] = NULL;

		if (!(strcmp(args[0], "kdpwd")))
			f_kdpwd(n, &args[0]);
		else if (!(strcmp(args[0], "kdcd")))
			f_kdcd(n, &args[0]);
		else if (!(strcmp(args[0], "kdecho")))
			f_kdecho(n, &args[0]);
		else if (!(strcmp(args[0], "kdman")))
			f_kdman(n, &args[0]);
		else if (!(strcmp(args[0], "kdclear")))
			system("tput clear");
		else {
			switch (fork()) {
			case 0:
				if ((execvp(args[0], &args[0]) < 0))
					exit(1);
				break;

			default:
				wait(&returnval);

				flag = WEXITSTATUS(returnval);
				if (flag == 1) {
					printf("COMMAND NOT FOUND\n");
				}
				for (i = 0; i <= n; i++)
					args[i] = "\0";
				for (i = 0; i < BUFSIZE + 1; i++)
					buf[i] = '\0';
				break;
			}
		}
	}
}
