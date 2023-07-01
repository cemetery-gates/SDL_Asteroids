#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <ostream>
#include <cmath>

#include "SDL_Plotter.h"

class point_t{
    private:
        double x, y;
        color c;
        int size;

    public:
        point_t(double=0, double=0);

        void setX(double);
        void setY(double);
        void setColor(color);
        void setSize(int);

        double getX() const;
        double getY() const;
        color getColor() const;
        int getSize() const;

        void draw(ostream&);
        void draw(SDL_Plotter&);

        point_t add(const point_t&) const;
        point_t operator+(const point_t& p) const{
            return add(p);
        }
        double distance(point_t p){
            return sqrt(pow(x- p.x,2) + pow(y - p.y, 2));
        }

};

#endif // POINT_H_INCLUDED
