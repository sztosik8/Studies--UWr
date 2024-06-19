#include <iostream>
#include <cmath>
#include "classes.hpp"
#include "functions.hpp"

using namespace std;

// Function to test Vector constructors and methods
bool testVectorConstructors()
{
    Vector v1;
    Vector v2(3, 4);
    Point A(1, 1);
    Point B(4, 5);
    Vector v3(A, B);
    Segment s(A, B);
    Vector v4(s);
    Vector v5(v2);
    if (!(v1.getx() == 0 && v1.gety() == 0))
        return false;
    if (!(v2.getx() == 3 && v2.gety() == 4))
        return false;
    if (!(v3.getx() == 3 && v3.gety() == 4))
        return false;
    if (!(v4.getx() == 3 && v4.gety() == 4))
        return false;
    if (!(v5.getx() == 3 && v5.gety() == 4))
        return false;

    return true;
}

bool testSetVector()
{
    Vector v;
    v.set_vector(5, 6);
    if (!(v.getx() == 5 && v.gety() == 6))
        return false;
    return true;
}

bool testGetX()
{
    Vector v(7, 8);
    if (v.getx() != 7)
        return false;
    return true;
}

bool testGetY()
{
    Vector v(7, 8);
    if (v.gety() != 8)
        return false;
    return true;
}

bool testLength()
{
    Vector v(3, 4);
    if (v.length() != 5)
        return false;
    return true;
}

bool testEqualityOperator()
{
    Vector v1(1, 2);
    Vector v2(1, 2);
    if (!(v1 == v2))
        return false;
    return true;
}

bool testInequalityOperator()
{
    Vector v1(1, 2);
    Vector v2(3, 4);
    if (!(v1 != v2))
        return false;
    return true;
}

bool testAdditionOperator()
{
    Vector v1(1, 2);
    Vector v2(3, 4);
    Vector v3 = v1 + v2;
    if (!(v3 == Vector(4, 6)))
        return false;
    return true;
}

bool testSubtractionOperator()
{
    Vector v1(5, 6);
    Vector v2(3, 4);
    Vector v3 = v1 - v2;
    if (!(v3 == Vector(2, 2)))
        return false;
    return true;
}

bool testScalarMultiplicationOperator()
{
    Vector v(2, 3);
    Vector v2 = v * 2;
    if (!(v2 == Vector(4, 6)))
        return false;
    return true;
}

bool testDotProductOperator()
{
    Vector v1(1, 2);
    Vector v2(3, 4);
    if (v1 * v2 != 11)
        return false;
    return true;
}

bool testAdditionAssignmentOperator()
{
    Vector v1(1, 2);
    Vector v2(3, 4);
    v1 += v2;
    if (!(v1 == Vector(4, 6)))
        return false;
    return true;
}

bool testSubtractionAssignmentOperator()
{
    Vector v1(5, 6);
    Vector v2(3, 4);
    v1 -= v2;
    if (!(v1 == Vector(2, 2)))
        return false;
    return true;
}

bool testScalarMultiplicationAssignmentOperator()
{
    Vector v(2, 3);
    v *= 2;
    if (!(v == Vector(4, 6)))
        return false;
    return true;
}

// Function to test Point constructors and methods

bool testPointConstructors()
{
    Point p1;
    Point p2(3, 4);

    if (!(p1.getx() == 0 && p1.gety() == 0))
        return false;
    if (!(p2.getx() == 3 && p2.gety() == 4))
        return false;

    return true;
}

bool testSetPoint()
{
    Point p;
    p.set_point(5, 6);
    if (!(p.getx() == 5 && p.gety() == 6))
        return false;
    return true;
}

bool testGetXPoint()
{
    Point p(7, 8);
    if (p.getx() != 7)
        return false;
    return true;
}

bool testGetYPoint()
{
    Point p(7, 8);
    if (p.gety() != 8)
        return false;
    return true;
}

bool testTranslatePoint()
{
    Point p(1, 2);
    Vector v(3, 4);
    p.translate(v);
    if (!(p == Point(4, 6)))
        return false;
    return true;
}

