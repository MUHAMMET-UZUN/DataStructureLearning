#include <stdio.h>

int pow(int m, int n)
{
    if (n == 0)
        return 1;
    else
        return pow(m, n - 1) * m;
}

int fastPow(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return fastPow(m * m, n / 2);
    else
        return m * fastPow(m * m, (n - 1) / 2);
}

int main()
{
    printf("%d\n", pow(2, 5));
    printf("%d\n", fastPow(3, 5));
    return 0;
}