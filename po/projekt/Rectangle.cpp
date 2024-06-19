#include "classes.hpp"
#include "functions.hpp"

Rectangle::Rectangle() : A(0, 0), B(1, 0), C(1, 1), D(0, 1) {}

Rectangle::Rectangle(const Rectangle &t) : A(t.A), B(t.B), C(t.C), D(t.D) {}

Rectangle::Rectangle(const Point &a, const Point &b, const Point &c, const Point &d)
{
    try
    {
        double len1 = length_g(a, b);
        double len2 = length_g(b, c);
        double len3 = length_g(c, d);
        Segment AB(a, b), BC(b, c), CD(c, d), DA(d, a);

        bool cond = AB.is_parallel(CD) && BC.is_parallel(DA) && AB.is_perpendicular(BC);

        if (cond)
        {
            A = a;
            B = b;
            C = c;
            D = d;
        }
        else
        {
            throw invalid_argument("Nie można utworzyć prostokata z takich punktów (Rectangle(Point, Point, Point, Point))");
        }
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
}

void Rectangle::set_rectangle(const Point &a, const Point &b, const Point &c, const Point &d)
{
    try
    {
        double len1 = length_g(a, b);
        double len2 = length_g(b, c);
        double len3 = length_g(c, d);
        Segment AB(a, b), BC(b, c), CD(c, d), DA(d, a);

        bool cond = AB.is_parallel(CD) && BC.is_parallel(DA) && AB.is_perpendicular(BC);
        if (cond)
        {
            A = a;
            B = b;
            C = c;
            D = d;
        }
        else
        {
            throw invalid_argument("Nie można utworzyć prostokata z takich punktów (set_rectangle())");
        }
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
}

Point Rectangle::getA() const
{
    return A;
}
Point Rectangle::getB() const
{
    return B;
}
Point Rectangle::getC() const
{
    return C;
}
Point Rectangle::getD() const
{
    return D;
}

void Rectangle::translate(const Vector &v)
{
    A.translate(v);
    B.translate(v);
    C.translate(v);
    D.translate(v);
}

void Rectangle::symmetry(const Line &s)
{
    A.symmetry(s);
    A.symmetry(s);
    C.symmetry(s);
    D.symmetry(s);
}

double Rectangle::perimeter() const
{
    double p = 2 * (length_g(A, B) + length_g(B, C));
    return p;
}
double Rectangle::area() const
{
    double p = length_g(A, B) * length_g(B, C);
    return p;
}
bool Rectangle::inside(const Point &e)
{
    double p = area();
    double p1 = area_g(A, B, e);
    double p2 = area_g(B, C, e);
    double p3 = area_g(C, D, e);
    double p4 = area_g(D, A, e);

    return abs(p - (p1 + p2 + p3 + p4)) < 1e-5;
}
bool Rectangle::is_square() const
{
    double len1 = length_g(A, B);
    double len2 = length_g(B, C);
    double len3 = length_g(C, D);
    return abs(len1 - len2) < 1e-5 && abs(len2 - len3) < 1e-5;
}

bool operator==(const Rectangle &r1, const Rectangle &r2)
{
    return (r1.A == r2.A) && (r1.B == r2.B) && (r1.C == r2.C) && (r1.D == r2.D);
}

bool operator!=(const Rectangle &r1, const Rectangle &r2)
{
    return (r1.A != r2.A) || (r1.B != r2.B) || (r1.C != r2.C) && (r1.D != r2.D);
}