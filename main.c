/*
    author = chuck
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 9
#define K 0

struct node {
    int number;
    struct node *next;
};

void InitNodes(struct node **first);
void DisplayNodes(struct node *first);

// main
int main(int argc, char **argv)
{
    struct node *first;

    InitNodes(&first);
    // if (first == NULL)
    //     printf("NULL\n")
    DisplayNodes(first);

    return 0;
}

// InitNodes
void InitNodes(struct node **first)
{
    *first = (struct node *)malloc(sizeof(struct node));
    struct node *p = *first;
    p->number = 0;
    int i = 1;
    while (i < N) {
        p->next = (struct node *)malloc(sizeof(struct node));
        p->next->number = i;
        if (i == N - 1) // must assign the next ptr to NULL for the last node
            p->next->next = NULL;
        p = p->next;
        i++;
    }
}

// DisplayNodes
void DisplayNodes(struct node *first)
{
    struct node *p = first;
    while (p) {
        printf("%d   ", p->number);
        p = p->next;
    }
    printf("\n");
}


