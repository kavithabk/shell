#include<sys/utsname.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int flag = 0;
	struct utsname var;
	flag = uname(&var);
	if (flag == -1)
		printf("error displaying output\n");
	else {
		if (argc == 1)
			printf("%s\n", var.sysname);
		else if (argc >= 3)
			printf("Error Usage:kduname <option>\n");
		else {		/*Displays kernel version */
			if (!(strcmp(argv[1], "-r")))
				printf("%s\n", var.release);
			/*Displays version release */
			if (!(strcmp(argv[1], "-v")))
				printf("%s\n", var.version);
			/*Displays machine hardware */
			if (!(strcmp(argv[1], "-m")))
				printf("%s\n", var.machine);

		}
	}

}
