#include<stdio.h>

void f_kdman(int argc, char *argv[])
{
	int i = 0;
	if (argc == 1)
		printf("Which Command Information Do You Need?");
	else {
		printf("Welcome To The Journey  Of BOND SHELL\n");
		for (i = 1; i < argc; i++) {
			if (!(strcmp(argv[i], "ls"))) {
				printf("     kdls -  displays file listing\n");
				printf("     syntax  : <path>kdls .\n");
			} else if (!(strcmp(argv[i], "cat"))) {
				printf
				    ("     kdcat  -  displays file listing\n");
				printf
				    ("     syntax  : <path>kdcat <file name>...\n");

			} else if (!(strcmp(argv[i], "pwd"))) {
				printf
				    ("	kdpwd - Shows the present working directory\n");
				printf("	syntax  : kdpwd\n");
				printf("It is shell built in\n");
			} else if (!(strcmp(argv[i], "echo"))) {
				printf
				    ("	kdecho  -Echoes ithe input given to the command\n");
				printf("	syntax  :kdecho *\n");
				printf
				    ("Its both an internal and external command\n");
			} else if (!(strcmp(argv[i], "cd"))) {
				printf
				    ("	kdcd     -Changes the current working directory to the one  specified as the input\n");
				printf
				    ("	syntax   : <path>kdcd <dirname>\n");
				printf("Its a shell built in command \n");
			} else if (!(strcmp(argv[i], "cp"))) {
				printf("     kdcp     -Copies files\n");
				printf
				    ("     syntax   : kdcd <srcfile> <destfile>\n");
				printf
				    ("     syntax   : kdcd <file1> <file2>....<dir>\n");
				printf("Its an external command\n");
			} else if (!(strcmp(argv[i], "mkdir"))) {
				printf
				    ("     kdmkdir  -Create directory/directories\n");
				printf
				    ("     syntax   :<path>kdmkdir <dir> ....\n");
				printf("Its an external command\n");
			} else if (!(strcmp(argv[i], "rmdir"))) {
				printf
				    ("     kdrmdir  -Removes directories/directories \n");
				printf
				    ("     syntax   :<path>kdrmdir <dirname>... \n");
				printf("Its an external command \n");
			} else if (!(strcmp(argv[i], "rename"))) {
				printf
				    ("     kdrename -The command renames a file \n");
				printf
				    ("     syntax   :<path>kdrename <file1> <file2>\n");
				printf("Its an external command\n");
			} else if (!(strcmp(argv[i], "meridian"))) {
				printf
				    ("     kdmeridian-displays time and date\n");
				printf("     syntax   :kdmeridian\n");
				printf("Its an external command \n");
			} else if (!(strcmp(argv[i], "wc"))) {
				printf
				    ("     kdwc     -Gives the word,character and line count  of an input file \n");
				printf("     syntax   :<path>kdwc <fname> \n");
				printf("Its an external command\n");
			} else if (!(strcmp(argv[i], "bc"))) {
				printf("     kdbc      -Simple calucalator\n");
				printf("     syntax   :<path>kdbc        \n");
				printf("Its an external command\n");
			} else if (!(strcmp(argv[i], "uname"))) {
				printf
				    ("     kduname  -Displays operating systems details  options     -r Displays kernal version -v Displays version release -m Displays machine hardware\n");
				printf
				    ("     syntax   :<path>kduname option \n");
				printf("Its an external command\n");
			} else if (!(strcmp(argv[i], "rm"))) {
				printf
				    ("     kdrm     -Removes files and directories \n");
				printf("     syntax   :<path>kdrm <fname>\n");
				printf("Its an external command \n");
			} else if (!(strcmp(argv[i], "comm"))) {
				printf
				    ("     kdcomm   - Display the common lines between two files, lines unique to 1st file and lines unique to second file \n");
				printf
				    ("     syntax   :<path>kdcomm <file1> <file2>\n");
				printf("Its an external command\n");
			} else if (!(strcmp(argv[i], "cmp"))) {
				printf
				    ("     kdcmp    -Compares two files for first character mismatch\n");
				printf
				    ("     syntax   :<path>kdcmp <file1> <file2>\n");
				printf("Its an external command\n");
			} else if (!(strcmp(argv[i], "head"))) {
				printf
				    ("     kdhead   -Displays first 10 lines -n option displays the specified no of lines\n");
				printf
				    ("     syntax   :<path>kdhead op <fname>\n");
				printf("Its an external command\n");
			} else if (!(strcmp(argv[i], "tail"))) {
				printf
				    ("     kdtail   -Displays the last 10 lines \n");
				printf("     syntax   :<path>kdtail <fname>\n");
				printf("Its an external command\n");
			} else if (!(strcmp(argv[i], "exit"))) {
				printf("     kdexit   -Exit from the shell\n");
				printf("     syntax   :kdexit\n");
			} else
				printf("Command not found\n");
		}

	}

}
