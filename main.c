/*
 author = chuck
 */

#include <stdio.h>
#include <stdlib.h>

int N = 6; // default 6
int K = 0; // default 0

#define M 3

struct node {
    int number;
    int password;
    struct node *next;
    int flag; // flag = 0 means deleted
};

void InitNodes(struct node **head);
void DisplayNodes(struct node *head);
void DeleteNode(struct node **head, int number);
void Solve(struct node **head, int m);
void SolveByRecursion(struct node **head, struct node *lp, int m);
void Restore(struct node **head);
void InputPassword(struct node **head);

// main
int main(int argc, char **argv)
{
    struct node *head;
    
    // Input
    printf("约瑟夫环程序 - 王俊皓 - 2014101027\n\n");
    printf("请输入总人数N: ");
    scanf("%d", &N);
    printf("请输入初始值K: ");
    scanf("%d", &K);
    
    // Init
    InitNodes(&head);
    
    // Password
    InputPassword(&head);
    
    // Print Origin
    printf("\n");
    printf("原始: ");
    DisplayNodes(head);
    
    // Result
    printf("循环: ");
    Solve(&head, K);
    
    // Restore
    Restore(&head);
    
    // Result
    printf("递归: ");
    SolveByRecursion(&head, NULL, M);
    
    // End
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
        printf("%d   ", p->next->number);
        (*head)->number--;
//        DisplayNodes(*head);
    }
}

// Solve
void Solve(struct node **head, int m)
{
    int count = m;
    struct node *p = (*head)->next;
    while ((*head)->number > 0) {
        int i = 0;
        while (p && (i < count - 1 || p->flag == 0)) {
            if (p->flag == 0) {
                p = p->next;
                continue;
            } else {
                i++;
                p = p->next;
            }
        }
        DeleteNode(head, p->number);
        count = p->password;
        p = p->next;
    }
    printf("\n");
}

// SolveByRecursion
void SolveByRecursion(struct node **head, struct node *lp, int m)
{
    if ((*head)->number == 0) {
        printf("\n");
        return;
    }
    struct node *p = lp ? lp : (*head)->next;
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
    DeleteNode(head, p->number);
    SolveByRecursion(head, p->next, p->password);
}

// Restore
void Restore(struct node **head)
{
    struct node *p = (*head)->next;
    int i = 0;
    while (i < N) {
        p->flag = 1;
        p = p->next;
        i++;
    }
    (*head)->number = N;
}

// InputPassword
void InputPassword(struct node **head)
{
    struct node *p = (*head)->next;
    int i = 0;
    while (i < N) {
        printf("请输入密码(编号%d): ", i + 1);
        scanf("%d", &p->password);
        p = p->next;
        i++;
    }
}







