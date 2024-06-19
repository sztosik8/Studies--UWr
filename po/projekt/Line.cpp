#include "classes.hpp"

Line::Line() : a(1), b(0) {}

Line::Line(const Line &s) : a(s.a), b(s.b) {}

Line::Line(const Point &A, const Point &B)
{
    if (A != B)
    {
        a = (B.gety() - A.gety()) / (B.getx() - A.getx());
        b = A.gety() - a * A.getx();

    }
    else
    {
        cerr << "Points A and B cannot be identical." << '\n';
        exit(1);
    }
}

Line::Line(double da, double db)
{
    if (da == db && db == 0)
    {
        cerr << "Coefficients a and b cannot both be zero." << '\n';
        exit(1);
    }
    else
    {
        a = da;
        b = db;
    }
}

Line::Line(const Vector &v)
{
    Point A(0, 0);
    Point B(v.getx(), v.gety());
     if (A != B)
    {
        a = (B.gety() - A.gety()) / (B.getx() - A.getx());
        b = A.gety() - a * A.getx();

    }
    else
    {
        cerr << "Vector can not be zero" << '\n';
        exit(1);
    }
}

Line::Line(const Segment &AB)
{
    Point A=AB.getA();
    Point B=AB.getB();
     if (A != B)
    {
        a = (B.gety() - A.gety()) / (B.getx() - A.getx());
        b = A.gety() - a * A.getx();

    }
    else
    {
        cerr << "Punkty A i B nie mogą być identyczne." << '\n';
        exit(1);
    }
}

void Line::set_Line(double da, double db)
{
    if (da == db && db == 0)
    {
        cerr << "Współczynniki a i b nie mogą być jednocześnie równe 0." << '\n';
        exit(1);
    }
    else
    {
        a = da;
        b = db;
    }
}

double Line::geta() const
{
    return a;
}
double Line::getb() const
{
    return b;
}

double Line::value_at(double x)
{
    return a * x + b;
}
double Line::zero_of_fun(double x)
{
    return -b / a;
}

bool Line::belong(const Point &A)
{
    return (A.gety() == value_at(A.getx()));
}

void Line::translate(const Vector &v)
{
    double new_b = b - (a * v.getx()) + v.gety();
    b = new_b;
}

bool Line::is_parallel(const Line &k)
{
    return a == k.a;
}

bool Line::is_perpendicular(const Line &k)
{
    return a * k.a == -1;
}

Line Line::perpendicular_at(const Point &A)
{

    if (a == 0)
    {
        cerr << "Program nie obsługuje prostych prostopadłych." << '\n';
        exit(1); // lub inna odpowiednia obsługa błędu
    }
    else
    {
        double a2 = -1.0 / a;
        double b2 = A.gety() - a2 * A.getx();

        return Line(a2, b2);
    }
}

bool operator==(const Line &k, const Line &l)
{
    return abs(k.a - l.a) < 1e-5 && abs(k.b - l.b) < 1e-5;
}

bool operator!=(const Line &k, const Line &l)
{
    return abs(k.a - l.a) > 1e-5 || abs(k.b - l.b) > 1e-5;
}
