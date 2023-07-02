#include <iostream>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    printf("\n");
    while (p != NULL)
    {
        printf("data: %d\n", p->data);
        p = p->next;
    }
}

void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("data: %d\n", p->data);
        RDisplay(p->next);
    }
}

int Count(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int RCount(struct Node *p)
{
    if (p)
        return 1 + RCount(p->next);
    else
        return 0;
}

int Sum(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int RSum(struct Node *p)
{
    if (p)
        return p->data + RSum(p->next);
    else
        return 0;
}

int Max(struct Node *p)
{
    int maxNum = -32768;
    while (p)
    {
        if (maxNum < p->data)
            maxNum = p->data;
        p = p->next;
    }
    return maxNum;
}

int RMax(struct Node *p)
{
    int x = 0;

    if (p == 0)
        return INT32_MIN;
    x = RMax(p->next);

    if (x > p->data)
        return x;
    else
        return p->data;
}

Node *LSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;

            return (p);
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

Node *RSearch(struct Node *p, int key)
{
    if (!p)
        return NULL;
    if (key == p->data)
        return p;
    return RSearch(p->next, key);
}

int main()
{
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    Create(A, 8);

    temp = LSearch(first, 25);
    temp = LSearch(first, 8);
    if (temp)
        printf("Key found! -> %d", temp->data);
    else
        printf("Key didn't find!");

    Display(first);

    return 0;
}