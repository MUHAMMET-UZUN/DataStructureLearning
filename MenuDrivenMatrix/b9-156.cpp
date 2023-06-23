#include <iostream>

int main()
{

    int *A, n, ch, x, i, j;

    printf("Enter dimension: ");
    scanf("%d", &n);

    // A = (int *)malloc(n * sizeof(int));
    A = new int[n];

    do
    {
        printf("1- Create\n2- Get\n3- Set\n4- Display");
        printf("\n\n");
        scanf("%d", ch);

        switch (ch)
        {
        case 1:
            for (i = 1; i <= n; i++)
                scanf("%d", &A[i - 1]);
            break;
        case 2:
            printf("Enter indices");
            scanf("%d%d", &i, &j);
            if (i == j)
                printf("%d ", A[i - 1]);
            else
                printf("0 ");
            break;
        case 3:
            printf("Enter row column an element: ");
            scanf("%d%d%d", &i, &j, &x);

            if (i == j)
                A[i - 1] = x;
            break;
        case 4:
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                {
                    if (i == j)
                        printf("%d ", A[i - 1]);
                    else
                        printf("0 ");
                }
        default:
            break;
        }
    } while (ch < 5 && ch > 0);

    return 0;
}