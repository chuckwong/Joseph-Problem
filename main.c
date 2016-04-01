/*
    author = chuck
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 3
#define K 0

struct node {
    int number;
    struct node *next;
};

void InitNodes(struct node **head);
void DisplayNodes(struct node *head);
void DeleteNode(struct node **head, struct node *d);
void SolveByRecursion(struct node **head, int m);

// main
int main(int argc, char **argv)
{
    struct node *head;

    InitNodes(&head);
    // if (head == NULL)
    //     printf("NULL\n")
    DisplayNodes(head);
    // DeleteNode(&head);
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->number = 5;
    DeleteNode(&head, p);

    DisplayNodes(head);
    // SolveByRecursion(&head, M);

    return 0;
}

// InitNodes
void InitNodes(struct node **head)
{
    *head = (struct node *)malloc(sizeof(struct node));
    struct node *p = *head;
    p->number = 0;
    int i = 1;
    while (i < N) {
        p->next = (struct node *)malloc(sizeof(struct node));
        p->next->number = i;
        if (i == N - 1) // must assign the next ptr to HEAD for the last node
            p->next->next = *head;
        p = p->next;
        i++;
    }
}

// DisplayNodes
void DisplayNodes(struct node *head)
{
    struct node *p = head;
    int i = 0;
    while (p && i < N) {
        printf("%d   ", p->number);
        p = p->next;
        i++;
    }
    printf("\n");
}

// DeleteNode
void DeleteNode(struct node **head, struct node *d)
{
    struct node *p = *head;
    while (p && p->next && (p->next->number != d->number)) {
        p = p->next;
    }
    // delete p->next
    printf("Delete %d\n", p->next->number);
    struct node *tmp = p->next;
    p->next = tmp->next;
    free(tmp);
}

// SolveByRecursion
void SolveByRecursion(struct node **head, int m)
{
    struct node *p = *head;
}