bool testSymmetry()
{
    Point p(2, 0);
    Point reflected_point(-3, 1);

    Line k(5, 3); // y=2x+1
    p.symmetry(k);

    if (!(p == reflected_point))
        return false;
    return true;
}

bool testEqualityOperatorPoint()
{
    Point p1(1, 2);
    Point p2(1, 2);
    if (!(p1 == p2))
        return false;
    return true;
}

bool testInequalityOperatorPoint()
{
    Point p1(1, 2);
    Point p2(3, 4);
    if (!(p1 != p2))
        return false;
    return true;
}

// Function to test Segment constructors and methods

bool testSegmentDefaultConstructor()
{
    Segment s;
    Point A(0, 0);
    Point B(1, 0);
    if (!(s.getA() == A && s.getB() == B))
        return false;
    return true;
}

bool testSegmentCopyConstructor()
{
    Point A(1, 2);
    Point B(3, 4);
    Segment s1(A, B);
    Segment s2(s1);
    if (!(s2.getA() == A && s2.getB() == B))
        return false;
    return true;
}

bool testSegmentPointConstructor()
{
    Point A(1, 2);
    Point B(3, 4);
    Segment s(A, B);
    if (!(s.getA() == A && s.getB() == B))
        return false;
    return true;
}

bool testSegmentVectorConstructor()
{
    Vector v(2, 3);
    Segment s(v);
    Point A(0, 0);
    if (!(s.getA() == A && s.getB() == Point(v.getx(), v.gety())))
        return false;
    return true;
}

bool testSetSegment()
{
    Point A(1, 2);
    Point B(3, 4);
    Segment s;
    s.set_segment(A, B);
    if (!(s.getA() == A && s.getB() == B))
        return false;
    return true;
}

bool testLengthSegment()
{
    Point A(1, 2);
    Point B(4, 6);
    Segment s(A, B);
    if (s.length() != 5)
        return false;
    return true;
}

bool testParallelSegment()
{
    Segment s1(Point(1, 1), Point(2, 1));
    Segment s2(Point(1, 2), Point(2, 2));
    if (!s1.is_parallel(s2))
        return false;
    return true;
}

bool testPerpendicularSegment()
{
    Segment s1(Point(1, 2), Point(2, 1));
    Segment s2(Point(1, 1), Point(2, 2));

    if (!s1.is_perpendicular(s2))
        return false;
    return true;
}

bool testBelongSegment()
{
    Point A(-1, 1);
    Point B(1, 5);
    Segment s(A, B);
    Point P1(0, 3); // Point P lies on segment AB
    Point P2(2, 7); // Point P dont lay on segment AB
    if (!s.belong(P1))
        return false;
    if (s.belong(P2))
        return false;
    return true;
}

bool testIntersectSegment()
{
    Segment s1(Point(0, 0), Point(10, 1));
    Segment s2(Point(0, 0), Point(0, 5));    // Segments intersect
    Segment s3(Point(-5, 2), Point(-2, -4)); // Segments dont intersect
    if (!s1.intersect(s2))
        return false;
    if (s1.intersect(s3))
        return false;
    return true;
}

bool testEqualityOperatorSegment()
{
    Segment s1(Point(1, 2), Point(3, 4));
    Segment s2(Point(1, 2), Point(3, 4));
    if (!(s1 == s2))
        return false;
    return true;
}

bool testInequalityOperatorSegment()
{
    Segment s1(Point(1, 2), Point(3, 4));
    Segment s2(Point(5, 6), Point(7, 8));
    if (!(s1 != s2))
        return false;
    return true;
}

// Function to test Triangle constructors and methods

bool testTriangleDefaultConstructor()
{
    Triangle t;

    if (!(t.getA() == Point(0, 0) &&
          t.getB() == Point(1, 0) &&
          t.getC() == Point(0, 1)))
    {
        return false;
    }
    return true;
}

bool testTriangleCopyConstructor()
{
    Point A(1, 2);
    Point B(3, 1);
    Point C(5, 6);
    Triangle t1(A, B, C);
    Triangle t2(t1);

    if (!(t1.getA() == t2.getA() && t1.getB() == t2.getB() && t1.getC() == t2.getC()))
    {
        return false;
    }
    return true;
}

