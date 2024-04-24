#include "classes.hpp"
#include "functions.hpp"

// ---------------------  Vector  -----
Vector::Vector()
{
    x = 0;
    y = 0;
}

Vector::Vector(const Vector &v)
{
    x = v.x;
    y = v.y;
}
void Vector::set_vector(double dx, double dy)
{
    x = dx;
    y = dy;
}

double Vector::getX()
{
    return x;
}

double Vector::getY()
{
    return y;
}
// ---------------------  Straight  -----

Straight::Straight()
{
    a = 1;
    b = 0;
    c = 0;
}
Straight::Straight(const Straight &s)
{
    a = s.a;
    b = s.b;
    c = s.c;
}
void Straight::set_straight(double da, double db, double dc)
{
    try
    {
        if (da == db and db == 0)
        {
            throw invalid_argument("Wspolczynniki a i b nie moga byc jednoczesnie rowne 0");
        }
        else
        {
            a = da;
            b = db;
            c = dc;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

double Straight::geta()
{
    return a;
}
double Straight::getb()
{
    return b;
}
double Straight::getc()
{
    return c;
}

// ---------------------  Point  -----

Point::Point()
{
    x = 0.0;
    y = 0.0;
}

Point::Point(const Point &p)
{
    x = p.x;
    y = p.y;
}

void Point::translate(Vector v)
{
    x += v.getX();
    y += v.getY();
}

void Point::symmetry(Straight s)
{
    double a = s.geta();
    double b = s.getb();
    double c = s.getc();

    double d = (a * x + b * y + c) / sqrt(a * a + b * b);
    x = x - 2 * a * d / (a * a + b * b);
    y = y - 2 * b * d / (a * a + b * b);
}

void Point::rotate(Point c, double angle)
{
    angle = angle * M_PI / 180;
    x = (x - c.getX()) * cos(angle) - (y - c.getY()) * sin(angle) + c.getX();
    y = (x - c.getX()) * sin(angle) + (y - c.getY()) * cos(angle) + c.getY();
    // cout<<"kat  "<< angle <<"  sin = "<<sin(angle)<<"  cos = "<<cos(angle)<<'\n';
}

void Point::set_point(double dx, double dy)
{
    x = dx;
    y = dy;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}
void Point::Print()
{
    cout << "(" << x << ", " << y << ")";
}

// ---------------------  Segment  -------------

Segment::Segment()
{
    a.set_point(0, 0);
    b.set_point(1, 1);
}
Segment::Segment(const Segment &s)
{
    a = s.a;
    b = s.b;
}
void Segment::translate(Vector v)
{
    a.translate(v);
    b.translate(v);
}

double Segment::length_s()
{
    return length(a, b);
}

bool Segment::belong(Point p)
{
    double w = (a.getX() * b.getY()) + (b.getX() * p.getY()) + (p.getX() * a.getY()) - (b.getY() * p.getX()) - (p.getY() * a.getX()) - (a.getY() * b.getX());
    if (w == 0)
    {
        if ((p.getX() >= fmin(a.getX(), b.getX())) && (p.getX() <= fmax(a.getX(), b.getX())) && (p.getY() >= fmin(a.getY(), b.getY())) && (p.getY() <= fmax(a.getY(), b.getY())))
            return true;
        else
            return false;
    }
    else
        return false;
}
void Segment::symmetry(Straight s)
{
    a.symmetry(s);
    b.symmetry(s);
}


void Segment::rotate(Point c, double angle)
{
    a.rotate(c, angle);
    b.rotate(c, angle);
}
void Segment::set_segment(Point A, Point B)
{
    try
    {
        double len = length(A, B);
        if (len == 0)
        {
            throw invalid_argument("Nie można utworzyć odcinka z takich punktów");
        }
        else
        {
            a = A;
            b = B;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

Point Segment::geta()
{
    return a;
}
Point Segment::getb()
{
    return b;
}
void Segment::Print()
{
    cout << "{";
    a.Print();
    cout << ", ";
    b.Print();
    cout << "}" << '\n';
}

// ---------------------  Triangle  -----

Triangle::Triangle()
{
    a.set_point(0, 0);
    b.set_point(1, 0);
    c.set_point(0, 1);
}
Triangle::Triangle(const Triangle &t)
{
    a = t.a;
    b = t.b;
    c = t.c;
}
double Triangle::perimeter()
{
    double p = length(a, b) + length(b, c) + length(c, a);
    return p;
}
double Triangle::area()
{
    double p = 0.5 * abs((b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX()));
    return p;
}
bool Triangle::inside(Point d)
{
    double p = area();
    double p1 = pole_g(a, b, d);
    double p2 = pole_g(a, c, d);
    double p3 = pole_g(b, c, d);
    return (p == p1 + p2 + p3);
}
void Triangle::translate(Vector v)
{
    a.translate(v);
    b.translate(v);
    c.translate(v);
}

void Triangle::symmetry(Straight s)
{
    a.symmetry(s);
    b.symmetry(s);
    c.symmetry(s);
}


void Triangle::rotate(Point d, double angle)
{
    a.rotate(c, angle);
    b.rotate(c, angle);
    c.rotate(c, angle);
}
void Triangle::set_triangle(Point pa, Point pb, Point pc)
{

    try
    {
        double area = pole_g(pa, pb, pc);
        if (area == 0)
        {
            throw invalid_argument("Nie można utworzyć trójkata z takich punktów");
        }
        else
        {
            a = pa;
            b = pb;
            c = pc;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

Point Triangle::geta()
{
    return a;
}
Point Triangle::getb()
{
    return b;
}
Point Triangle::getc()
{
    return c;
}

void Triangle::Print()
{
    cout << "{";
    a.Print();
    cout << ", ";
    b.Print();
    cout << ", ";
    c.Print();
    cout << "}" << '\n';
}
