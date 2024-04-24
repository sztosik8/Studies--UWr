/*
Katarzyna Trzos
Lista 3
Kurs C++
Kompilacja bash make.sh
*/

#include "classes.hpp"
#include "functions.hpp"

using namespace std;

int main()
{
    Point A = Point();
    Point B = Point();
    Point C = Point();
    Point D = Point();

    A.set_point(-3.8, 67);
    cout << "Point A = ";
    A.Print();
    cout << '\n';
    cout << '\n';

    Vector v = Vector();
    v.set_vector(3, 2);

    A.translate(v);
    cout << "point A translated by a vector (3, 2): ";
    A.Print();
    cout << '\n';
    cout << '\n';
    cout << "----------------------------------------------------------------" << '\n';

    Point zero = Point();
    zero.set_point(0, 0);
    cout << "A = ";
    A.Print();
    cout << '\n';
    cout << "wektor ";
    zero.Print();
    cout << '\n';
    A.rotate(zero, 180);
    cout << "A obrocony  ";
    A.Print();
    cout << "----------------------------------------------------------------" << '\n';

    // ----------- SEGMENT ---------------
    B.set_point(6.0, -2.0);
    Segment AB;
    Segment CD;
    AB.set_segment(A, B);
    cout << "Segment AB: ";
    AB.Print();
    cout << '\n';

    Segment BA = Segment(AB);
    cout << "segment AB copied to Segment BA : ";
    BA.Print();
    cout << '\n';

    BA.rotate(zero, 180);
    cout << "Segment BA rotate by 180 degrees about point (0, 0) : ";
    BA.Print();
    cout << '\n';

    Straight s = Straight();
    s.set_straight(2, 3, 4);
    AB.symmetry(s);

    cout << "Symmetry along 2x + 3y + 4 = 0 : ";
    AB.Print();
    cout << "\n";
    cout << "----------------------------------------------------------------" << '\n';

    A.set_point(4.0, 0.0);
    B.set_point(0, 3);

    cout << "New segment AB : ";

    AB.set_segment(A, B);
    AB.Print();

    cout << "Length of AB : ";
    cout << AB.length_s();
    cout << '\n';

    cout << "AB after translation : ";
    AB.translate(v);
    AB.Print();

    cout << "Length of AB : ";
    cout << AB.length_s();
    cout << '\n'
         << '\n';

    cout << "----------------------------------------------------------------" << '\n';
    A.set_point(1, 5);
    B.set_point(5, 2);
    AB.set_segment(A, B);
    C.set_point(5, 5);
    D.set_point(8, 9);
    CD.set_segment(C, D);
    cout << "Segment AB : ";
    AB.Print();
    cout << '\n';
    cout << "Segment CD : ";
    CD.Print();
    cout << '\n';
    cout << "Are segments AB and CD pararel? : ";
    cout << parallel(AB, CD) << '\n';
    cout << "Are segments AB and CD perpendicular ? : ";
    cout << perpendicular(AB, CD) << '\n';
    cout << "----------------------------------------------------------------" << '\n';

    CD = Segment(AB);
    v.set_vector(-3.5, 12);
    CD.translate(v);
    cout << "Segment AB : ";
    AB.Print();
    cout << '\n';
    cout << "Segment CD : ";
    CD.Print();
    cout << '\n';
    cout << "Are segments AB and CD pararel? : ";
    cout << parallel(AB, CD) << '\n';
    cout << "Are segments AB and CD perpendicular ? : ";
    cout << perpendicular(AB, CD) << '\n';

    cout << "----------------------------------------------------------------" << '\n';
    A.set_point(4.0, 4.0);
    B.set_point(12.0, 12.0);
    AB.set_segment(A, B);
    cout << "Segment AB : ";
    AB.Print();
    cout << '\n';
    C.set_point(5.0, 5.0);
    D.set_point(13, 13);

    cout << "Does point C=(5, 5) belongs to the segment AB? ";
    cout << AB.belong(C) << '\n';

    cout << "Does point D=(13, 13) belongs to the segment AB? ";
    cout << AB.belong(D) << '\n';

    // ----------- TRIANGLE ---------------

    cout << "----------------------------------------------------------------" << '\n';
    Triangle ABC = Triangle();
    A.set_point(0, 4);
    B.set_point(3, 0);
    C.set_point(0, 0);

    ABC.set_triangle(A, B, C);

    cout << "Triangle ABC : ";
    ABC.Print();

    cout << "Area of ABC : " << ABC.area() << '\n';
    cout << "Perimeter of ABC : " << ABC.perimeter() << '\n';

    cout << "----------------------------------------------------------------" << '\n';

    Triangle DEF = Triangle(ABC);
    v.set_vector(1, 2);
    ABC.translate(v);
    cout << "Triangle ABC : ";
    ABC.Print();
    cout << "Triangle DEF : ";
    DEF.Print();
    cout << "Are ABC and DEF separable ? ";
    cout << separable(ABC, DEF);
    cout << '\n'
         << '\n';
    cout << "----------------------------------------------------------------" << '\n';
    ABC.symmetry(s);
    cout << "Triangle ABC after x symmetry : ";
    ABC.Print();
    cout << "Triangle DEF : ";
    DEF.Print();
    cout << "Are ABC and DEF separable ? ";
    cout << separable(ABC, DEF);
    cout << '\n';

    cout << "----------------------------------------------------------------" << '\n';
    cout << "Triangle DEF : ";
    DEF.Print();
    A.set_point(0.12, 0.1);
    B.set_point(-1, 1);

    cout << "Point A : ";
    A.Print();
    cout << '\n'
         << "Point B : ";
    B.Print();
    cout << '\n';

    cout << "Does point A is inside Triangle DEF? : ";
    cout << DEF.inside(A) << '\n';

    cout << "Does point B is inside Triangle DEF? : ";
    cout << DEF.inside(B) << '\n';
    cout << "----------------------------------------------------------------" << '\n';

    A.set_point(0, 10);
    B.set_point(0, 0);
    C.set_point(15, 0);
    ABC.set_triangle(A, B, C);

    A.set_point(2, 3);
    B.set_point(2, 2);
    C.set_point(4, 2);
    DEF.set_triangle(A, B, C);

    cout << "Triangle ABC : ";
    ABC.Print();
    cout << "Triangle DEF : ";
    DEF.Print();
    cout << "Is triangle DEF inside ABC ? ";
    cout << one_in_another(ABC, DEF) << '\n';

    cout << "----------------------------------------------------------------" << '\n';

    cout << "Triangle ABC : ";
    ABC.Print();
    cout << "Triangle DEF : ";
    DEF.Print();
    DEF.symmetry(s);
    cout << "Is triangle ABC inside DEF ? ";
    cout << one_in_another(DEF, ABC) << '\n';

    cout << "----------------------------------------------------------------" << '\n';

    A.set_point(3, 3);
    B.set_point(9, 9);
    C.set_point(-23, -23);
    cout << "Triangle from collinear Points : ";
    ABC.set_triangle(A, B, C);

    cout << '\n';

    cout << "----------------------------------------------------------------" << '\n';
    A.set_point(1, 3);
    B.set_point(6, 3);
    C.set_point(3, 6);
    ABC.set_triangle(A, B, C);
    A.set_point(3, 2);
    B.set_point(5, 5);
    C.set_point(1, 6);
    DEF.set_triangle(A, B, C);

    cout << "Triangle ABC : ";
    ABC.Print();
    cout << "Triangle DEF : ";
    DEF.Print();
    cout << "Are ABC and DEF separable ? ";
    cout << separable(ABC, DEF);
    cout << '\n';

    cout << "----------------------------------------------------------------" << '\n';

    A.set_point(0, 10);
    B.set_point(0, 0);
    C.set_point(10, 0);
    ABC.set_triangle(A, B, C);
    A.set_point(1, 2);
    B.set_point(1, 4);
    C.set_point(2, 3);
    DEF.set_triangle(A, B, C);

    cout << "Triangle ABC : ";
    ABC.Print();
    cout << "Triangle DEF : ";
    DEF.Print();
    cout << "Are ABC and DEF separable ? ";
    cout << separable(ABC, DEF);
    cout << '\n';
    cout << "----------------------------------------------------------------" << '\n';

    C.set_point(2, 100);
    DEF.set_triangle(A, B, C);
    cout << "Triangle ABC : ";
    ABC.Print();
    cout << "Triangle DEF : ";
    DEF.Print();
    cout << "Are ABC and DEF separable ? ";
    cout << separable(ABC, DEF);
    cout << '\n';
}