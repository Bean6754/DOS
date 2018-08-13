#include <stdio.h>

int intro()
{
	char name[26];
        FILE *fp = fopen("USER.TXT", "r");

        if (fp == NULL)
	{
		FILE *fp = fopen("USER.TXT", "w");
		printf("What is your name? ");
		scanf("%s", name);
		fprintf(fp, "%s", name);
		fclose(fp);
	}
	else if (fp != NULL)
	{
		fseek(fp, 0, SEEK_SET);
		fgets(name, 100, fp);
		printf("Welcome:\033[0;31m %s\033[0m.\n", name);
		fclose(fp);
	}
	else
	{
        	printf("Error, can't open 'USER.TXT' for writing/reading.\n");
                fclose(fp);
		return 1;
	}
}

int main (void)
{
        intro();

	return 0;
}
