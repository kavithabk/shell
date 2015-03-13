#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int flag = 1;
	char ch;
	if ((argc < 2) || (argc >= 4))
		printf("Error : Usage : rm <option > <fname>\n");
	else if (argc == 2) {
		flag = unlink(argv[1]);
		if (flag == 0)
			printf("File Deleted Successfully\n");
		else
			printf("Error Deletting Successfully\n");
	} else if (!(strcmp(argv[1], "-i"))) {
		printf("Confirm Deletion [y/n] : ");
		scanf("%c", &ch);
		if (ch == 'y') {
			flag = unlink(argv[2]);
			if (flag == 0)
				printf("File Deleted Successfully\n");
			else
				printf("Error Deleting File \n");
		} else if (ch == 'n')
			printf("File not Deleted \n");
		else
			printf("Invalid Option\n");
	}
	return (0);
}
