#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE (1024)
#define MAX_NAME (256)
#define ERROR (-1)

struct _Osoba;
typedef struct _Osoba* poz;
typedef struct _Osoba {
	char ime[MAX_NAME];
	char prezime[MAX_NAME];
	int godRod;
	poz next;
}Osoba;

int UnosP(poz);
int ispis(poz);
int UnosK(poz);
int trazi(poz);
int brisi(poz);
int dinIz(poz);
int dinIs(poz);
int brisisve(poz);
int sort(poz);
int write(poz);
int read();

int main()
{
	Osoba Head;
	Head.next = NULL;
	int izbor;

	while (1) {
		printf("\nUnesite:\n 1 za unos na pocetak\n 2 za unos na kraj\n 3 za ispis\n 4 za brisanje\n 5 za trazenje po prezimenu\n 6 za dinamicko dodavanje elementa ispred odabranog prezimena\n 7 za dinamicko dodavanje elementa iza odabranog prezimena\n 9 citanje iz datoteke\n 10 za pisanje u datoteku\n 11 za sortiranje\n 12 za kraj programa\n\n");
		scanf("%d", &izbor);
		if (izbor == 1) {
			UnosP(&Head);
		}
		else if (izbor == 2) {
			UnosK(&Head);
		}
		else if (izbor == 3) {
			ispis(&Head);
		}
		else if (izbor == 4) {
			brisi(&Head);
		}
		else if (izbor == 5) {
			trazi(&Head);
		}
		else if (izbor == 6) {
			dinIs(&Head);
		}
		else if (izbor == 7) {
			dinIz(&Head);
		}
		else if (izbor == 8) {
			printf("\nNOS TI POSRAN!\n");
		}
		else if (izbor == 9) {
			read(&Head);
		}
		else if (izbor == 10) {
			write(&Head);
		}
		else if (izbor == 11) {
			sort(&Head);
		}
		else if (izbor == 12) {
			break;
		}
		else {
			printf("Neispravan unos\n");
		}
	}
	brisisve(&Head);
	return EXIT_SUCCESS;
}

int UnosP(poz p) {
	poz q = NULL;
	q = (poz)malloc(sizeof(Osoba));

	if (q == NULL) {
		printf("Neuspjesna alokacija memorije");
		return ERROR;
	}

	printf("\nUnesi ime osobe: ");
	scanf(" %s", q->ime);
	printf("Unesi prezime osobe: ");
	scanf(" %s", q->prezime);
	printf("Unesi godinu rodenja: ");
	scanf("%d", &q->godRod);
	printf("\n");

	q->next = p->next;
	p->next = q;

	return EXIT_SUCCESS;
}

int UnosK(poz p) {
	poz q = NULL;
	q = (poz)malloc(sizeof(Osoba));
	
	if (q == NULL) {
		printf("\nNeuspjesna alokacija memorije!\n");
		return ERROR;
	}
	
	printf("Unesi ime osobe: ");
	scanf(" %s", q->ime);
	printf("Unesi prezime osobe: ");
	scanf(" %s", q->prezime);
	printf("Unesi godinu rodenja: ");
	scanf("%d", &q->godRod);
	printf("\n");

	while (p->next != NULL) {
		p = p->next;
	}

	q->next = p->next;
	p->next = q;

	/*free(q);*/
	return EXIT_SUCCESS;
}
int ispis(poz p) {
	poz q = NULL;
	q = p->next;
	while (q != NULL) {
		printf("\n%s\n%s\n%d\n", q->ime, q->prezime, q->godRod);
		q = q->next;
	}
	return EXIT_SUCCESS;
}
int brisi(poz p) {
	poz q = NULL;
	char prezime[MAX_NAME] = { 0 };
	q = (poz)malloc(sizeof(Osoba));
	printf("Unesi prezime osobe koju zelite izbrisati: ");
	scanf(" %s", &prezime);
	printf("\n");

	while (p->next != NULL && strcmp(prezime, p->prezime) != 0) {
		q = p;
		p = p->next;
	}
	if (q != NULL && strcmp(prezime, p->prezime) == 0) {
		p = q->next;
		q->next = p->next;
	}
	/*free(q);
	free(prezime);*/
	return EXIT_SUCCESS;
}
int trazi(poz p) {
	char prez[MAX_NAME]={0};
	printf("\nUnesite prezime trazene osobe: ");
	scanf(" %s", &prez);

	while (p != NULL && strcmp(prez, p->prezime) != 0) {
		p = p->next;
	}
	if (p == NULL)
		printf("\nOsoba sa danim prezimenom ne postoji");
	else
		printf("\nAdresa trazene osobe je: %p\n", p);
	return EXIT_SUCCESS;
}