bool testTrianglePointConstructor()
{
    Point A(1, 2);
    Point B(3, 1);
    Point C(5, 6);
    Triangle t(A, B, C);
    if (!(t.getA() == A && t.getB() == B && t.getC() == C))
    {
        return false;
    }
    return true;
}

bool testSetTriangle()
{
    Triangle t;
    Point A(1, 2);
    Point B(3, 1);
    Point C(5, 6);
    t.set_triangle(A, B, C);
    if (!(t.getA() == A && t.getB() == B && t.getC() == C))
    {
        return false;
    }
    return true;
}

bool testPerimeter()
{
    Point A(0, 0);
    Point B(3, 0);
    Point C(0, 4);
    Triangle t(A, B, C);
    if (t.perimeter() != 12)
    {
        return false;
    }
    return true;
}

bool testArea()
{
    Point A(0, 0);
    Point B(3, 0);
    Point C(0, 4);
    Triangle t(A, B, C);
    if (t.area() != 6)
    {
        return false;
    }
    return true;
}

bool testIsInside()
{
    Point A(0, 0);
    Point B(3, 0);
    Point C(0, 4);
    Triangle t(A, B, C);
    Point D(1, 1);
    // Check if point (1,1) is inside triangle with points (0,0), (3,0), (0,4)
    if (!t.is_inside(D))
    {
        return false;
    }
    return true;
}

bool testIsRightAngled()
{
    Point A(0, 0);
    Point B(3, 0);
    Point C(0, 4);
    Triangle t(A, B, C);
    // Triangle with these points is right-angled
    if (!t.isRightAngled())
    {
        return false;
    }
    A.set_point(0, 2);
    B.set_point(3, 0);
    C.set_point(0, 4);
    t.set_triangle(A, B, C);
    // Triangle with these point is not right-angled
    if (t.isRightAngled())
    {
        return false;
    }
    return true;
}

bool testIsAcuteAngled()
{
    Point A(0, 0);
    Point B(3, 3);
    Point C(0, 4);
    Triangle t(A, B, C);
    // Triangle with these points is acute-angled
    if (!t.isAcuteAngled())
    {
        return false;
    }

    A.set_point(-30, 2);
    t.set_triangle(A, B, C);
    if (t.isAcuteAngled())
    {
        return false;
    }
    return true;
}

bool testIsObtuseAngled()
{
    Point A(-30, 0);
    Point B(3, 0);
    Point C(0, 3);
    Triangle t(A, B, C);
    // Triangle with these points is obtuse-angled
    if (!t.isObtuseAngled())
    {
        return false;
    }
    A.set_point(0, -1);
    t.set_triangle(A, B, C);
    if (t.isObtuseAngled())
    {
        return false;
    }
    return true;
}

bool testIncircle()
{

    Point A(-9, 3);
    Point B(-5, 6);
    Point C(-1, 3);
    Triangle t(A, B, C);
    Circle incir = t.Incircle();

    Point S(-5, double(13 / 3.0));
    double r = double(13 / 3.0) - 3;
    Circle corr(S, abs(r));

    if (!(incir == corr))
    {
        return false;
    }
    return true;
}

bool testCircumcircle()
{
    Point A(-2, 5);
    Point B(6, 1);
    Point C(-6, -1);
    Triangle t(A, B, C);
    Circle circ = t.Circumcircle();

    Point s(1 / 8.0, -3 / 4.0);
    double r = (10);
    Circle corr(s, r);
    if (!(corr == circ))
    {
        return false;
    }

    return true;
}

bool testEqualityOperatorTriangle()
{
    Point A(1, 2);
    Point B(3, 1);
    Point C(5, 6);
    Triangle t1(A, B, C);
    Triangle t2(A, B, C);
    if (!(t1 == t2))
    {
        return false;
    }
    return true;
}

bool testInequalityOperatorTriangle()
{
    Point A(1, 2);
    Point B(3, 1);
    Point C(5, 6);
    Point D(4, 8);
    Triangle t1(A, B, C);
    Triangle t2(A, B, D);
    if (!(t1 != t2))
    {
        return false;
    }
    return true;
}

