#include "classes.h"
//Implementation of Point 2D
// Default constructor and point starts at top-left corner
Point_2D::Point_2D() : row(0), col(0) {}

// Parameterized constructor
Point_2D::Point_2D(int r, int c) : row(r), col(c) {}

// Mutators
void Point_2D::setRow(int r) { row = r; }
void Point_2D::setCol(int c) { col = c; }

// Accessors
int Point_2D::getRow() const { return row; }
int Point_2D::getCol() const { return col; }

// Checks if two points represents the same position
bool Point_2D::equals(const Point_2D& other) const {
    return (row == other.row && col == other.col);
}

// Prints the point as (row, col)
void Point_2D::display() const {
    std::cout << "(" << row << ", " << col << ")";
}
