#ifndef FORCE_H_INCLUDED
#define FORCE_H_INCLUDED

#include <cmath>
#include <ostream>
#include "constants.h"

using namespace std;

class force{
    private:
        double magnitude;
        double direction; //radians
    public:
        force();
        force(double m, double d);

        void setMagnitude(double);
        void setDirection(double);

        double getMagnitude() const;
        double getDirection() const;

        force add(const force&) const;
        force operator+ (const force& f) const;

        force operator= (const force&);
        void apply(const force&);

        void display(ostream&) const;

};

#endif // FORCE_H_INCLUDED
