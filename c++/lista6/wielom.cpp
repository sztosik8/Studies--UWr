#ifndef WIELOM_CPP
#include "wielom.hpp"
#include <iostream>

using namespace std;

wielom::wielom()
{
    n = 0;
    a = new double[n + 1];
    a[0] = 1.0;
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
        a = new double[n + 1];
        *a = wsp[0];
    }
}

wielom::wielom(initializer_list<double> wsp)
{
    n = wsp.size() - 1;
    a = new double[n + 1];
    int i = 0;
    for (auto x : wsp)
    {
        a[i] = x;
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
    if (i < 0 || i > n)
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
    return calcValue(x);
}

double wielom::calcValue(double x) const
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
        throw std::invalid_argument("Invalid degree");
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
    double *a = new double[maxSt + 1];
    for (int i = 0; i <= maxSt; ++i)
    {
        a[i] = (i <= u.n ? u[i] : 0) + (i <= v.n ? v[i] : 0);
    }
    wielom result(maxSt, a);
    delete[] a;
    return result;
}

wielom operator-(const wielom &u, const wielom &v)
{
    int maxSt = max(u.n, v.n);
    double *a = new double[maxSt + 1];
    for (int i = 0; i <= maxSt; ++i)
    {
        a[i] = (i <= u.n ? u[i] : 0) - (i <= v.n ? v[i] : 0);
    }
    wielom result(maxSt, a);
    delete[] a;
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
/*
wielom operator*(double c)
{
    wielom result(*this); // Tworzymy kopię obecnego wielomianu
    for (int i = 0; i <= result.n; i++)
    {
        result.a[i] *= c; // Mnożymy każdy współczynnik przez stałą c
    }
    return result;
}
*/

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