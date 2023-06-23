#include <iostream>

using namespace std;

class Element
{
public:
    int i, j, x;
};

class Sparse
{
private:
    int m, n, num;
    Element *ele;

public:
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;

        ele = new Element[this->num];
    }
    ~Sparse()
    {
        delete[] ele;
    }

    Sparse operator+(Sparse &s);

    friend istream &operator>>(istream &is, Sparse &s);
    friend ostream &operator<<(ostream &os, Sparse &s);
};

Sparse Sparse::operator+(Sparse &s)
{
    int i, j, k;
    if (m != s.m || n != s.n)
        return NULL;

    Sparse *sum = new Sparse(m, n, num + s.num);

    i = j = k = 0;

    while (i < num && j < s.num)
    {
        if (ele[i].i < s.ele[j].i)
            sum->ele[k++] = ele[i++];
        else if (ele[i].i > s.ele[j].i)
            sum->ele[k++] = ele[j++];
        else
        {
            if (ele[i].j < s.ele[j].j)
                sum->ele[k++] = ele[i++];
            else if (ele[i].j > s.ele[j].j)
                sum->ele[k++] = ele[j++];
            else
            {
                sum->ele[k] = ele[i];
                sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
            }
        }
    }
    for (; i < num; i++)
        sum->ele[k++] = ele[i];
    for (; j < num; j++)
        sum->ele[k++] = ele[j];
    sum->num = k;

    return *sum;
}

istream &operator>>(istream &is, Sparse &s)
{
    int i;
    cout << "Enter non-zero elements (row - column - value)\n";
    for (i = 0; i < s.num; i++)
        cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
}
ostream &operator<<(ostream &os, Sparse &s)
{
    int i, j, k = 0;

    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (s.ele[k].i == i && s.ele[k].j == j)
                cout << s.ele[k++].x << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    Sparse s1(5, 5, 5);
    Sparse s2(5, 5, 5);

    cout << s1;
    cout << s2;

    Sparse sum = s1 + s2;

    cout << "First Matrix" << endl
         << s1;
    cout << "Second Matrix" << endl
         << s2;
    cout << "Sum Matrix" << endl
         << sum;

    return 0;
}