#include <iostream>

class LowerTri
{
private:
    int n;
    int *A;

public:
    LowerTri() // n for dimension
    {
        n = 2;
        A = new int[n * (n + 1) / 2];
    }
    LowerTri(int n) // n for dimension
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() { return n; }
    ~LowerTri();
};

void LowerTri::Set(int i, int j, int x)
{
    if (i >= j)
        A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] = x; // column major
                                                            // A[i * (i - 1) / 2 + j - 1] = x; // row major
}

int LowerTri::Get(int i, int j)
{
    if (i >= j)
        return A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j]; // column major
    // return A[i * (i - 1) / 2 + j - 1]; // row major
    else
        return 0;
}

void LowerTri::Display()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i >= j)
                std::cout << A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] << " "; // column major
            // std::cout << A[i * (i - 1) / 2 + j - 1] << " "; // row major
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
}

LowerTri::~LowerTri()
{
    delete[] A;
}

int main()
{

    int d;
    std::cout << "Enter Dimension:";
    std::cin >> d;

    LowerTri lm(d);

    int x;
    std::cout << "Enter all elements: ";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            std::cin >> x;
            lm.Set(i, j, x);
        }
    }

    lm.Display();

    return 0;
}