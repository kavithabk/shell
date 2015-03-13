f_kdpwd(int argc, char *argv[])
{
	if (argc > 2)
		printf("Error:Usage : kdpwd\n");
	else {
		char dir[100];
		getcwd(dir, sizeof(dir));
		printf("Current directory: %s\n", dir);
	}
}
  
