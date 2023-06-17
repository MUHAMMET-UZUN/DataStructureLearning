#include <iostream>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void perm(char s[], int k)
{
    static int A[10] = {0};
    static char Res[10];
    int i;

    if (s[k] == '\0')
    {
        Res[k] = '\0';
        printf(Res);
        printf("\n");
    }

    for (i = 0; s[i] != '\0'; i++)
    {
        if (A[i] == 0)
        {
            Res[k] = s[i];
            A[i] = 1;
            perm(s, k + 1);
            A[i] = 0;
        }
    }
}
void perm(char S[], int l, int h)
{
    int i;

    if (l == h)
    {
        printf(S);
    }
    else
    {
        for (i = l; i <= h; i++)
        {
            swap(&S[l], &S[i]);
            perm(S, l + 1, h);
            swap(&S[l], &S[i]);
        }
    }
}

int main()
{
    char s[] = {"ABCD"};
    perm(s, 0);
    return 0;
}