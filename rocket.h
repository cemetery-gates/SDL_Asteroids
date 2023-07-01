#ifndef ROCKET_H_INCLUDED
#define ROCKET_H_INCLUDED

#include <vector>

using namespace std;

#include "force.h"
#include "point.h"
#include "SDL_Plotter.h"
#include "constants.h"
#include "graphics.h"


class rocket{
    private:
        point_t loc, center;
        force f;
        color c;
        vector<point_t> shape;
        double direction = 0;

    public:
        rocket(){
            shape.push_back(point_t(0,0));
            shape.push_back(point_t(40,10));
            shape.push_back(point_t(0,20));
            shape.push_back(point_t(20,10));
            center.setX(20);
            center.setY(10);
            loc.setX(100);
            loc.setY(100);
            c = color(255,255,255);
        }

        void setLocation(const point&);
        point getLocation() const;

        void draw(SDL_Plotter& g){
        	drawPoly(loc, shape, c, g);
        }

        void erase(SDL_Plotter& g){
        	drawPoly(loc, shape, BG, g);
        }

        void movePoly(vector<int>& x, vector<int>& y, int px){
            for(int i=0; i < x.size(); i++){
                x[i] += px;
                y[i] += px;
            }
        }

        void setDirection(double d){
            direction = d;
            //rotatePolygonAtDistance(direction);
        }

        double getDirection() const{
            return direction;
        }

        void thrust(){
            force tForce(0.01, getDirection());
            f.apply(tForce);
        }

        void move(){
        	double newX = loc.getX() + f.getMagnitude() * cos(f.getDirection());
        	double newY = loc.getY() + f.getMagnitude() * sin(f.getDirection());

        	if(newX < 0) {
        		newX += COL;
        	}
        	else if(newX >= COL) {
        		newX -= COL;
        	}

        	if(newY < 0) {
        		newY += ROW;
        	}
        	else if(newY >= ROW){
        		newY -= ROW;
        	}

        	loc.setX(newX);
        	loc.setY(newY);
        }

        void rotatePolygonAtDistance(double theta) {

                    // Translate the polygon by (-cx, -cy) to bring the center to the origin
                    double cx = center.getX();
                    double cy = center.getY();

                    translatePolygon(-cx, -cy);
                    // Rotate the polygon at the origin
                    rotatePolygon(theta);
                    // Translate the polygon back to its original position
                    translatePolygon(cx, cy);
                    setDirection(getDirection() + theta);
        }

		void translatePolygon(double dx, double dy) {
			for (size_t i = 0; i < shape.size(); i++) {
				shape[i].setX(shape[i].getX() + dx);
				shape[i].setY(shape[i].getY() + dy);
			}
		}

		void rotatePolygon(double theta) {

			for (size_t i = 0; i < shape.size(); i++) {
				double x = shape[i].getX();
				double y = shape[i].getY();

				shape[i].setX(x * cos(theta) - y * sin(theta));
				shape[i].setY(x * sin(theta) + y * cos(theta));

			}
		}


};

#endif // ROCKET_H_INCLUDED
