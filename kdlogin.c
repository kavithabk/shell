void f_login()
{
	char login[25], password[25];
	char temp[2];
	system("tput clear");
	printf("\n\n\n\t\t WELCOME TO BOND SHELL");
	printf("\n\n\t\tSHELL IMPLEMENTED BY KAVITHA B K AND DEEPTHI G R\n\n");
	while (1) {
		printf("Login  : ");
		scanf("%s", login);
		if (!(strcmp(login, "bond007"))) {
			printf("Password:  ");
			scanf("%s", password);
			if (!(strcmp(password, "kd123"))) {
				fgets(temp, 2, stdin);
				break;

			} else {
				printf("incorrect\n");
				exit(0);
			}
		} else
			printf("incorrect login try bond007\n");
	}

}
