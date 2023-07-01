#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <cmath>
#include "constants.h"
#include "point.h"
#include "SDL_Plotter.h"

using namespace std;

void drawLine(int, int, int, int, color c, SDL_Plotter& g);

void drawPoly(const point_t&, const vector<point_t>&, color, SDL_Plotter&);

bool hasSlope(int, int, int, int);

double slope(int, int, int, int);

double yIntercept(int, int, int, int);

#endif // GRAPHICS_H_INCLUDED
