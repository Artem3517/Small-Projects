#include "auth.h"
#include "new_user.h"
#include <stdio.h>
#include <unistd.h>
#define BUFSIZE 256

int choice = 0;

int main(int argc, char** argv) {
	choice = start();
	if (choice == 3)
		return 0;
	if (choice == 2)
		new_log();
		new_pas();
	if (getlog() == SUCCESS) {
		if (getpas() == SUCCESS) {
			printf("Loading");
			int i = 0;
			while (i < 20) {
				putchar('.');
				usleep(100);
				i++;
			}
			putchar('\n');
			puts("Congratulations, you have entered the system!");
		}
	} else {
		return 1;
	}
	pulldata();
	return 0;
}