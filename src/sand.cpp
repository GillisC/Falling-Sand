#include <SDL.h>

#include <iostream>
#include "sand.h"
#include "color.h"

Sand::Sand() 
    : Element(
          varyColor(255), 
          varyColor(204),  
          varyColor(0)     
      ) {}

void Sand::update(Grid& grid, int x, int y) {
    // Below
    if (y + 1 < grid.getHeight() && grid.isEmpty(x, y + 1)) {
        grid.swap(x, y, x, y+1);
    }
    // Below left
    else if (x - 1 >= 0 && y + 1 < grid.getHeight() && grid.isEmpty(x - 1, y + 1)) {
        grid.swap(x, y, x-1, y+1);
    } 
    // Below right
    else if (x + 1 >= 0 && y + 1 < grid.getHeight() && grid.isEmpty(x + 1, y + 1)) {
        grid.swap(x, y, x+1, y+1);
    } 
}

void Sand::display(SDL_Renderer* renderer, int x, int y) const {
    SDL_SetRenderDrawColor(renderer, getRed(), getGreen(), getBlue(), 255);
    SDL_RenderDrawPoint(renderer, x, y);
}   
