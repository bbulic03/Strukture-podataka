#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME (256)

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
int UnosK (poz);
int trazi(poz);
int brisi(poz );

int main()
{
	Osoba Head;
	Head.next = NULL;
	int izbor;

	while (1){
		printf("Unesite: 1 za unos na pocetak\n 2 za unos na kraj\n 3 za ispis\n 4 za brisanje\n 5 za trazenje po prezimenu\n 6 za kraj programa\n");
		scanf("%d", & izbor);
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
			break;
		}
		else {
			printf("Neispravan unos\n");
		}
	}

	return 0;
}

int UnosP(poz p) {
	poz q = NULL;
	q = (poz)malloc(sizeof(Osoba));

	if (q == NULL) {
		printf("Neuspjesna alokacija memorije");
		return -1;
	}

	printf("Unesi ime osobe: ");
	scanf(" %s", q->ime);
	printf("Unesi prezime osobe: ");
	scanf(" %s", q->prezime);
	printf("Unesi godinu rodenja: ");
	scanf("%d", &q->godRod);
	printf("\n");

	q->next = p->next;
	p->next = q;

	return 0;
}

int UnosK(poz p) {
	while (p->next != NULL) {
		p = p->next;
	}
	poz q = NULL;
	q = (poz)malloc(sizeof(Osoba));

	if (q == NULL) {
		printf("Neuspjesna alokacija memorije");
		return -1;
	}

	printf("Unesi ime osobe: ");
	scanf(" %s", q->ime);
	printf("Unesi prezime osobe: ");
	scanf(" %s", q->prezime);
	printf("Unesi godinu rodenja: ");
	scanf("%d", &q->godRod);
	printf("\n");

	q->next = p->next;
	p->next = q;

	return 0;
}
int ispis(poz p) {
	while (p != NULL) {
		printf("\n%s %s %d", p->ime, p->prezime, p->godRod);
		p = p->next;
	}
	return 0;
}
int brisi(poz p) {
	poz q = NULL;
	char prezime[MAX_NAME];
	printf("Unesi prezime osobe koju zelite izbrisati: ");
	scanf(" %s", &prezime);
	printf("\n");

	while (p->next != NULL && strcmp(prezime,p->prezime)!=0) {
		q = p;
		p = p->next;
	}
	if (q != NULL && strcmp(prezime, p->prezime) == 0) {
		p = q->next;
		q->next = p->next;
	}
	return 0;
}
int trazi(poz p) {
	char prez[MAX_NAME];
	printf("\nUnesite prezime trazene osobe: ");
	scanf(" %s", &prez);

	while (p != NULL && strcmp(prez, p->prezime) != 0) {
		p = p->next;
	}
	if (p == NULL)
		printf("\nOsoba sa danim prezimenom ne postoji");
	else
		printf("\nAdresa trazene osobe je: %p\n", p);
	return 0;
}
