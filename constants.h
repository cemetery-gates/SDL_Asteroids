/*
* Author: Logan, Tanner, Emily
* Assignment Title: Group Project - Asteroids
* Assignment Description:
*     - This is the constants.h file which contains the constant values
*       for column size (COL), row size (ROW), the background color (BG)
*       and the Pi (PI)
* Due Date: 7/7/2023
* Date Created: 6/30/2023
* Date Last Modified: 7/1/2023
*/
#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include "SDL_Plotter.h"

const double STEP_SIZE = 0.01;
const int COL = 750;
const int ROW = 750;
const double PI = 3.141592653589793;
const color BG = {0,0,0};
const int MIN_VERTICES = 5;
const int MAX_VERTICES = 10;
const int MIN_SIZE = 20;
const int MAX_SIZE = 40;

#endif // CONSTANTS_H_INCLUDED