// Function to test square constructors and methods

bool testSquareDefaultConstructor()
{
    Square s1;
    if (!(s1.getA() == Point(0, 0) && s1.getB() == Point(1, 0) && s1.getC() == Point(0, 1) && s1.getD() == Point(1, 1)))
        return false;
    return true;
}

bool testSquareCopyConstructor()
{
    Point A(1, 1), B(1, 2), C(2, 2), D(2, 1);
    Square s1(A, B, C, D);

    Square s2(s1);
    if (!(s1 == s2))
        return false;
    return true;
}

bool testSquarePointConstructor()
{
    Point A(1, 1), B(1, 2), C(2, 2), D(2, 1);
    Square s(A, B, C, D);
    if (!(s.getA() == A && s.getB() == B && s.getC() == C && s.getD() == D))
        return false;
    return true;
}

bool testSetSquare()
{
    Point A(1, 1), B(1, 2), C(2, 2), D(2, 1);
    Square s;
    s.set_square(A, B, C, D);
    if (!(s.getA() == A && s.getB() == B && s.getC() == C && s.getD() == D))
        return false;
    return true;
}

bool testPerimeterSquare()
{
    Point A(1, 1), B(1, 2), C(2, 2), D(2, 1);
    Square s(A, B, C, D);
    if (std::abs(s.perimeter() - 4) > 1e-5)
        return false;
    return true;
}

bool testAreaSquare()
{
    Point A(1, 1), B(1, 2), C(2, 2), D(2, 1);
    Square s(A, B, C, D);
    if (std::abs(s.area() - 1) > 1e-5)
        return false;
    return true;
}

bool testInsideSquare()
{
    Point A(1, 1), B(1, 2), C(2, 2), D(2, 1);
    Square s(A, B, C, D);
    Point P(1.5, 1.5);
    Point Q(5, 5);
    if (!s.inside(P))
        return false;
    if (s.inside(Q))
        return true;

    return true;
}

bool testEqualityOperatorSquare()
{
    Point A(1, 1), B(1, 2), C(2, 2), D(2, 1);
    Square s1(A, B, C, D);
    Square s2(A, B, C, D);
    if (!(s1 == s2))
        return false;
    return true;
}

bool testInequalityOperatorSquare()
{
    Point A(1, 1), B(1, 2), C(2, 2), D(2, 1);
    Point E(0, 0), F(0, 1), G(1, 1), H(1, 0);
    Square s1(A, B, C, D);
    Square s2(E, F, G, H);
    if (!(s1 != s2))
        return false;
    return true;
}

// Function to test rectangle constructors and methods

bool testRectangleConstructors()
{
    Rectangle r1;
    Point A(0, 0), B(1, 0), C(1, 1), D(0, 1);
    Rectangle r2(A, B, C, D);
    Rectangle r3(r2);

    if (!(r1 == Rectangle(A, B, C, D)))
        return false;

    if (!(r2 == Rectangle(A, B, C, D)))
        return false;
    if (!(r3 == Rectangle(A, B, C, D)))
        return false;

    return true;
}

bool testSetRectangle()
{
    Point A(0, 0), B(0, 2), C(3, 2), D(3, 0);
    Rectangle r;
    r.set_rectangle(A, B, C, D);
    if (!(r == Rectangle(A, B, C, D)))
        return false;
    return true;
}

bool testPerimeterRectangle()
{
    Point A(0, 0), B(0, 2), C(3, 2), D(3, 0);
    Rectangle r(A, B, C, D);
    if (r.perimeter() - 10 > 1e-5)
        return false;
    return true;
}

bool testAreaRectangle()
{
    Point A(0, 0), B(0, 2), C(3, 2), D(3, 0);
    Rectangle r(A, B, C, D);
    if (r.area() != 6)
        return false;
    return true;
}

bool testInsideRectangle()
{
    Point A(0, 0), B(0, 2), C(3, 2), D(3, 0);
    Rectangle r(A, B, C, D);
    Point P(1, 1), Q(4, 4);

    if (!r.inside(P))
        return false;
    if (r.inside(Q))
        return false;

    return true;
}

