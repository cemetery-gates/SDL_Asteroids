#include "force.h"

force::force(){
    magnitude = 0;
    direction = 0;
}

force::force(double m, double d){
    magnitude = m;
    direction = d;
}

void force::setMagnitude(double m){
    magnitude = m;
}

void force::setDirection(double d){
    direction = d;
}

double force::getMagnitude() const{
    return magnitude;
}

double force::getDirection() const{
    return direction;
}

force force::add(const force& f) const{
    force v;

    double ax, ay, bx, by;
    double theta, mag;

    ax = getMagnitude() * cos(getDirection());
    ay = getMagnitude() * sin(getDirection());

    bx = f.getMagnitude() * cos(f.getDirection());
    by = f.getMagnitude() * sin(f.getDirection());

    theta = atan((ay + by)/(ax + bx));

    if((ay + by) < 0 && theta > 0) theta += PI;
    if((ay + by) > 0 && theta < 0) theta += PI;

    mag = sqrt(pow(ax + bx, 2) + pow(ay + by, 2));

    v.setMagnitude(mag);
    v.setDirection(theta);

    return v;
}

force force::operator+ (const force& f) const{
    return add(f);
}

void force::operator= (const force& f){
    setMagnitude(f.getMagnitude());
    setDirection(f.getDirection());
}

void force::apply(const force& f){
    *this = add(f);
}

void force::display(ostream& output) const{
    output << getMagnitude() << " " << getDirection() << endl;
}
