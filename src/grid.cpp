#include <iostream>
#include "grid.h"

Grid::Grid(int w, int h) 
    : width(w), height(h), grid(height, std::vector<std::shared_ptr<Element>>(width, nullptr)) {}


// Clears the grid
void Grid::clear() {
    grid.assign(height, std::vector<std::shared_ptr<Element>>(width, nullptr));
}

void Grid::set(int x, int y, std::shared_ptr<Element> element) {
    if (isInBounds(x, y)) {
        grid[y][x] = element;
    } else {
        std::cerr << "Out of bounds, trying to insert element into: (" << x << ", " << y << ")" << std::endl;
    }
}

void Grid::swap(int x1, int y1, int x2, int y2) {
    if (isInBounds(x1, y1) && isInBounds(x2, y2)) {
        auto temp = grid[y1][x1];
        grid[y1][x1] = grid[y2][x2];
        grid[y2][x2] = temp;
    } else {
        std::cerr << "Out of bounds, trying to swap element: (" << x1 << ", " << y1 << ")" << "with (" << x2 << ", " << y2 << ")" << std::endl;
    }
}

bool Grid::isEmpty(int x, int y) {
    if (isInBounds(x, y)) {
        if (grid[y][x] == nullptr) {
            return true;
        } else return false;
    } else {
        std::cerr << "Out of bounds, trying to check if cell is empty at: (" << x << ", " << y << ")" << std::endl;
    }
}

std::string Grid::toString() const {
    return "Grid(width=" + std::to_string(width) + ", height=" + std::to_string(height) + ")";
}

bool Grid::isInBounds(int x, int y) const {
    return x>=0 && x<=width && y>=0 && y<=height;
}