bool testIsSquare()
{
    Point A(0, 0), B(0, 1), C(1, 1), D(1, 0);
    Point E(0, 0), F(0, 2), G(3, 2), H(3, 0);
    Rectangle r1(A, B, C, D);
    Rectangle r2(E, F, G, H);

    if (!r1.is_square())
        return false;
    if (r2.is_square())
        return false;

    return true;
}

bool testEqualityOperatorRectangle()
{
    Point A(0, 0), B(0, 2), C(3, 2), D(3, 0);
    Rectangle r1(A, B, C, D);
    Rectangle r2(A, B, C, D);
    Rectangle r3;

    if (!(r1 == r2))
        return false;
    if (r1 == r3)
        return false;

    return true;
}

bool testInequalityOperatorRectangle()
{
    Point A1(0, 0), B1(0, 2), C1(3, 2), D1(3, 0);
    Point A2(0, 0), B2(0, 4), C2(3, 4), D2(3, 0);
    Rectangle r1(A1, B1, C1, D1);
    Rectangle r2(A2, B2, C2, D2);

    if (!(r1 != r2))
        return false;

    return true;
}

// Function to test circle constructors and methods

bool testCircleConstructors()
{
    Circle c1;
    Point p(0, 0);
    Circle c2(p, 5.0);
    Circle c3(c2);

    if (!(c1.getO() == Point(0, 0) && c1.getr() == 1))
        return false;
    if (!(c2.getO() == p && c2.getr() - 5.0 < 1e-5))
        return false;
    if (!(c3.getO() == p && c3.getr() - 5.0 < 1e-5))
        return false;

    return true;
}

bool testSetCircle()
{
    Circle c;
    Point p(3, 4);
    c.set_circle(p, 6.0);

    if (c.getO() != p || c.getr() != 6.0)
        return false;

    return true;
}

bool testPerimeterCircle()
{
    Circle c(Point(0, 0), 5.0);

    if (abs(c.perimeter() - 2 * M_PI * 5.0) > 1e-5)
        return false;

    return true;
}

bool testAreaCircle()
{
    Circle c(Point(0, 0), 5.0);

    if (abs(c.area() - M_PI * 25.0) > 1e-5)
        return false;

    return true;
}

bool testBelongCircle()
{
    Circle c(Point(0, 0), 5.0);
    Point p(3, 4);

    if (!c.belong(p))
        return false;

    return true;
}

bool testIsInsideCircle()
{
    Circle c(Point(0, 0), 5.0);
    Point p(1, 1);

    if (!c.is_inside(p))
        return false;

    return true;
}

bool testIsIntersectCircle()
{
    Circle c1(Point(0, 0), 5.0);
    Circle c2(Point(6, 0), 5.0);

    if (!c1.is_intersect(c2))
        return false;

    return true;
}

bool testIsSeparableCircle()
{
    Circle c1(Point(0, 0), 5.0);
    Circle c2(Point(15, 0), 5.0);

    if (!c1.is_separable(c2))
        return false;

    return true;
}

bool testIsTangentCircle()
{
    Circle c1(Point(0, 0), 5.0);
    Circle c2(Point(10, 0), 5.0);

    if (!c1.is_tangent(c2))
        return false;

    return true;
}

bool testTangentLineCircle()
{
    Point S(4, -2);
    Point A(2, -1);
    Circle c(S, length_g(S, A));
    Line l = c.tangent_line(A);
    Line ans(2, -5);
    if (!(l == ans))
        return false;

    return true;
}

bool testEqualityOperatorCircle()
{
    Circle c1(Point(0, 0), 5.0);
    Circle c2(Point(0, 0), 5.0);

    if (!(c1 == c2))
        return false;

    return true;
}

bool testInequalityOperatorCircle()
{
    Circle c1(Point(0, 0), 5.0);
    Circle c2(Point(1, 1), 5.0);

    if (!(c1 != c2))
        return false;

    return true;
}

// Function to test circle constructors and methods

