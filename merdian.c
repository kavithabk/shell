#include<stdio.h>
#include<sys/times.h>
#include<time.h>

int main(int argc, char *argv[])
{
	if (argc > 2)
		printf("Error : Usage - time\n");
	else {
		time_t timv = time(0);
		printf("\n%s\n", ctime(&timv));
	}
	return (0);
}
