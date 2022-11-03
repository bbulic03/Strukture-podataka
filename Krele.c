#define _CRT_SECURE_NO_WARNINGS
#define ERROR 1
#define MAX_NAME 256
#define MAX_LINE 1024

#include <stdio.h>
#include <stdlib.h>

struct _Polinom;
typedef struct _Polinom* pos;
typedef struct _Polinom {
	int coef;
	int exp;

	pos* next;
}Polinom;

int Add(pos);
int Multiply(pos);

int main() {
	int izbor;
	Polinom Head = { .coef = 0, .exp = 0 , .next=NULL};
	
	printf("Do you want to add or multiply your polynomes?\nIf you want to add them choose 1\nIf you want to multiply them choose 2\n");
	scanf("%d", &izbor);
	while (1) {
		if (izbor == 1) {
			Add(&Head);
		}
		else if (izbor == 2) {
			Multiply(&Head);
		}
		else {
			printf("Wrong choice.");
			break;
		}
	}
	return EXIT_SUCCESS;
}

int Add(pos p) {
	char filename[MAX_NAME] = { 0 };
	int buffer[MAX_LINE] = { 0 };

	printf("Enter file name: ");
	scanf(" %s", filename);

	FILE* fp = NULL;
	fp = fopen(filename, "r");

	/*fgets(buffer, MAX_LINE,fp);*/
	sscanf(p,"%d %d %n", &coef,&exp,&numofbytes);
	fclose(fp);
	return EXIT_SUCCESS;
}

int Multiply(pos p) {
	
	return EXIT_SUCCESS;
}
