#include "functions.hpp"

double length_g(Point a, Point b)
{
    double x = a.getx() - b.getx();
    double y = a.gety() - b.gety();
    return sqrt(x * x + y * y);
}

double area_g(Point a, Point b, Point c)
{
    double p = 0.5 * abs((b.getx() - a.getx()) * (c.gety() - a.gety()) - (b.gety() - a.gety()) * (c.getx() - a.getx()));
    return p;
}
