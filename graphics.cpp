#include "graphics.h"

#include "point.h"

void drawLine(int x1, int y1, int x2, int y2, color c, SDL_Plotter& g){
    double m, b, y;
    if(hasSlope(x1,y1,x2,y2)){
        m = slope(x1,y1,x2,y2);
        b = yIntercept(x1,y1,x2,y2);
        for(double x = min(x1,x2); x <= max(x1,x2); x += STEP_SIZE){
            y = m * x + b;
            g.plotPixel(round(x),round(y),c);
        }
    }
    else{
        for(double y = min(y1,y2); y < max(y1,y2); y+= STEP_SIZE){
            g.plotPixel(x1,y,c);
        }
    }
}

void drawPoly(const point_t& loc, const vector<point_t>& shape, color c, SDL_Plotter& g) {
    for (size_t i = 0; i < shape.size(); i++) {
        int x1 = static_cast<int>(loc.getX() + shape[i].getX());
        int y1 = static_cast<int>(loc.getY() + shape[i].getY());
        int x2 = static_cast<int>(loc.getX() + shape[(i + 1) % shape.size()].getX());
        int y2 = static_cast<int>(loc.getY() + shape[(i + 1) % shape.size()].getY());

        drawLine(x1, y1, x2, y2, c, g);
    }
}

void movePoly(vector<int>& x, vector<int>& y, int px){
    for(int i=0; i < x.size(); i++){
        x[i] += px;
        y[i] += px;
    }
}

void drawCircle(point loc, int size, color c, SDL_Plotter& g){
	for(double i = -size; i <= size;i+=0.1){
		for(double j = -size; j <= size; j+=0.1){
			if(i*i + j*j <= size*size){
				g.plotPixel(round(loc.x+i),round(loc.y+j),c);
			}
		}
	}

}

bool hasSlope(int x1, int y1, int x2, int y2){
    return x1 != x2;
}

double slope(int x1, int y1, int x2, int y2){
    return static_cast<double>(y1 - y2)/(x1 - x2);
}

double yIntercept(int x1, int y1, int x2, int y2){
    return y1 - slope(x1,y1,x2,y2) *  x1;
}
