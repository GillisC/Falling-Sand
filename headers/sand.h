#pragma once

#include <SDL.h>

#include "element.h"
#include "grid.h"

class Grid;

class Sand : public Element {
  public:
    Sand();
    void update(Grid& grid, int x, int y) override;
    void display(SDL_Renderer* renderer, int x, int y) const override;
};