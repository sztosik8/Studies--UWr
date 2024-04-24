#ifndef CLASSES_HPP
#define CLASSES_HPP
#include <iostream>
#include <cmath>
using namespace std;

class Vector
{
private:
    double x;
    double y;

public:
    Vector();
    Vector(const Vector &v);
    void set_vector(double dx, double dy);
    double getX();
    double getY();
};

class Straight
{
private:
    double a;
    double b;
    double c;

public:
    Straight();
    Straight(const Straight &s);
    void set_straight(double da, double db, double dc);
    double geta();
    double getb();
    double getc();
};

class Point
{
private:
    double x;
    double y;

public:
    Point();
    Point(const Point &p);
    void translate(Vector v);
    void symmetry(Straight s);
    void rotate(Point p, double angle);
    void set_point(double dx, double dy);
    double getX();
    double getY();
    void Print();
};

class Segment
{
private:
    Point a;
    Point b;

public:
    Segment();
    Segment(const Segment &s);
    void translate(Vector v);
    double length_s();
    bool belong(Point p);
    void symmetry(Straight s);
    void rotate(Point c, double angle);
    void set_segment(Point a, Point b);
    Point geta();
    Point getb();
    void Print();
};

class Triangle
{
private:
    Point a;
    Point b;
    Point c;

public:
    Triangle();
    Triangle(const Triangle &t);
    double perimeter();
    double area();
    bool inside(Point d);
    void translate(Vector d);
    void symmetry(Straight s);
    void rotate(Point d, double angle);
    void set_triangle(Point a, Point b, Point c);
    Point geta();
    Point getb();
    Point getc();
    void Print();
};

#endif