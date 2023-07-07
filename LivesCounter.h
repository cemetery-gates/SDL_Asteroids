#ifndef LIVESCOUNTER_H
#define LIVESCOUNTER_H

#include <string>
#include "SDL_Plotter.h"

class LivesCounter {
public:
    LivesCounter(SDL_Plotter& g);
    void updateLives(int newLives);
    void render(SDL_Plotter& g) const;

private:
    int lives;
    SDL_Plotter& plotter;
};

#endif  // LIVESCOUNTER_H