bool testLineConstructors()
{
    Line l1;
    Line l2(2.0, 3.0);
    Point A(0, 0), B(1, 1);
    Line l3(A, B);
    Line l4(Vector(1, 1));
    Line l5(Segment(A, B));
    Line l6(l2);

    if (!(l1.geta() == 1 && l1.getb() == 0))
        return false;

    if (!(l2.geta() == 2.0 && l2.getb() == 3.0))
        return false;
    if (abs(l3.geta() - 1.0) > 1e-5 || l3.getb() != 0)
        return false;
    if (!(abs(l4.geta() - 1.0) < 1e-5 && l4.getb() == 0))
        return false;
    if (!(abs(l5.geta() - 1.0) < 1e-5 && l5.getb() == 0))
        return false;
    if (!(l6.geta() == 2.0 && l6.getb() == 3.0))
        return false;

    return true;
}

bool testSetLine()
{
    Line l;
    l.set_Line(1.0, 2.0);

    if (l.geta() != 1.0 || l.getb() != 2.0)
        return false;

    return true;
}

bool testTranslateLine()
{
    Line l(3.0, 2.0);
    Vector v(2, -3);
    l.translate(v);
    Line ans(3, -7);

    if (!(l == ans))
        return false;

    return true;
}

bool testValueAt()
{
    Line l(2.0, 3.0);

    if (abs(l.value_at(1.0) - 5.0) > 1e-5)
        return false;

    return true;
}

bool testZeroOfFun()
{
    Line l(2.0, -4.0);

    if (abs(l.zero_of_fun(0.0) - 2.0) > 1e-5)
        return false;

    return true;
}

bool testBelong()
{
    Line l(1.0, 0);
    Point p(1, 1);

    if (!l.belong(p))
        return false;

    return true;
}

bool testIsParallel()
{
    Line l1(1.0, 2.0);
    Line l2(1.0, -3.0);

    if (!l1.is_parallel(l2))
        return false;

    return true;
}

bool testIsPerpendicular()
{
    Line l1(1.0, 0);
    Line l2(-1.0, 0);

    if (!l1.is_perpendicular(l2))
        return false;

    return true;
}

bool testPerpendicularAt()
{
    Line l(1.0, 0);
    Point p(1, 1);
    Line perp = l.perpendicular_at(p);

    if (abs(perp.geta() + 1.0) > 1e-5 || abs(perp.getb() - 2.0) > 1e-5)
        return false;

    return true;
}

bool testEqualityOperatorLine()
{
    Line l1(1.0, 2.0);
    Line l2(1.0, 2.0);

    if (!(l1 == l2))
        return false;

    return true;
}

bool testInequalityOperatorLine()
{
    Line l1(1.0, 2.0);
    Line l2(1.0, 3.0);

    if (!(l1 != l2))
        return false;

    return true;
}

