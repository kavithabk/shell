#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int a;
	if (argc != 3 && (!strcmp(argv[1], argv[2]))) {
		printf("Error : Improper usage\n");
		return (0);
	}
	a = link(argv[1], argv[2]);
	if (a != 0)
		printf("Unable to rename\n");
	return (0);
}
