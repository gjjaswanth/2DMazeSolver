#include "classes.h"
// Implementation of Path Traversal

// Constructor: stores pointers to maze and path
// Starts at position top left corner
Path_Traversal::Path_Traversal(Maze_2D* m, Path_1D* p)
    : maze(m), path(p), current_Location(0, 0), current_Step(0) {
    // Marks starting cell as visited
    visited_Points.push_back(current_Location);
}

// Checks if a given point has already been visited
bool Path_Traversal::is_Already_Visited(const Point_2D& p) const {
    for (int i = 0; i < (int)visited_Points.size(); i++) {
        if (visited_Points[i].equals(p)) return true;
    }
    return false;
}


// Traverse exactly one step of the path
// Updates current_Location, current_Step and visited_Points
// Throws exception if step is invalid
void Path_Traversal::traverse_One_Step() {

    int move = path->getMove(current_Step);
    // Calculates the next position based on move direction
    int new_Row = current_Location.getRow();
    int new_Col = current_Location.getCol();

    // Up=1 - row decreases
    // Down=3 - row increases
    // Right=2 - col increases
    // Left=4 - col decreases
    if      (move == 1) new_Row--;   
    else if (move == 2) new_Col++;   
    else if (move == 3) new_Row++;   
    else if (move == 4) new_Col--;   

    // Checks new position must be within maze boundaries
    if (!maze->is_Within_Bounds(new_Row, new_Col)) {
        //Figure out which edge was crossed for clear error message
        std::string edge;
        if  (new_Row < 0){
            edge = "top";
        }     
        else if(new_Row >= maze->getNumRows()) {
            edge = "bottom";
        }
        else if(new_Col < 0) {
            edge = "left";
        }
        else{
            edge = "right";
        }                                
        throw std::runtime_error(
            "-E-: Invalid path, taking it beyond the " + edge +
            " edge of the maze after " +
            std::to_string(current_Step + 1) + " steps."
        );
    }

    // Checks whether new position is a walkable cell
    if (!maze->is_Walkable(new_Row, new_Col)) {
        throw std::runtime_error(
            "-E-: Invalid path, visits an illegal cell (" +
            std::to_string(new_Col) + ", " + std::to_string(new_Row) +
            ") of the maze (origin being at top-left corner)."
        );
    }

    // Checks whether new position have been visited before or not
    Point_2D next_Point(new_Row, new_Col);
    if (is_Already_Visited(next_Point)) {
        throw std::runtime_error(
            "-E-: Invalid path, revisits a traversed path at coordinates (" +
            std::to_string(new_Row) + ", " + std::to_string(new_Col) +
            ") (origin being at top-left corner)."
        );
    }
    // updates the state when all checks are passed
    current_Location = next_Point;
    visited_Points.push_back(current_Location);
    current_Step++;
}

// Returns true if we are at bottom-right corner
bool Path_Traversal::has_Reached_End_Of_Maze() const {
    int lastRow = maze->getNumRows() - 1;
    int lastCol = maze->getNumCols() - 1;
    return (current_Location.getRow() == lastRow &&
            current_Location.getCol() == lastCol);
}

// Returns true if the next move in path is 0
bool Path_Traversal::has_Reached_End_Of_Path() const {
    if (current_Step >= path->getSize()) return true;
    return (path->getMove(current_Step) == 0);
}


//Accessors
int Path_Traversal::get_Current_Step() const { return current_Step; }
Point_2D Path_Traversal::get_Current_Location() const { return current_Location; }


// walks through the maze and prints the result
void Path_Traversal::simulate() {
    // Keeps walking until we reach end of the path and end of the maze
    while (!has_Reached_End_Of_Maze() && !has_Reached_End_Of_Path()) {
        traverse_One_Step();   
    }

    if (has_Reached_End_Of_Maze() && has_Reached_End_Of_Path()) {
        std::cout << "-I-: Path traversal completed successfully in "
                  << current_Step << " steps." << std::endl;
    }

    else if (has_Reached_End_Of_Path() && !has_Reached_End_Of_Maze()) {
        std::cout << "-I-: Invalid path. Reached end of path after "
                  << current_Step << " steps, "
                  << "but not reached the end of the maze yet!" << std::endl;
    }

    else if (has_Reached_End_Of_Maze() && !has_Reached_End_Of_Path()) {
        std::cout << "-I-: Invalid path. Reached end of maze after "
                  << current_Step << " steps, "
                  << "but path not complete yet!" << std::endl;
    }
}