int main()
{

    if (!testVectorConstructors())
        std::cout << "Vector testVectorConstructors false 1" << '\n';
    if (!testSetVector())
        std::cout << "Vector testSetVector false 2" << '\n';
    if (!testGetX())
        std::cout << "Vector testGetX false 3" << '\n';
    if (!testGetY())
        std::cout << "Vector testGetY false 4" << '\n';
    if (!testLength())
        std::cout << "Vector testLength false 5" << '\n';
    if (!testEqualityOperator())
        std::cout << "Vector testEqualityOperator false 6" << '\n';
    if (!testInequalityOperator())
        std::cout << "Vector testInequalityOperator false 7" << '\n';
    if (!testAdditionOperator())
        std::cout << "Vector testAdditionOperator false 8" << '\n';
    if (!testSubtractionOperator())
        std::cout << "Vector testSubtractionOperator false 9" << '\n';
    if (!testScalarMultiplicationOperator())
        std::cout << "Vector testScalarMultiplicationOperator false 10" << '\n';
    if (!testDotProductOperator())
        std::cout << "Vector testDotProductOperator false 11" << '\n';
    if (!testAdditionAssignmentOperator())
        std::cout << "Vector testAdditionAssignmentOperator false 12" << '\n';
    if (!testSubtractionAssignmentOperator())
        std::cout << "Vector testSubtractionAssignmentOperator false 13" << '\n';
    if (!testScalarMultiplicationAssignmentOperator())
        std::cout << "Vector testScalarMultiplicationAssignmentOperator false 14" << '\n';

    if (!testPointConstructors())
        std::cout << "Point testPointConstructors false 1" << '\n';
    if (!testSetPoint())
        std::cout << "Point testSetPoint false 2" << '\n';
    if (!testGetXPoint())
        std::cout << "Point testGetXPoint false 3" << '\n';
    if (!testGetYPoint())
        std::cout << "Point testGetYPoint false 4" << '\n';
    if (!testTranslatePoint())
        std::cout << "Point testTranslatePoint false 5" << '\n';
    if (!testSymmetry())
        std::cout << "Point testSymmetry false 6" << '\n';
    if (!testEqualityOperatorPoint())
        std::cout << "Point testEqualityOperatorPoint false 7" << '\n';
    if (!testInequalityOperatorPoint())
        std::cout << "Point testInequalityOperatorPoint false 8" << '\n';

    if (!testSegmentDefaultConstructor())
        std::cout << "Segment testSegmentDefaultConstructor false 1" << '\n';
    if (!testSegmentCopyConstructor())
        std::cout << "Segment testSegmentCopyConstructor false 2" << '\n';
    if (!testSegmentPointConstructor())
        std::cout << "Segment testSegmentPointConstructor false 3" << '\n';
    if (!testSegmentVectorConstructor())
        std::cout << "Segment testSegmentVectorConstructor false 4" << '\n';
    if (!testSetSegment())
        std::cout << "Segment testSetSegment false 5" << '\n';
    if (!testLengthSegment())
        std::cout << "Segment testLengthSegment false 6" << '\n';
    if (!testParallelSegment())
        std::cout << "Segment testParallelSegment false 7" << '\n';
    if (!testPerpendicularSegment())
        std::cout << "Segment testPerpendicularSegment false 8" << '\n';
    if (!testBelongSegment())
        std::cout << "Segment testBelongSegment false 9" << '\n';
    if (!testIntersectSegment())
        std::cout << "Segment testIntersectSegment false 10" << '\n';
    if (!testEqualityOperatorSegment())
        std::cout << "Segment testEqualityOperatorSegment false 11" << '\n';
    if (!testInequalityOperatorSegment())
        std::cout << "Segment testInequalityOperatorSegment false 12" << '\n';

    if (!testTriangleDefaultConstructor())
        std::cout << "Triangle testTriangleDefaultConstructor false 1" << '\n';
    if (!testTriangleCopyConstructor())
        std::cout << "Triangle testTriangleCopyConstructor false 2" << '\n';
    if (!testTrianglePointConstructor())
        std::cout << "Triangle testTrianglePointConstructor false 3" << '\n';
    if (!testSetTriangle())
        std::cout << "Triangle testSetTriangle false 4" << '\n';
    if (!testPerimeter())
        std::cout << "Triangle testPerimeter false 5" << '\n';
    if (!testArea())
        std::cout << "Triangle testArea false 6" << '\n';
    if (!testIsInside())
        std::cout << "Triangle testIsInside false 7" << '\n';
    if (!testIsRightAngled())
        std::cout << "Triangle testIsRightAngled false 8" << '\n';
    if (!testIsAcuteAngled())
        std::cout << "Triangle testIsAcuteAngled false 9" << '\n';
    if (!testIsObtuseAngled())
        std::cout << "Triangle testIsObtuseAngled false 10" << '\n';
    if (!testIncircle())
        std::cout << "Triangle testIncircle false 11" << '\n';
    if (!testCircumcircle())
        std::cout << "Triangle testCircumcircle false 12" << '\n';
    if (!testEqualityOperatorTriangle())
        std::cout << "Triangle testEqualityOperatorTriangle false 13" << '\n';
    if (!testInequalityOperatorTriangle())
        std::cout << "Triangle testInequalityOperatorTriangle false 14" << '\n';

    if (!testSquareDefaultConstructor())
        std::cout << "Square testSquareDefaultConstructor false 1" << '\n';
    if (!testSquareCopyConstructor())
        std::cout << "Square testSquareCopyConstructor false 2" << '\n';
    if (!testSquarePointConstructor())
        std::cout << "Square testSquarePointConstructor false 3" << '\n';
    if (!testSetSquare())
        std::cout << "Square testSetSquare false 4" << '\n';
    if (!testPerimeterSquare())
        std::cout << "Square testPerimeterSquare false 5" << '\n';
    if (!testAreaSquare())
        std::cout << "Square testAreaSquare false 6" << '\n';
    if (!testInsideSquare())
        std::cout << "Square testInsideSquare false 7" << '\n';
    if (!testEqualityOperatorSquare())
        std::cout << "Square testEqualityOperatorSquare false 8" << '\n';
    if (!testInequalityOperatorSquare())
        std::cout << "Square testInequalityOperatorSquare false 9" << '\n';

    if (!testRectangleConstructors())
        std::cout << "Rectangle testRectangleConstructors false 1" << '\n';
    if (!testSetRectangle())
        std::cout << "Rectangle testSetRectangle false 2" << '\n';
    if (!testPerimeterRectangle())
        std::cout << "Rectangle testPerimeterRectangle false 3" << '\n';
    if (!testAreaRectangle())
        std::cout << "Rectangle testAreaRectangle false 4" << '\n';
    if (!testInsideRectangle())
        std::cout << "Rectangle testInsideRectangle false 5" << '\n';
    if (!testIsSquare())
        std::cout << "Rectangle testIsSquare false 6" << '\n';
    if (!testEqualityOperatorRectangle())
        std::cout << "Rectangle testEqualityOperatorRectangle false 7" << '\n';
    if (!testInequalityOperatorRectangle())
        std::cout << "Rectangle testInequalityOperatorRectangle false 8" << '\n';

    if (!testCircleConstructors())
        std::cout << "Circle testCircleConstructors false" << '\n';
    if (!testSetCircle())
        std::cout << "Circle testSetCircle false" << '\n';
    if (!testPerimeterCircle())
        std::cout << "Circle testPerimeterCircle false" << '\n';
    if (!testAreaCircle())
        std::cout << "Circle testAreaCircle false" << '\n';
    if (!testBelongCircle())
        std::cout << "Circle testBelongCircle false" << '\n';
    if (!testIsInsideCircle())
        std::cout << "Circle testIsInsideCircle false" << '\n';
    if (!testIsIntersectCircle())
        std::cout << "Circle testIsIntersectCircle false" << '\n';
    if (!testIsSeparableCircle())
        std::cout << "Circle testIsSeparableCircle false" << '\n';

    if (!testIsTangentCircle())
        std::cout << "Circle testIsTangentCircle false" << '\n';

    if (!testTangentLineCircle())
        std::cout << "Circle testTangentLineCircle false" << '\n';
    if (!testEqualityOperatorCircle())
        std::cout << "Circle testEqualityOperatorCircle false" << '\n';
    if (!testInequalityOperatorCircle())
        std::cout << "Circle testInequalityOperatorCircle false" << '\n';

    if (!testLineConstructors())
        std::cout << "Line testLineConstructors false" << '\n';
    if (!testSetLine())
        std::cout << "Line testSetLine false" << '\n';

    if (!testTranslateLine())
        std::cout << "Line testTranslateLine false" << '\n';

    if (!testValueAt())
        std::cout << "Line testValueAt false" << '\n';
    if (!testZeroOfFun())
        std::cout << "Line testZeroOfFun false" << '\n';
    if (!testBelong())
        std::cout << "Line testBelong false" << '\n';
    if (!testIsParallel())
        std::cout << "Line testIsParallel false" << '\n';
    if (!testIsPerpendicular())
        std::cout << "Line testIsPerpendicular false" << '\n';
    if (!testPerpendicularAt())
        std::cout << "Line testPerpendicularAt false" << '\n';
    if (!testEqualityOperatorLine())
        std::cout << "Line testEqualityOperatorLine false" << '\n';
    if (!testInequalityOperatorLine())
        std::cout << "Line testInequalityOperatorLine false" << '\n';

    return 0;
}