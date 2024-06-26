#include "classes.hpp"
#include "functions.hpp"

Square::Square() : A(0, 0), B(1, 0), C(0, 1), D(1, 1) {}

Square::Square(const Square &t) : A(t.A), B(t.B), C(t.C), D(t.D) {}

Square::Square(const Point &a, const Point &b, const Point &c, const Point &d)
{
    try
    {
        double len1 = length_g(a, b);
        double len2 = length_g(b, c);
        double len3 = length_g(c, d);

        Segment AC(a, c), BD(b, d);

        bool cond = (len1 == len2) && (len2 == len3) && AC.is_perpendicular(BD);
        if (cond)
        {
            A = a;
            B = b;
            C = c;
            D = d;
        }
        else
        {
            throw invalid_argument("Cannot form a square with these points (Square(Point, Point, Point, Point))");
        }
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
}

void Square::set_square(const Point &a, const Point &b, const Point &c, const Point &d)
{
    try
    {
        double len1 = length_g(a, b);
        double len2 = length_g(b, c);
        double len3 = length_g(c, d);

        Segment AC(a, c), BD(b, d);

        bool cond = (len1 == len2) && (len2 == len3) && AC.is_perpendicular(BD);
        if (cond)
        {
            A = a;
            B = b;
            C = c;
            D = d;
        }
        else
        {
            throw invalid_argument("Cannot form a square with these points (set_square())");
        }
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
}

Point Square::getA() const
{
    return A;
}
Point Square::getB() const
{
    return B;
}
Point Square::getC() const
{
    return C;
}
Point Square::getD() const
{
    return D;
}

void Square::translate(const Vector &v)
{
    A.translate(v);
    B.translate(v);
    C.translate(v);
    D.translate(v);
}

void Square::symmetry(const Line &k)
{
    A.symmetry(k);
    A.symmetry(k);
    C.symmetry(k);
    D.symmetry(k);
}

double Square::perimeter() const
{
    double p = 4 * length_g(A, B);
    return p;
}
double Square::area() const
{
    double p = pow(length_g(A, B), 2);
    return p;
}
bool Square::inside(const Point &e)
{
    double p = area();
    double p1 = area_g(A, B, e);
    double p2 = area_g(B, C, e);
    double p3 = area_g(C, D, e);
    double p4 = area_g(D, A, e);

    return abs(p - (p1 + p2 + p3 + p4)) < 1e-5;
}

bool operator==(const Square &s1, const Square &s2)
{
    return (s1.A == s2.A) && (s1.B == s2.B) && (s1.C == s2.C) && (s1.D == s2.D);
}

bool operator!=(const Square &s1, const Square &s2)
{
    return (s1.A != s2.A) || (s1.B != s2.B) || (s1.C != s2.C) && (s1.D != s2.D);
}