#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX_LINE 1024
#define ERROR (-1)

struct _Stog;
typedef struct _Stog* position;
typedef struct _Stog {
	int El;
	position next;
}Stog;

int push(int El, position S);
int pop(position S);

int main() {
	Stog Head;

	return EXIT_SUCCESS;
}

int push(int El, position S) {


	return EXIT_SUCCESS;
}

int pop(position S) {
	
	return EXIT_SUCCESS;
}
