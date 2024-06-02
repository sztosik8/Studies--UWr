#include "classes.hpp"
#include "functions.hpp"

Triangle::Triangle() : A(0, 0), B(1, 0), C(0, 1) {}

Triangle::Triangle(const Triangle &t) : A(t.A), B(t.B), C(t.C) {}

Triangle::Triangle(Point a, Point b, Point c)
{
    try
    {
        double area = area_g(a, b, c);
        if (area == 0)
        {
            throw invalid_argument("Nie można utworzyć trójkąta z takich punktów");
        }
        else
        {
            A = a;
            B = b;
            C = c;
        }
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
}

void Triangle::set_triangle(Point a, Point b, Point c)
{
    Triangle(a, b, c);
}

Point Triangle::getA() const
{
    return A;
}
Point Triangle::getB() const
{
    return B;
}
Point Triangle::getC() const
{
    return C;
}

void Triangle::translate(const Vector &v)
{
    A.translate(v);
    B.translate(v);
    C.translate(v);
}

void Triangle::symmetry(const Line &s)
{
    A.symmetry(s);
    A.symmetry(s);
    C.symmetry(s);
}

double Triangle::perimeter() const
{
    double p = length_g(A, B) + length_g(B, C) + length_g(C, A);
    return p;
}
double Triangle::area() const
{
    double p = 0.5 * abs((B.getx() - A.getx()) * (C.gety() - A.gety()) - (B.gety() - A.gety()) * (C.getx() - A.getx()));
    return p;
}
bool Triangle::is_inside(const Point &D)
{
    double p = area();
    double p1 = area_g(A, B, D);
    double p2 = area_g(A, C, D);
    double p3 = area_g(B, C, D);
    return (p == p1 + p2 + p3);
}
bool Triangle::isRightAngled() const
{
    Segment AB(A, B);
    Segment BC(B, C);
    Segment CA(C, A);

    double AB_len = AB.length();
    double BC_len = BC.length();
    double CA_len = CA.length();

    double AB2 = AB_len * AB_len;
    double BC2 = BC_len * BC_len;
    double CA2 = CA_len * CA_len;
    return (AB2 + BC2 == CA2) ||
           (AB2 + CA2 == BC2) ||
           (BC2 + CA2 == AB2);
}
bool Triangle::isAcuteAngled() const
{
    Segment AB(A, B);
    Segment BC(B, C);
    Segment CA(C, A);

    double AB_len = AB.length();
    double BC_len = BC.length();
    double CA_len = CA.length();

    double AB2 = AB_len * AB_len;
    double BC2 = BC_len * BC_len;
    double CA2 = CA_len * CA_len;
    return (AB2 + BC2 > CA2 &&
            AB2 + CA2 > BC2 &&
            BC2 + CA2 > AB2);
}
bool Triangle::isObtuseAngled() const
{
    Segment AB(A, B);
    Segment BC(B, C);
    Segment CA(C, A);

    double AB_len = AB.length();
    double BC_len = BC.length();
    double CA_len = CA.length();

    double AB2 = AB_len * AB_len;
    double BC2 = BC_len * BC_len;
    double CA2 = CA_len * CA_len;
    return (AB2 + BC2 < CA2 ||
            AB2 + CA2 < BC2 ||
            BC2 + CA2 < AB2);
}
Circle Triangle::Incircle() const
{
    Segment AB(A, B);

    Segment BC(B, C);
    Segment CA(C, A);

    double AB_len = AB.length();
    double BC_len = BC.length();
    double CA_len = CA.length();

    double perimeter = AB_len + BC_len + CA_len;
    double area = this->area();

    double inradius = area / (perimeter / 2);

    double x = (A.getx() * BC_len + B.getx() * CA_len + C.getx() * AB_len) / perimeter;
    double y = (A.gety() * BC_len + B.gety() * CA_len + C.gety() * AB_len) / perimeter;

    Point p(x, y);

    Circle incircle(p, inradius);
    return incircle;
}

Circle Triangle::Circumcircle() const
{
    double D = 2 * (A.getx() * (B.gety() - C.gety()) + B.getx() * (C.gety() - A.gety()) + C.getx() * (A.gety() - B.gety()));
    double Ux = ((A.getx() * A.getx() + A.gety() * A.gety()) * (B.gety() - C.gety()) +
                 (B.getx() * B.getx() + B.gety() * B.gety()) * (C.gety() - A.gety()) +
                 (C.getx() * C.getx() + C.gety() * C.gety()) * (A.gety() - B.gety())) /
                D;
    double Uy = ((A.getx() * A.getx() + A.gety() * A.gety()) * (C.getx() - B.getx()) +
                 (B.getx() * B.getx() + B.gety() * B.gety()) * (A.getx() - C.getx()) +
                 (C.getx() * C.getx() + C.gety() * C.gety()) * (B.getx() - A.getx())) /
                D;

    Point circumcenter(Ux, Uy);
    Segment AB(A, B);
    double circumradius = AB.length() / (2 * sin(atan2(B.gety() - A.gety(), B.getx() - A.getx())));

    Circle circumcircle(circumcenter, circumradius);
    return circumcircle;
}

bool operator==(const Triangle &t1, const Triangle &t2)
{
    return (t1.A == t2.A) && (t1.B == t2.B) && (t1.C == t2.C);
}
bool operator!=(const Triangle &t1, const Triangle &t2)
{
    return (t1.A != t2.A) || (t1.B != t2.B) || (t1.C != t2.C);
}
