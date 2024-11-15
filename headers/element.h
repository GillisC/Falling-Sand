#pragma once 

#include <SDL.h>
#include "color.h"

class Grid;

// Base class for all elements
class Element {
  public:

    Element(int red, int green, int blue)
        : r(red), g(green), b(blue) {}


    virtual void update(Grid& grid, int x, int y) = 0;
    virtual void display(SDL_Renderer* renderer, int x, int y) const = 0;

    int getRed() const { return r; }
    int getGreen() const { return g; }
    int getBlue() const { return b; }

    virtual ~Element() = default;

  private:
    int r;
    int g;
    int b;
};

