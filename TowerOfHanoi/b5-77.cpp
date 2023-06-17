#include <stdio.h>

void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        printf("(%d,%d)\n", A, C);
        TOH(n - 1, B, A, C);
    }
}
void foo(int n, int sum)

{

    int k = 0, j = 0;

    if (n == 0)
        return;

    k = n % 10;

    j = n / 10;

    sum = sum + k;

    foo(j, sum);

    printf("% d", k);
}

int f(int n)

{

    static int i = 1;

    if (n >= 5)
        return n;

    n = n + i;

    i++;

    return f(n);
}

int fun(int n)

{

    int x = 1, k;

    if (n == 1)
        return x;

    for (k = 1; k < n; ++k)

        x = x + fun(k) * fun(n - k);

    return x;
}

int main()
{
    int sum = 0;

    TOH(4, 1, 2, 3);
    printf("%d", f(1));
    foo(2048, sum);
    printf("%d", sum);
    printf("fun %d",fun(5));
    return 0;
}