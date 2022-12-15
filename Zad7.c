#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50

struct dir;
typedef struct dir* pos;
struct dir
{
    char name[N];
    pos sibling;
    pos child;
};

struct stack;
typedef struct stack* stpos;
struct stack
{
    pos data;
    stpos next;
};

pos AddDir(pos current, pos p);
void print(pos p);
pos find(pos p, char* dirName, char* curr, int n, stpos queue);
void delete(pos p);
stpos push(stpos queue, pos p);
pos pop(stpos queue);
stpos popStack(stpos queue);


int main(void)
{
    struct dir C;
    struct stack head = {.data = &C, .next = NULL};
    char command[10], dirName[N], curr[100];
    pos q, current = &C;
    stpos currentStack = &head, h;
    int n = 0, i;

    strcpy(curr, "");

    strcpy(C.name, "C:");
    C.sibling = NULL;
    C.child = NULL;


    while(1)
    {
        printf("%s%s", C.name, curr);
        scanf("%s", command);
        if(strcmp(command, "md") == 0)
        {
            scanf("%s", dirName);
            q = (pos)malloc(sizeof(struct dir));
            strcpy(q->name, dirName);
            q->sibling = NULL;
            q->child = NULL;
            current->child = AddDir(current->child, q);
        }
        else if(strcmp(command, "cd") == 0)
        {
            scanf("%s", dirName);
            n = strlen(curr);
            current = find(current, dirName, curr, n, currentStack);
            currentStack = push(currentStack, current);
        }
        else if(strcmp(command, "cd..") == 0)
        {
            //printf("*%s*", currentStack->data->name);
            if(current != &C)
            {
                currentStack = popStack(currentStack);
                current = pop(currentStack);
            }
            for(i = strlen(curr) - 2; i >= 0; i--)
            {
                if(curr[i] == ':')
                    break;
                curr[i] = '\0';
            }
        }
        else if(strcmp(command, "dir") == 0)
        {
            print(current->child);
        }
        else if(strcmp(command, "exit") == 0)
        {
            delete(&C);
            return EXIT_SUCCESS;
        }
        else
        {
            printf("Command not found!\n");
        }
    }

    return EXIT_SUCCESS;
}

pos AddDir(pos current, pos p)
{
    if(current == NULL)
        return p;
    if(strcmp(current->name, p->name) > 0)
    {
        p->sibling = current;
        return p;
    }
    else if(strcmp(current->name, p->name) < 0)
        current->sibling = AddDir(current->sibling, p);
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
        printf(" %s\n", p->name);
        p = p->sibling;
    }
}

pos find(pos p, char* dirName, char* curr, int n, stpos queue)
{
    int i;
    pos c = p;
    p = p->child;
    while(p != NULL)
    {
        if(strcmp(p->name, dirName) == 0)
        {
            for(i = 0; i < strlen(dirName); i++)
                curr[n + i] = dirName[i];
            curr[n + i] = ':';
            curr[n + 1 + i] = '\0';
            queue = push(queue, p);
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

void delete(pos p)
{
    if(!p)
        return;
    delete(p->sibling);
    delete(p->child);
    free(p);
}

stpos push(stpos queue, pos p)
{
    stpos q;
    q = (stpos)malloc(sizeof(struct stack));
    q->data = p;
    q->next = queue;
    return q;
}

pos pop(stpos queue)
{
    pos q;
    q = queue->data;
    return q;
}

stpos popStack(stpos queue)
{
    stpos q = queue->next;
    return q;
}
