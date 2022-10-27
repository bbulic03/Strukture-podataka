#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE (1024)
#define MAX_NAME (256)
#define MAX_FILE_NAME (256)

struct _student;
typedef struct _student {
	char ime[MAX_NAME];
	char prezime[MAX_NAME];
	double bodovi;
}student;

int countstudents(FILE*);

int maxbrbod(FILE*);

int main(void) {
	FILE* fp = NULL;
	student* ps = NULL;
	int i = 0;
	double relativni;
	char filename[MAX_FILE_NAME] = { 0 };

	printf("Insert filename: ");
	scanf(" %s", filename);

	fp = fopen(filename, "r");
	
	ps = (student*)calloc(countstudents(fp), sizeof(student));
	if (ps == NULL) {
		// riješi problem
	}
	rewind(fp);

	for (i = 0; i < countstudents(fp); i++)
	{
		fscanf(fp, "%s %s %lf\n", ps[i].ime, ps[i].prezime, &ps[i].bodovi);
		relativni = ps[i].bodovi / maxbrbod(fp) * 100;
		printf("Ime: %s\t Prezime: %s\t Bodovi: %lf\t Relativni bodovi: %lf\n", ps[i].ime, ps[i].prezime, &ps[i].bodovi, relativni);
	}

	printf("Broj studenata u datoteci je %d", countstudents(fp));
	fclose(fp);

	return 0;
}

int countstudents(FILE* fp) {
	int count = 0;
	char buffer[MAX_LINE] = { 0 };

	while (!feof(fp)) {
		fgets(buffer, MAX_LINE, fp);
		if (strcmp("\n", buffer) != 0) {
			count++;
		}
	}
	return count;
}

int maxbrbod(FILE* fp, student* ps, int count) {
	int max = 0;
	int i;
	count = countstudents(fp);

	for (i = 0; i < count; i++) {
		if (&ps[i].bodovi > max) {
			max = &ps[i].bodovi;
		}
	}
	return max;
}
