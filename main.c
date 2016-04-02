/*
 author = chuck
 */

#include <stdio.h>
#include <stdlib.h>

#define N 6
#define M 3
#define K 2

struct node {
    int number;
    struct node *next;
    int flag; // flag = 0 means deleted
};

void InitNodes(struct node **head);
void DisplayNodes(struct node *head);
void DeleteNode(struct node **head, int number);
void Solve(struct node **head, int m, int k);
void SolveByRecursion(struct node **head, int m);

// main
int main(int argc, char **argv)
{
    struct node *head;
    
    InitNodes(&head);
    DisplayNodes(head);
    // printf("Length = %d\n", GetLength(head));
    // DisplayNodes(head);
    
    Solve(&head, M, K);
    printf("---------END---------\n");
    return 0;
}

// InitNodes
void InitNodes(struct node **head)
{
    *head = (struct node *)malloc(sizeof(struct node));
    struct node *p = *head;
    p->number = N; // length
    p->flag = 1;
    int i = 1;
    while (i < N + 1) {
        p->next = (struct node *)malloc(sizeof(struct node));
        p->next->number = i;
        p->next->flag = 1;
        if (i == N) // must assign the next ptr to HEAD for the last node
            p->next->next = (*head)->next;
        p = p->next;
        i++;
    }
}

// DisplayNodes
void DisplayNodes(struct node *head)
{
    struct node *p = head->next;
    int i = 0;
    while (p && i < (head->number)) {
        if (p->flag == 1) {
            printf("%d   ", p->number);
            i++;
        }
        p = p->next;
    }
    printf("\n");
}

// DeleteNode
void DeleteNode(struct node **head, int number)
{
    struct node *p = (*head)->next;
    while (p && p->next && (p->next->number != number)) {
        p = p->next;
    }
    // delete p->next
    if (p && p->next && (p->next->number == number)) {
        p->next->flag = 0;
        printf("\nDelete ------------ %d\n", p->next->number);
        (*head)->number--;
        DisplayNodes(*head);
    }
}

// Solve
void Solve(struct node **head, int m, int k)
{
    // int j = 0;
    struct node *p = (*head)->next;
    while ((*head)->number > 0) {
        int i = 0;
        while (p && (i < M - 1 || p->flag == 0)) {
            if (p->flag == 0) {
                p = p->next;
                continue;
            } else {
                i++;
                p = p->next;
            }
        }
        // k = 0;
        // j = m;
        DeleteNode(head, p->number);
        p = p->next;
    }
}

// SolveByRecursion
void SolveByRecursion(struct node **head, int m)
{
    if (*head == NULL) {
        printf("结束\n");
    }
    struct node *p = *head;
    int i = 0;
    while (p && i < m - 1) {
        p = p->next;
        i++;
    }
    DeleteNode(head, p->number);
    SolveByRecursion(&p, M);
}








