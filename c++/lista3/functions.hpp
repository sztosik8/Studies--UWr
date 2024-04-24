#ifndef UNTITLED1_EXTRA_FUNCTIONS_H
#define UNTITLED1_EXTRA_FUNCTIONS_H
#include <cmath>
#include <exception>
#include <iostream>
#include "classes.hpp"

double length(Point a, Point b);
double pole_g(Point a, Point b, Point c);
bool parallel(Segment a, Segment b);
bool perpendicular(Segment a, Segment b);
bool one_in_another(Triangle a, Triangle b);
bool separable(Triangle a, Triangle b);
bool cross(Segment a, Segment b);
int orientation(Point p, Point q, Point r);
bool onSegment(Point p, Point q, Point r);

#endif