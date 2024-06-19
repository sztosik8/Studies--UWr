#include "classes.hpp"
#include "functions.hpp"
#include <cmath>

Circle::Circle() : O(0, 0), r(1) {}

Circle::Circle(const Circle &c) : O(c.O), r(c.r) {}

Circle::Circle(const Point &dS, double dr)
{
    if (dr > 0)
    {
        O = dS;
        r = dr;
    }
    else
        cerr << "Cannot form a circle with these points (Ciecle())" << '\n';
}

void Circle::set_circle(const Point &ds, double dr)
{
    if (dr > 0)
    {
        O = ds;
        r = dr;
    }
    else
        cerr << "Cannot form a circle with these points (set_circle())" << '\n';
}

Point Circle::getO() const
{
    return O;
}

double Circle::getr()
{
    return r;
}

void Circle::translate(const Vector &v)
{
    O.translate(v);
}

void Circle::symmetry(const Line &s)
{
    O.symmetry(s);
}

double Circle::perimeter() const
{
    return 2 * M_PI * r;
}

double Circle::area() const
{
    return M_PI * r * r;
}
bool Circle::belong(const Point &A)
{
    return length_g(A, O) == r;
}

bool Circle::is_inside(const Point &A)
{
    return length_g(A, O) <= r;
}

bool Circle::is_tangent(const Circle &c)
{
    return abs(length_g(O, c.O) - (c.r + r)) < 1e-5;
}

bool Circle::is_intersect(const Circle &c)
{
    return length_g(O, c.O) < c.r + r;
}

bool Circle::is_separable(const Circle &c)
{
    return length_g(O, c.O) > c.r + r;
}

Line Circle::tangent_line(const Point &A)
{
    try
    {
        if (belong(A))
        {
            Line k(O, A);
            return k.perpendicular_at(A);
        }
        else
        {
            return Line();
            throw invalid_argument("Point A does not belong to the circle (tangent_line())");
        }
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
}

bool operator==(const Circle &c1, const Circle &c2)
{
    return c1.O == c2.O && abs(c1.r - c2.r) < 1e-5;
}

bool operator!=(const Circle &c1, const Circle &c2)
{
    return c1.O != c2.O || abs(c1.r - c2.r) > 1e-5;
}