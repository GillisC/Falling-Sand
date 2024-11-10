#pragma once

#include <vector>
#include <memory>
#include "element.h"

class Grid {
public:
    // Constructor
    Grid(int width, int height);

    // Clears the grid
    void clear();

    // Sets an element at a specific position
    void set(int x, int y, std::shared_ptr<Element> element);

    // Swaps elements between two positions
    void swap(int x1, int y1, int x2, int y2);

    // Checks if a cell is empty
    bool isEmpty(int x, int y);

    std::string toString() const;

private:
    int width, height;
    std::vector<std::vector<std::shared_ptr<Element>>> grid;

    // Checks if coordinates are within bounds
    bool isInBounds(int x, int y) const;
};