#include "new_user.h"
#include <stdio.h>

static char temp[BUFSIZE];
static char login[BUFSIZE];

int check() {
    FILE* fp = fopen("users.txt", "r");
	char c = 0;
	while (fscanf(fp, "%c", &c) != EOF) {
		login[0] = '\0';
		int i = 0;
		while (c != ' ') {
			login[i] = c;
			fscanf(fp, "%c", &c);
			i++;
		}
		if(strcmp(login, temp) == 0) {
			return ERROR;
		}
		while (c != '\n') {
			fscanf(fp, "%c", &c);
		}
	}
	fclose(fp);
	return SUCCESS;
}

void newlog() {
	while (check() == ERROR) {
		printf("Enter your unique login: ");
		temp[0] = '\0';
		scanf("%s", temp);
	}
}

int newpas() {
    return SUCCESS;
}