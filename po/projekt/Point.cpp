#include "classes.hpp"

Point::Point() : x(0.0), y(0.0) {}

Point::Point(const Point &p) : x(p.x), y(p.y) {}

Point::Point(double dx, double dy) : x(dx), y(dy) {}

void Point::set_point(double dx, double dy)
{
    x = dx;
    y = dy;
}

double Point::getx() const
{
    return x;
}

double Point::gety() const
{
    return y;
}

void Point::translate(const Vector &v)
{
    x += v.getx();
    y += v.gety();
}

void Point::symmetry(const Line &k)
{
    double a = k.geta();
    double b = k.getb();

    double denom = (a * a + 1);
    double x_intersect = (x - a * (b - y)) / denom;
    double y_intersect = (a * x + b + y * a * a) / denom;

    x = 2 * x_intersect - x;
    y = 2 * y_intersect - y;
}

bool operator==(const Point &A, const Point &B)
{
    return abs(A.getx() - B.getx()) < 1e-5 && abs(A.gety() - B.gety()) < 1e-5;
}

bool operator!=(const Point &A, const Point &B)
{
    return abs(A.getx() - B.getx()) > 1e-5 || abs(A.gety() - B.gety()) > 1e-5;
}
