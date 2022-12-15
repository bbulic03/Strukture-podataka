#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50

struct dir;
typedef struct dir* pos;
struct dir
{
    char ime[N];
    pos sibling;
    pos child;
};

struct stog;
typedef struct stog* stpos;
struct stog
{
    pos data;
    stpos next;
};

pos dodajDir(pos current, pos p);
void print(pos p);
pos trazi(pos p, char* dirIme, char* trenutni, int n, stpos red);
void brisi(pos p);
stpos push(stpos red, pos p);
pos pop(stpos red);
stpos popStog(stpos red);


int main(void)
{
    struct dir C;
    struct stog head = {.data = &C, .next = NULL};
    char naredba[10], dirIme[N], trenutni[100];
    pos q, current = &C;
    stpos currentStog = &head, h;
    int n = 0, i;

    strcpy(trenutni, "");

    strcpy(C.ime, "C:");
    C.sibling = NULL;
    C.child = NULL;


    while(1)
    {
        printf("%s%s", C.ime, trenutni);
        scanf("%s", naredba);
        if(strcmp(naredba, "md") == 0)
        {
            scanf("%s", dirIme);
            q = (pos)malloc(sizeof(struct dir));
            strcpy(q->ime, dirIme);
            q->sibling = NULL;
            q->child = NULL;
            current->child = dodajDir(current->child, q);
        }
        else if(strcmp(naredba, "cd") == 0)
        {
            scanf("%s", dirIme);
            n = strlen(trenutni);
            current = trazi(current, dirIme, trenutni, n, currentStog);
            currentStog = push(currentStog, current);
        }
        else if(strcmp(naredba, "cd..") == 0)
        {
            //printf("*%s*", currentStog->data->ime);
            if(current != &C)
            {
                currentStog = popStog(currentStog);
                current = pop(currentStog);
            }
            for(i = strlen(trenutni) - 2; i >= 0; i--)
            {
                if(trenutni[i] == ':')
                    break;
                trenutni[i] = '\0';
            }
        }
        else if(strcmp(naredba, "dir") == 0)
        {
            print(current->child);
        }
        else if(strcmp(naredba, "exit") == 0)
        {
            brisi(&C);
            return EXIT_SUCCESS;
        }
        else
        {
            printf("Command not found!\n");
        }
    }

    return EXIT_SUCCESS;
}

pos dodajDir(pos current, pos p)
{
    if(current == NULL)
        return p;
    if(strcmp(current->ime, p->ime) > 0)
    {
        p->sibling = current;
        return p;
    }
    else if(strcmp(current->ime, p->ime) < 0)
        current->sibling = dodajDir(current->sibling, p);
    else
    {
        printf("That directory already exists\n");
        free(p);
    }
    return current;
}

void print(pos p)
{
    if(p == NULL)
        printf("There is no directory\n");
    while(p != NULL)
    {
        printf(" %s\n", p->ime);
        p = p->sibling;
    }
}

pos trazi(pos p, char* dirIme, char* trenutni, int n, stpos red)
{
    int i;
    pos c = p;
    p = p->child;
    while(p != NULL)
    {
        if(strcmp(p->ime, dirIme) == 0)
        {
            for(i = 0; i < strlen(dirIme); i++)
                trenutni[n + i] = dirIme[i];
            trenutni[n + i] = ':';
            trenutni[n + 1 + i] = '\0';
            red = push(red, p);
            return p;
        }
        p = p->sibling;
    }
    if(p == NULL)
    {
        printf("Directory not found\n");
        return c;
    }
    return c;
}

void brisi(pos p)
{
    if(!p)
        return;
    brisi(p->sibling);
    brisi(p->child);
    free(p);
}

stpos push(stpos red, pos p)
{
    stpos q;
    q = (stpos)malloc(sizeof(struct stog));
    q->data = p;
    q->next = red;
    return q;
}

pos pop(stpos red)
{
    pos q;
    q = red->data;
    return q;
}

stpos popStog(stpos red)
{
    stpos q = red->next;
    return q;
}
