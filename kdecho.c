f_kdecho(int argc, char *argv[])
{
	int i = 0;
/*Read all the positional parameters and display it on 
  the standard output*/
	for (i = 1; i < argc; i++) {
		printf("%s\t", argv[i]);
	}
	printf("\n");
	return (0);
}
