#ifndef WIELOM_CPP
#include "wielom.hpp"
#include <iostream>

using namespace std;

wielom::wielom(int st, double wsp)
{
    if (st < 0)
    {
        throw invalid_argument("Niepoprawny stopień wielomianu");
    }
    else
    {
        n = st;
        a = new double[n + 1]{};

        a[n] = wsp;
    }
}

wielom::wielom(int st, const double wsp[])
{
    if (st < 0)
    {
        throw invalid_argument("niepoprawny stopien wielomainu");
    }
    else
    {
        n = st;
        this->a = new double[this->n + 1];

        for (int i = 0; i < st; i++)
        {
            this->a[i] = wsp[i];
        }
    }
}

wielom::wielom(initializer_list<double> wsp)
{
    n = wsp.size() - 1;
    a = new double[n + 1];
    int i = 0;
    for (auto x : wsp)
    {
        this->a[i] = x;
        i++;
    }
}

wielom::wielom(const wielom &w)
{
    n = w.n;
    a = new double[n + 1];
    for (int i = 0; i <= w.n; ++i)
    {
        a[i] = w.a[i];
    }
}

wielom::wielom(wielom &&w)
{
    swap(n, w.n);
    swap(a, w.a);
}

wielom &wielom::operator=(const wielom &w)
{
    if (this != &w)
    {
        this->~wielom();
        n = w.n;
        a = new double[n + 1];
        for (int i = 0; i <= w.n; ++i)
        {
            a[i] = w.a[i];
        }
    }
    return *this;
}
wielom &wielom::operator=(wielom &&w)
{
    if (this != &w)
    {
        swap(n, w.n);
        swap(a, w.a);
    }
    return *this;
}

wielom ::~wielom()
{
    delete a;
}

int wielom::stopien() const
{
    return n;
}

double &wielom::operator[](int i)
{
    if (i < 0 || i > this->n)
    {
        throw invalid_argument("brak wspolczynnika przy tej potedze");
    }
    return a[i];
}

double wielom::operator[](int i) const
{
    if (i < 0 || i > n)
    {
        throw invalid_argument("brak wspolczynnika przy tej potedze");
    }
    return a[i];
}

double wielom::operator()(double x) const
{
    double result = a[n];
    for (int i = n - 1; i >= 0; --i)
    {
        result = result * x + a[i];
    }
    return result;
}

istream &operator>>(std::istream &st, wielom &w)
{
    int n;
    st >> n;
    if (n < 0)
    {
        throw std::invalid_argument("bledny stopien wielomianu ");
    }
    double *a = new double[n + 1];
    for (int i = 0; i <= n; ++i)
    {
        st >> a[i];
    }
    w = wielom(n, a);
    delete[] a;
    return st;
}

ostream &operator<<(std::ostream &wy, const wielom &w)
{
    wy << w.n << ": ";
    for (int i = w.n; i >= 0; --i)
    {
        wy << w[i];
        if (i > 0)
        {
            wy << " ";
        }
    }
    return wy;
}

wielom operator+(const wielom &u, const wielom &v)
{

    int maxSt = max(u.n, v.n);
    wielom result = wielom(maxSt);
    double a[maxSt + 1];
    for (int i = 0; i <= maxSt; i++)
    {
        if (i > u.n)
        {
            result.a[i] = v.a[i];
        }
        else if (i > v.n)
        {
            result.a[i] += u.a[i];
        }
        else
        {
            result.a[i] = u.a[i] + v.a[i];
        }
    }

    return result;
}

wielom operator-(const wielom &u, const wielom &v)
{
    int maxSt = max(u.n, v.n);
    wielom result(maxSt);
    double a[maxSt + 1];
    for (int i = 0; i <= maxSt; ++i)
    {
        if (i > u.n)
        {
            result.a[i] = v.a[i];
        }
        else if (i > v.n)
        {
            result.a[i] = u.a[i];
        }
        else
        {
            result.a[i] = u.a[i] + v.a[i];
        }
    }

    return result;
}

wielom operator*(const wielom &u, const wielom &v)
{
    int newSt = u.n + v.n;
    double *a = new double[newSt + 1]();
    for (int i = 0; i <= u.n; ++i)
    {
        for (int j = 0; j <= v.n; ++j)
        {
            a[i + j] += u[i] * v[j];
        }
    }
    wielom result(newSt, a);
    delete[] a;
    return result;
}

wielom operator*(const wielom &u, double c)
{
    double *a = new double[u.n]();
    for (int i = 0; i <= u.n; i++)
    {
        a[i] = u[i] * c;
    }

    wielom result(u.n, a);
    return result;
}

wielom &wielom::operator+=(const wielom &v)
{
    *this = *this + v;
    return *this;
}

wielom &wielom::operator-=(const wielom &v)
{
    *this = *this - v;
    return *this;
}

wielom &wielom::operator*=(double c)
{
    for (int i = 0; i <= this->n; i++)
    {
        a[i] *= c;
    }
    return *this;
}
#endif