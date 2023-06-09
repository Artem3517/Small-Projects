#ifndef INCLUDE_H
#define INCLUDE_H
#define BUFSIZE 256

enum exit_code{ERROR = 0, SUCCESS};

typedef struct {
    const char* login;
    const char* pass;
    int some_data;
} Account;

int start();
int getlog();
int getpas();
int check();
void pulldata();

#endif //INCLUDE_H
