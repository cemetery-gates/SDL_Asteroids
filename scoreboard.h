#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string>
#include "SDL_Plotter.h"

class Scoreboard {
public:
    Scoreboard(SDL_Plotter& g);
    void updateScore(int newScore);
    void render(SDL_Plotter& g) const;

private:
    int score;
    SDL_Plotter& plotter;
};


#endif  // SCOREBOARD_H
