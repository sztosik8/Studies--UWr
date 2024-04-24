#include "functions.hpp"

double length(Point a, Point b)
{
    double x = a.getX() - b.getX();
    double y = a.getY() - b.getY();
    return sqrt(x * x + y * y);
}

double pole_g(Point a, Point b, Point c)
{
    double p = 0.5 * abs((b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX()));
    return p;
}
bool parallel(Segment a, Segment b)
{
    double a1 = (a.geta().getY() - a.getb().getY()) / (a.geta().getX() - a.getb().getX());
    double a2 = (b.geta().getY() - b.getb().getY()) / (b.geta().getX() - b.getb().getX());

    if (a1 == a2)
        return true;
    else
        return false;
}
bool perpendicular(Segment a, Segment b)
{
    double a1 = (a.geta().getY() - a.getb().getY()) / (a.geta().getX() - a.getb().getX());
    double a2 = (b.geta().getY() - b.getb().getY()) / (b.geta().getX() - b.getb().getX());

    if (a1 * a2 == (-1))
        return true;
    else
        return false;
}
bool one_in_another(Triangle a, Triangle b)
{
    Point x;
    x = b.geta();
    Point y;
    y = b.getb();
    Point z;
    z = b.getc();
    Point d;
    d = a.geta();
    Point e;
    e = a.getb();
    Point f;
    f = a.getc();
    if (a.inside(x) and a.inside(y) and a.inside(z))
        return true;
    else if (b.inside(d) and b.inside(e) and b.inside(f))
        return true;
    else
        return false;
}

bool separable(Triangle a, Triangle b)
{
    Point x;
    x = b.geta();
    Point y;
    y = b.getb();
    Point z;
    z = b.getc();
    Point d;
    d = a.geta();
    Point e;
    e = a.getb();
    Point f;
    f = a.getc();
    bool in = (a.inside(x) or a.inside(y) or a.inside(z) or b.inside(d) or b.inside(e) or b.inside(f));
    // in = true if at least one point is inside,  NOT SEPARABLE -> 0
    // in = false if no point is inside,  SEPARABLE -> 1

    if (!in)
    {
        Segment s1 = Segment();
        s1.set_segment(d, e);
        Segment s2 = Segment();
        s2.set_segment(e, f);
        Segment s3 = Segment();
        s3.set_segment(f, d);

        Segment z1 = Segment();
        z1.set_segment(x, y);
        Segment z2 = Segment();
        z2.set_segment(y, z);
        Segment z3 = Segment();
        z3.set_segment(z, x);

        bool c = (cross(s1, z1) or cross(s1, z2) or cross(s1, z3) or
                  cross(s2, z1) or cross(s2, z2) or cross(s2, z3) or
                  cross(s3, z1) or cross(s3, z2) or cross(s3, z3));
        // c = true if at least one pair of segments crosses each other,  NOT SEPARABLE -> 0
        // c = false if no pair crosses each other,   SEPARABLE -> 1
        return not c;
    }
    return not in;
}

bool cross(Segment a, Segment b)
{
    // Find the four orientations needed for general and
    // special cases
    Point p1 = a.geta();
    Point q1 = a.getb();
    Point p2 = b.geta();
    Point q2 = b.getb();

    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;

    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;

    // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false; // Doesn't fall in any of the above cases
}
int orientation(Point p, Point q, Point r)
{

    int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) -
              (q.getX() - p.getX()) * (r.getY() - q.getY());

    if (val == 0)
        return 0; // collinear

    return (val > 0) ? 1 : 2; // clock or counterclock wise
}
bool onSegment(Point p, Point q, Point r)
{
    if (q.getX() <= max(p.getX(), r.getX()) && q.getX() >= min(p.getX(), r.getX()) &&
        q.getY() <= max(p.getY(), r.getY()) && q.getY() >= min(p.getY(), r.getY()))
        return true;

    return false;
}