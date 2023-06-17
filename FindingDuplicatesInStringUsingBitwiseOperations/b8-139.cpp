#include <iostream>

int main()
{
    char A[] = "finding";
    int i;
    long int H = 0, X = 0;

    for (i = 0; A[i] != '\0'; i++)
    {
        X = 1;
        X = X << (A[i] - 97);
        
        if ((X & H) > 0)
        {
            printf("%c is Duplicate\n", A[i]);
        }
        else
        {
            H = X | H;
        }
    }

    return 0;
}