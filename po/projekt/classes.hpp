#ifndef CLASSES_HPP
#define CLASSES_HPP
#include <iostream>
#include <cmath>
using namespace std;

class Vector;
class Point;
class Segment;
class Triangle;
class Square;
class Rectangle;
class Circle;
class Line;


class Vector
{
private:
    double x;
    double y;

public:
    Vector();
    Vector(const Vector &v);
    Vector(double x, double y);
    Vector(const Point &A, const Point &B);
    Vector(const Segment &AB);
    void set_vector(double x, double y);

    double getx() const;
    double gety() const;

    double length() const;

    friend bool operator==(const Vector &v, const Vector &u); 
    friend bool operator!=(const Vector &v, const Vector &u); 

    friend Vector operator+(const Vector &v, const Vector &u); 
    friend Vector operator-(const Vector &v, const Vector &u); 
    friend Vector operator*(const Vector &v, double c); 
    friend double operator*(const Vector &v, const Vector &u); 
    

    Vector &operator+=(const Vector &v);
    Vector &operator-=(const Vector &v);
    Vector &operator*=(double c);

};

class Point
{
private:
    double x;
    double y;

public:
    Point();
    Point(const Point &p);
    Point(double x, double y);
    void set_point(double x, double y);

    double getx() const;
    double gety() const;

    void translate(const Vector &v);
    void symmetry( const Line &k);

    friend bool operator==(const Point &A, const Point &B); 
    friend bool operator!=(const Point &A, const Point &B); 
};

class Segment
{
private:
    Point A;
    Point B;

public:
    Segment();
    Segment(const Segment &s);
    Segment(const Point &A, const Point &B);
    Segment(const Vector &v);
    
    void set_segment(const Point &A, const Point &B);

    Point getA() const;
    Point getB() const;

    void translate(const Vector &v);
    void symmetry(const Line &k);
    double length() const;
    bool is_parallel(const Segment &AB);
    bool is_perpendicular(const Segment &AB);
    bool belong(const Point &A);
    bool intersect(const Segment &AB);

    friend bool operator==(const Segment &AB, const Segment &CD); 
    friend bool operator!=(const Segment &AB, const Segment &CD); 

};

class Triangle
{
private:
    Point A;
    Point B;
    Point C;

public:
    Triangle();
    Triangle(const Triangle &t);
    Triangle(Point A, Point B, Point C);
    void set_triangle(Point A, Point B, Point C);

    Point getA() const;
    Point getB() const;
    Point getC() const;

    void translate(const Vector &v);
    void symmetry(const Line &k);
    double perimeter() const;
    double area() const;
    bool is_inside(const Point &d);
    bool isRightAngled() const;
    bool isAcuteAngled() const;
    bool isObtuseAngled() const;
    Circle Incircle() const;
    Circle Circumcircle() const;

    friend bool operator==(const Triangle &t1, const Triangle &t2); 
    friend bool operator!=(const Triangle &t1, const Triangle &t2);

};

class Square
{
private:
    Point A;
    Point B;
    Point C;
    Point D;

public:
    Square();
    Square(const Square &s);
    Square(const Point &A, const Point &B, const Point &C, const Point &D);
    void set_square(const Point &A, const Point &B, const Point &C, const Point &D);

    Point getA() const;
    Point getB() const;
    Point getC() const;
    Point getD() const;
    
    void translate(const Vector &v);
    void symmetry(const Line &k);
    double perimeter()const ;
    double area()const ;
    bool inside(const Point &A); 

    friend bool operator==(const Square &s1, const Square &s2); 
    friend bool operator!=(const Square &s1, const Square &s2); 
    
};

class Rectangle
{
    private:
        Point A;
        Point B;
        Point C;
        Point D;

public:
    Rectangle();
    Rectangle(const Rectangle &t);
    Rectangle(const Point &A, const Point &B,const  Point &C, const Point &D);
    void set_rectangle(const Point &A, const Point &B, const Point &C, const Point &D);
   
    Point getA() const ;
    Point getB()const ;
    Point getC()const ;
    Point getD()const ;

    void translate(const Vector &v);
    void symmetry(const Line &k);
    double perimeter()const ;
    double area()const ;
    bool inside(const Point &A); 
    bool is_square() const ;

    friend bool operator==(const Rectangle &r1, const Rectangle &r2); 
    friend bool operator!=(const Rectangle &r1, const Rectangle &r2); 
};

class Circle
{
private:
    Point O;
    double r;

public:
    Circle();
    Circle(const Circle &S);
    Circle(const Point &S, double r);
    void set_circle(const Point &O, double r);
    
    Point getO() const;
    double getr();
    
    void translate(const Vector &v);
    void symmetry(const Line &k);
    double perimeter() const ;
    double area() const ;
    bool belong(const Point &A);
    bool is_inside(const Point &A);   
    bool is_intersect(const Circle &S); // przecinajace
    bool is_separable(const Circle &S);
    bool is_tangent(const Circle &S);
    Line tangent_line(const Point &A); //styczne

    friend bool operator==(const Circle &s1, const Circle &s2); 
    friend bool operator!=(const Circle &s1, const Circle &s2); 
    
};


class Line // (y=ax+b)
{
private:
    double a;
    double b;

public:
    Line();
    Line(const Line &s);
    Line(const Point &A, const Point &B);
    Line(double a, double b);
    Line(const Vector &v);
    Line(const Segment &AB);
    void set_Line(double da, double db);

    double geta() const;
    double getb() const;

    void translate(const Vector &v);
    double value_at(double x);
    double zero_of_fun(double x);
    bool belong(const Point &x);
    bool is_parallel(const Line &k);
    bool is_perpendicular(const Line &k);
    Line perpendicular_at(const Point &A);

    friend bool operator==(const Line &k, const Line &l); 
    friend bool operator!=(const Line &k, const Line &l); ; 
    
};
#endif

/*
class Parable
{
private:
    double a;
    double b;
    double c;

public:
    Parable();
    Parable(const Parable &p);
    Parable(Point A, Point B, Point C);
    void set_Parable(double a, double b, double c);

    double geta();
    double getb();
    double getc();

    void translate(const Vector &v);
    void symmetry(const Line &k);
    double value_at(double x) const;
    pair<Point,Point> delta();
    double zero_of_fun(double x);
    bool belong(Point A);
    Line parallel_at(double x);
    Line perpendicular_at(double x);
    Line derivative();
   
};
*/
