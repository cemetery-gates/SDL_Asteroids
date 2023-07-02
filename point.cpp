#include "point.h"

point_t::point_t(double x, double y){
    this-> x = x;
    this-> y = y;
    size = 1;
}

void point_t::setX(double x){
    this-> x = x;
}

void point_t::setY(double y){
    this-> y = y;
}
void point_t::setColor(color c){
    this-> c = c;
}
void point_t::setSize(int n){
    if(n >= 1){
        size = n;
    }
}

double point_t::getX() const{
    return x;
}

double point_t::getY() const{
    return y;
}

color point_t::getColor() const{
    return c;
}

int point_t::getSize() const{
    return size;
}



void point_t::draw(ostream& output){
    output << "(" << x << ", " << y << ")";
}

void point_t::draw(SDL_Plotter& g){
    for(int r=0; r<size; r++){
        for(int c=0; c<size; c++){
            g.plotPixel(x+c,y+r,this->c);
        }
    }
}

point_t point_t::add(const point_t& p) const{
    point_t p3;
    p3.setX(getX() + p.getX());
    p3.setY(getY() + p.getY());

    p3.setSize(getSize() + p.getSize());
    p3.setColor(color(c.R + p.c.R, c.G + p.c.G, c.B + p.c.B));

    return p3;
}
