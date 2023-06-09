#include "auth.h"
#include <stdio.h>
#include <string.h>

extern int choice;
static char login[BUFSIZE];
static char pass[BUFSIZE];
static char temp[BUFSIZE];

int start() {
	for (int i = 0; i < 30; i++) {
		putchar('#');
	}
	putchar('\n');
	puts("Welcome to Beta-Bank!\nAuthorization - 1\nRegistration - 2\nExit - 3");
	printf("Choose the action: ");
	scanf("%d", &choice);
	return choice;
}

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
			pass[0] = '\0';
			int j = 0;
			while(c != '\n') {
				fscanf(fp, "%c", &c);
				pass[j] = c;
				j++;
			}
			pass[j-1] = '\0';
			fclose(fp);
			return SUCCESS;
		}
		while (c != '\n') {
			fscanf(fp, "%c", &c);
		}
	}
	fclose(fp);
	return ERROR;
}

int getlog() {
	int count = 0;
	while (check() == ERROR && count < 5) {
		printf("Enter your login: ");
		temp[0] = '\0';
		scanf("%s", temp);
		count++;
	}
	if (count == 5)
		return ERROR;
	return SUCCESS;
}

int getpas() {
	int count = 0;
	while (strcmp(pass, temp) != 0 && count < 5) {
		printf("Enter your password (%d try, %d left): ", count+1, 5-count);
		temp[0] = '\0';
		scanf("%s", temp);
		count++;
	}
	if (count == 5)
		return ERROR;
	return SUCCESS;
}

void pulldata() {
	FILE* fp = fopen(login, "r");
	Account Acc;
	Acc.login = login;
	Acc.pass = pass;
	/*char c = 0;
	int i = 0;
	while (c != ' ') {
		fscanf(fp, "%c", &c);
		temp[i] = c;
		i++;
	}
	temp[i-1] = '\0'; */
	Acc.some_data = 1;
	fclose(fp);
}