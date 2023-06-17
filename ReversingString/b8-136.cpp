#include <iostream>

int main()
{

    char A[] = "Python";
    char t;
    int i, j;

    // dizi uzunluğunu buluyoruz
    for (j = 0; A[j] != '\0'; j++)
    {
    }
    j--; // son eleman bitirme karakteri olduğundan onun sonda kalması gerek, o yüzden bir adım geriden başlıyoruz

    // burda i ve j ile ters çevirme işlemini gerçekleştiriyoruz
    for (i = 0; i < j; i++, j--)
    {
        t = A[j];
        A[j] = A[i];
        A[i] = t;
    }

    printf("%s", A);

    return 0;
}