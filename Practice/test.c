#include "test.h"

int main() {
	float x = .75; 						// x = 0.75
	float y = 10.; 						// y = 10.0
	int z = 6;
	int w = 2;
	printf("6 / 2 = %d\n", z / w); 					 // int / int = int // int
	printf("2 / 6 = %d\n", w / z);
	printf("6 / 0.75 = %.2f\n", z / x); 			 // int / float or float / int = float
	printf("10.0 / 2 = %.2f\n", y / w);
	printf("2 / 6 = %d(%d)\n", w / z, w % z);		 // int % int = the remainder of the division
	t = SQUARE(z);									 // example of usage macros and external value
	printf("6 * 6 = %d(macros)\n", t);
	printf("\n"); 

	int day = MON;
	day > 5 ? printf("Weekend!\n") : printf("Weekday(\n"); // 1 ? 2 : 3; = if (1) 2 else 3
	day = TUE;
	char string[] = "Today is "; 						   // '\0' in the end of string
	printf("\n%s\n\n", string+2);
	output(day, string);
	
	int a = -5;
	printf("%d\n\n", ~a << 1); 							   // a << n = a * 2^n
	
	a = 11;
	while (a) {											   // a = 0 - false expression, other - true
		a--; 
		if (a == 5)
			continue;
		printf("%d ", a);
	}
	printf("NO 5%c", '\n');
	
	User Player1, Player2;
	User* ptr = &Player1;
	Player1.id = 1;
	Player1.name = "Tom";
	Player1.ptr = &Player2;
	Player1.ptr->id = 2; 						// Player2.id = 2
	User Listarray[2] = {*ptr, Player2};
	User Player3 = Listarray[0]; 				// copied Player1 into Player3
	return 0;
}

void output(int day, char string[]) {			// char a[] = char* a
	for (int i = 0; i < strlen(string); i++) {
		printf("%c", string[i]);
	}
	switch (day) {
		case MON:	printf("Monday\n");
					break;
		case TUE:	printf("Tuesday\n");
					break;
		case 3:	printf("Wednsday\n");
					break;
		case THU:	printf("Thursday\n");
					break;
		case FRI:	printf("Friday\n");
					break;
		case SAT:	printf("Saturday\n");
					break;			
		case SUN:	printf("Sunday\n");
					break;
		default:	printf("Error!\n");
					break;
	}
	putchar('\n');
}
