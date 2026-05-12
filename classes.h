#ifndef CLASSES_H
#define CLASSES_H
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
// Initialized Non-Member Helper Functions, defined in Utilis.cpp

// Removes extra white spaces in a string
std::string trim_WhiteSpace(const std::string& line);

// Returns true if line is empty or starts with '#' 
bool comment_check(const std::string& line);

// Returns true if val is 0 or 1 
bool is_Valid_Maze_Entry(int val);

// Returns true if val is 0,1,2,3,4 
bool is_Valid_Path_Entry(int val);

// Responsible for converting integer to human-readable format
// 1=Up,2=Right,3=Down,4=Left,0=Stop
std::string move_To_String(int move);

//  Class: Point_2D
//  Represents the position inside the maze
class Point_2D {
private:
    int row;   // index of row 
    int col;   // index of column 
public:
    //Default constructor with position (0,0)
    Point_2D();
    // Parameterized constructor
    Point_2D(int r, int c);

    // Mutator Functions
    void setRow(int r);
    void setCol(int c);

    // Accessor Functions
    int getRow() const;
    int getCol() const;

    // Check whether two points are equal
    bool equals(const Point_2D& other) const;

    // Displays point as (row, col)
    void display() const;
};



//  Class: Maze_2D
//  Loads, stores and manages the NxN maze grid
class Maze_2D {
private:
    std::vector<std::vector<int>> maze_Data;  // 2D maze of 0s and 1s
    int num_Rows;                              // number of rows
    int num_Cols;                              // number of columns

public:
    // Constructor:reads maze from CSV file, throws on error
    Maze_2D(const std::string& filename);

    // Saves the maze to a file
    void saveToFile(const std::string& filename) const;

    // Displays the maze on screen
    void display() const;

    // Accessors
    int getNumRows() const;
    int getNumCols() const;
    int getCellValue(int row, int col) const;

    // Returns true if (row,col) is within maze boundaries
    bool is_Within_Bounds(int row, int col) const;

    // Returns true if (row,col) is a valid walkable cell
    bool is_Walkable(int row, int col) const;
};

//  Class: Path_1D
//  Loads, stores and manages the sequence of moves
class Path_1D {
private:
    std::vector<int> path_Data;

public:
    // Constructor: reads path from CSV file, throws on error
    Path_1D(const std::string& filename);

    // Saves the path to a file
    void saveToFile(const std::string& filename) const;

    // Displays path in human-readable form
    void display() const;

    // Accessors
    int getSize() const;
    int getMove(int index) const;
};

//  Class: Path_Traversal
//  Simulates walking through the maze following the path

class Path_Traversal {
private:
    Maze_2D* maze;                        
    Path_1D* path;                       
    std::vector<Point_2D> visited_Points; 
    Point_2D current_Location;            
    int current_Step;                   
    // Checks whether the point is already visited
    bool is_Already_Visited(const Point_2D& p) const;

public:
    // Constructor: takes pointers to existing maze and path objects
    Path_Traversal(Maze_2D* m, Path_1D* p);

    // Traverse exactly one step of the path
    // Throws exception if step is invalid
    void traverse_One_Step();

    // Returns true if current location is (N-1, N-1)
    bool has_Reached_End_Of_Maze() const;

    // Returns true if next move in path is 0
    bool has_Reached_End_Of_Path() const;

    // Returns the current step count
    int get_Current_Step() const;

    // Returns the current location
    Point_2D get_Current_Location() const;

    // Runs complete simulation and prints the result
    void simulate();
};

#endif 