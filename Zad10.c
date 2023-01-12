#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define ERROR -1
struct _Tree;
typedef struct _Tree* Position;
typedef struct _Tree {
	char naziv_grada;
	int broj_stanovnika;
	Position left;
	Position right;
}Tree;

struct _list;
typedef struct _list* Pos;
typedef struct _list {
	int country_name;
	Tree root;
	Pos next;
}list;

int input(char, int);
int readCountries(char, Pos);
int readCities(char);

int main() {

}

int input(char country, int range) {

}

int readCountries(char filename[_MAX_FNAME], Pos p) {
	Pos p;
	char file2;
	
	FILE* fp = NULL;
	fp = fopen(filename, "r");
	
	if (fp == NULL)
	{
		printf("Dear customer, the file %s didn't open! Possible wrong insert!\r\n", filename);
		return ERROR;
	}
	
	while (!feof) {
		sscanf(filename, "%s %s", p->country_name, file2);
		readCities(file2);
	}
	

}

int readCities(char filename2[_MAX_FNAME]) {
	return EXIT_SUCCESS;
}

/*
int cityCmp(City* c1, City c2){
	int result=0;

	result=c1->brStan-c2->brStan;
	if (result==0){
		result=strcmp(c1->naziv, c2->naziv);
	}
	return result;
}
*/
