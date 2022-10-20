#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LINE (1024)
#define MAX_FILE_NAME (256)

typedef struct{
	char ime[MAX_LINE];
	char prezime[MAX_LINE];
	double bodovi;
}student;

int main(void) {
	FILE* fp = NULL;
	int count = 0, i,maxbrbod=50;
	char buffer[MAX_LINE] = { 0 };
	double relativni;
	char filename[MAX_FILE_NAME] = { 0 };

	printf("Insert filename: ");
	scanf(" %s", filename);
	student* ps = NULL;

	fp = fopen(filename, "r");
	while (!feof(fp)) {
		if (strcmp("\n", buffer) != 0) {
			count++;
		}
	}
	ps = (student*)calloc((count), sizeof(student));
	rewind(fp);
	for ( i= 0; i < count; i++)
	{
		fscanf(fp, "%s %s %lf\n", (*(ps + i)).ime, (*(ps + i)).prezime, &(*(ps + i).bodovi));
		relativni = ps[i].bodovi / maxbrbod*100;
		printf("Ime: %s\t Prezime: %s\t Bodovi: %lf\t Relativni bodovi: %lf\n", (*(ps + i)).ime, (*(ps + i)).prezime, &(*(ps + i).bodovi), relativni);
	}
	printf("Broj studenata u datoteci je %d", count);
	fclose(fp);
	return 0;
}
