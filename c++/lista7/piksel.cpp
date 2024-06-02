#include "piksel.h++"
#include <cmath>

piksel::piksel()
{
    this->x = 0;
    this->y = 0;
}

piksel::piksel(int x, int y)
{
    if (x < 0 or y < 0 or x > roz_x or y > roz_y)
        throw std::invalid_argument("Niepoprawne dane");
    this->x = x;
    this->y = y;
}

void piksel::set_x(int xx)
{
    if(x<0 || x>roz_x)
    throw std::invalid_argument("Niepoprawne dane");
    this->x = xx;
}
void piksel::set_y(int yy)
{
    if(y<0 || y>roz_y)
    throw std::invalid_argument("Niepoprawne dane");
    this->y = yy;
}

int piksel::get_up() { return roz_y - y; }

int piksel::get_down() { return y; }

int piksel::get_right() { return roz_x - x; }

int piksel::get_left() { return x; }

int piksel::get_x() { return x; }

int piksel::get_y() { return y; }

int piksel::odleglosc(piksel &p, piksel &q)
{
    return sqrt((p.get_x() - q.get_x()) * (p.get_x() - q.get_x()) + (p.get_y() - q.get_y()) * (p.get_y() - q.get_y()));
}

int piksel::odleglosc(piksel *p, piksel *q)
{
    return sqrt((p->get_x() - q->get_x()) * (p->get_x() - q->get_x()) + (p->get_y() - q->get_y()) * (p->get_y() - q->get_y()));
}