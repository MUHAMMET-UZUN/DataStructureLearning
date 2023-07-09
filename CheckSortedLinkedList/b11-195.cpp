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

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > Count(p))
        return;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;

        t->next = p->next;
        p->next = t;
    }
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int i;
    int x = -1;

    if (index < 1 || index > Count(p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int isSorted(struct Node *p)
{
    int i, x = -32768;

    while (p)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    Create(A, 5);

    printf("%d", isSorted(first));
    
    printf("\n\n");
    return 0;
}
