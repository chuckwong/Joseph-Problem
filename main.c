/*
    author = chuck
*/

#include <stdio.h>
#include <stdlib.h>

#define N 30
#define M 9
#define K 0

struct node {
    int number;
    struct node *next;
};

void InitNodes(struct node *first);
void DisplayNodes(struct node *first);

// main
int main(int argc, char **argv)
{
    struct node *first;

    InitNodes(first);
    DisplayNodes(first);

    return 0;
}

// InitNodes
void InitNodes(struct node *first)
{
    // first = (struct node *)malloc(sizeof(struct node));
    struct node *p;
    p = first;
    int i = 0;
    while (i < N) {
        p = (struct node *)malloc(sizeof(struct node));
        p->number = i;
        p = p->next;
        i++;
    }
}

// DisplayNodes
void DisplayNodes(struct node *first)
{
    struct node *p;
    p = first;
    while (p) {
        printf("%d  ", p->number);
        p = p->next;
    }
    printf("\n");
}


