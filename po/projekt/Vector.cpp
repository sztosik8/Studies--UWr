#include "classes.hpp"
#include "functions.hpp"

Vector::Vector() : x(0), y(0) {}

Vector::Vector(const Vector &v) : x(v.x), y(v.y) {}

Vector::Vector(double dx, double dy) : x(dx), y(dy) {}

Vector::Vector(const Point &A, const Point &B) : x(B.getx()-A.getx()), y(B.gety()-A.gety()) {}

Vector::Vector(const Segment &AB)
{
    Vector(AB.getA(), AB.getB());
}

void Vector:: set_vector(double dx, double dy)
{
    x=dx;
     y=dy;
}

double Vector::getx() const
{
    return x;
}

double Vector::gety() const
{
    return y;
}

double Vector::length() const
{
    return sqrt(x * x + y * y);
}

bool operator==(const Vector &v, const Vector &u)
{
    return (v.getx()==u.getx()) && (v.gety()==u.gety());
}

bool operator!=(const Vector &v, const Vector &u)
{
    return (v.getx()!=u.getx()) || (v.gety()!=u.gety());
}

Vector operator+(const Vector &v, const Vector &u)
{
    Vector result;
    result.set_vector(v.getx() + u.getx(), v.gety() + u.gety());

    return result;
}

Vector operator-(const Vector &v, const Vector &u)
{
    Vector result;
    result.set_vector(v.getx() - u.getx(), v.gety() - u.gety());

    return result;
}

Vector operator*(const Vector &v, double c)
{
    Vector result;
    result.set_vector(v.getx() * c, v.gety() * c);

    return result;
}

double operator*(const Vector &v, const Vector &u)
{
    return v.getx() * u.getx() + v.gety() * u.gety();
}

Vector &Vector::operator+=(const Vector &v)
{
    *this = *this + v;
    return *this;
}
Vector &Vector::operator-=(const Vector &v)
{
    *this = *this - v;
    return *this;
}

Vector Vector::operator*=(double c)
{
    return *this * c;
}
