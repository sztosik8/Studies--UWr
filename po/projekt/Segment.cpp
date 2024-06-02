#include "classes.hpp"
#include "functions.hpp"

Segment::Segment() : A(0, 0), B(1, 0) {}

Segment::Segment(const Segment &s) : A(s.A), B(s.B) {}

Segment::Segment(const Point &a, const Point &b)
{
    try
    {
        double len = length_g(a, b);
        if (len == 0)
        {
            throw invalid_argument("Nie można utworzyć odcinka z takich punktów");
        }
        else
        {
            A = a;
            B = b;
        }
    }
    catch (const exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
Segment::Segment(const Vector &v)
{
    Segment(Point(0, 0), Point(v.getx(), v.gety()));
}

void Segment::set_segment(const Point &a, const Point &b)
{
    Segment(a, b);
}

Point Segment::getA() const
{
    return A;
}
Point Segment::getB() const
{
    return B;
}
void Segment::translate(const Vector &v)
{
    A.translate(v);
    B.translate(v);
}

void Segment::symmetry(const Line &s)
{
    A.symmetry(s);
    B.symmetry(s);
}

double Segment::length() const
{
    return length_g(A, B);
}

bool Segment::is_parallel(const Segment &AB)
{
    double a1 = (A.gety() - B.gety()) / (A.getx() - B.getx());
    double a2 = (AB.getA().gety() - AB.getB().gety()) / (AB.getA().getx() - AB.getB().getx());

    return (a1 == a2);
}
bool Segment::is_perpendicular(const Segment &AB)
{
    double a1 = (A.gety() - B.gety()) / (A.getx() - B.getx());
    double a2 = (AB.getA().gety() - AB.getB().gety()) / (AB.getA().getx() - AB.getB().getx());

    return a1 * a2 == (-1);
}

bool Segment::belong(const Point &p)
{
    double w = (A.getx() * B.gety()) + (B.getx() * p.gety()) + (p.getx() * A.gety()) - (B.gety() * p.getx()) - (p.gety() * A.getx()) - (A.gety() * B.getx());
    if (w == 0)
    {
        if ((p.getx() >= fmin(A.getx(), B.getx())) && (p.getx() <= fmax(A.getx(), B.getx())) && (p.gety() >= fmin(A.gety(), B.gety())) && (p.gety() <= fmax(A.gety(), B.gety())))
            return true;
        else
            return false;
    }
    else
        return false;
}
bool Segment::intersect(const Segment &AB)
{
    double x1 = A.getx();
    double y1 = A.gety();
    double x2 = B.getx();
    double y2 = B.gety();

    double x3 = AB.getA().getx();
    double y3 = AB.getA().gety();
    double x4 = AB.getB().getx();
    double y4 = AB.getB().gety();

    double dx1 = x2 - x1;
    double dy1 = y2 - y1;
    double dx2 = x4 - x3;
    double dy2 = y4 - y3;

    double denom = dx1 * dy2 - dy1 * dx2;

    if (denom == 0)
        return false;
    double t1 = ((x1 - x3) * dy2 - (y1 - y3) * dx2) / denom;
    double t2 = ((x1 - x3) * dy1 - (y1 - y3) * dx1) / denom;

    return (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1);
}

bool operator==(const Segment &AB, const Segment &CD)
{
    return (AB.A==CD.A) && (AB.B == CD.B);
}
bool operator!=(const Segment &AB, const Segment &CD)
{
    return (AB.A!=CD.A) || (AB.B != CD.B);
}