f_kdcd(int argc, char *argv[])
{
	int flag;
	char old[30];
	if (argc > 2)
		printf("Error Usage : cd <directory name>\n");
	else {
		getcwd(old, sizeof(old));
		printf("Present directory : %s\n", old);
		flag = chdir(argv[1]);
		if (flag == 0)
			printf("directory changed sucessfully\n");
		if (flag == -1)
			printf("Directory not changed\n");
	}
	return (0);
}