int dinIs(poz p) {
	poz q = NULL;
	poz prev = NULL;
	char prez[MAX_NAME]={0};
	q = (poz)malloc(sizeof(Osoba));
	if (q == NULL) {
		printf("\nNeuspjesna alokacija memorije!\n");
		return ERROR;
	}
	printf("\nUnesite prezime trazene osobe: ");
	scanf(" %s", &prez);

	printf("Unesi ime osobe: ");
	scanf(" %s", q->ime);
	printf("Unesi prezime osobe: ");
	scanf(" %s", q->prezime);
	printf("Unesi godinu rodenja: ");
	scanf("%d", &q->godRod);
	printf("\n");

	prev = p;
	while (p->next != NULL && strcmp(prez, p->prezime) != 0) {
		prev = p;
		p = p->next;
	}
	if (p == NULL)
		printf("\nOsoba sa danim prezimenom ne postoji");
	else {
		q->next = p;
		prev->next = q;
	}
	return EXIT_SUCCESS;
}

int brisisve(poz p) {
	poz q = NULL;
	while (p->next != 0) {
		q = p->next;
		p->next = q->next;
		free(q);
	}
	return EXIT_SUCCESS;
}

int dinIz(poz p) {
	poz q = NULL;
	char prez[MAX_NAME] = { 0 };
	q = (poz)malloc(sizeof(Osoba));
	if (q == NULL) {
		printf("\nNeuspjesna alokacija memorije!\n");
		return ERROR;
	}
	printf("\nUnesite prezime trazene osobe: ");
	scanf(" %s", &prez);

	printf("Unesi ime osobe: ");
	scanf(" %s", q->ime);
	printf("Unesi prezime osobe: ");
	scanf(" %s", q->prezime);
	printf("Unesi godinu rodenja: ");
	scanf("%d", &q->godRod);
	printf("\n");

	while (p->next != NULL && strcmp(prez, p->prezime) != 0) {
		p = p->next;
	}
	if (p == NULL)
		printf("\nOsoba sa danim prezimenom ne postoji");
	else {
		q->next = p->next;
		p->next = q;
	}
	return EXIT_SUCCESS;
}

int sort(poz p) {
	poz q = NULL;
	poz prev = NULL;
	poz temp = NULL;
	poz last = NULL;

	while (p->next != last) {
		prev = p;
		q = p->next;
		while (q->next != last) {
			if (strcmp(q->prezime, q->next->prezime) != 0) {
				temp = q->next;
				prev->next = temp;
				q->next = temp->next;
				temp->next = q;

				q = temp;
			}
			prev = q;
			q = q->next;
		}
		last = q;
	}
	return EXIT_SUCCESS;
}

int write(poz p) {
	FILE* fp = NULL;
	fp = fopen("persons.txt", "w");

	if (fp == NULL) {
		printf("Greška u otvaranju datoteke!\n");
		return ERROR;
	}

	while (p != NULL) {
		fprintf(fp, "%s\t %s\t %d\t\n", p->ime, p->prezime, p->godRod);
		p = p->next;
	}
	fclose(fp);
	return EXIT_SUCCESS;
}
int read() {
	char file[MAX_LINE];
	int a = 0;
	int i=0;
	Osoba Head;
	Head.next = NULL;
	poz p = &Head;
	poz q = NULL;

	printf("Unesite ime datoteke: \n");
	scanf(" %s", &file);

	FILE* fp = NULL;
	fp = fopen(file, "r");

	if (fp == NULL) {
		printf("Greska u otvaranju datoteke!\n");
		return ERROR;
	}
	while (!feof(fp)) {
		if (fgetc(fp) == "\n") {
			a++;
		}
	}
	rewind(fp);
	
	if (a != 0) {
		for (i = 0; i < a; i++) {
			q = (poz)malloc(sizeof(Osoba));
			if (q == NULL) {
				printf("Neuspjesna alokacija memorije!\n");
				return ERROR;
			}
			fscanf(fp, "%s %s %d", q->ime, q->prezime, &q->godRod);
			q->next = p->next;
			p->next = q;
			p = p->next;
		}
	}
	fclose(fp);
	printf(Head.next);
	return EXIT_SUCCESS;
}

