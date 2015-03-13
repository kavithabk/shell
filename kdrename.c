#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int a;
	if ((argc != 3) && (!strcmp(argv[1], argv[2])))
		printf("prename : improper usage\n");
	else {
		a = rename(argv[1], argv[2]);
		if (a == -1)
			printf("Error : unable to rename\n");
		else
			printf("rename sucessfull\n");
	}
	return (0);
}
