#include "classes.h"
// Implementation of Maze 2D

// Constructor: responsible for reading maze from a CSV file
// Throws std::runtime_error if anything is wrong
Maze_2D::Maze_2D(const std::string& filename) : num_Rows(0), num_Cols(0) {

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("-E-: Error reading maze file '" + filename + "'.");
    }
    std::string line;
    int expectedCols = -1;  

    while (std::getline(file, line)) {
        line = trim_WhiteSpace(line);
        if (comment_check(line)) continue;

        // Parses the CSV line into a row of integers
        std::vector<int> row;
        std::stringstream ss(line);
        std::string token;

        while (std::getline(ss, token, ',')) {
            token = trim_WhiteSpace(token);

            // Tries to convert token into an integer
            int val;
            try {
                val = std::stoi(token);
            } catch (...) {
                throw std::runtime_error("-E-: Invalid maze entry '" + token + "'.");
            }

            // Checks whether maze entry is 0 or 1
            if (!is_Valid_Maze_Entry(val)) {
                throw std::runtime_error("-E-: Invalid maze entry '" + token + "'.");
            }
            row.push_back(val);
        }

        // Checks whether all rows has the same number of columns
        if (expectedCols == -1) {
            // first row sets the expected column count
            expectedCols = (int)row.size();
        } else if ((int)row.size() != expectedCols) {
            throw std::runtime_error("-E-: All rows of the maze MUST have the same length.");
        }

        maze_Data.push_back(row);
    }

    file.close();// closes the file
    num_Rows = (int)maze_Data.size();
    num_Cols = expectedCols;

    // Checks whether rows and columns are same
    if (num_Rows != num_Cols) {
        throw std::runtime_error("-E-: #rows MUST be equal to #cols.");
    }

    // Checks for the top-left corner to be 1
    if (maze_Data[0][0] != 1) {
        throw std::runtime_error("-E-: The top left entry of the maze MUST be 1.");
    }
}

// Saves maze to a file in CSV format
void Maze_2D::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "-E-: Cannot open file for writing: " << filename << std::endl;
        return;
    }

    file << "# Maze_2D saved file" << std::endl;
    for (int i = 0; i < num_Rows; i++) {
        for (int j = 0; j < num_Cols; j++) {
            file << maze_Data[i][j];
            if (j < num_Cols - 1) file << ",";
        }
        file << std::endl;
    }
    file.close(); // file is being closed
}

// Displays the maze on screen with tabs between values
void Maze_2D::display() const {
    for (int i = 0; i < num_Rows; i++) {
        for (int j = 0; j < num_Cols; j++) {
            std::cout << maze_Data[i][j];
            if (j < num_Cols - 1) std::cout << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Accessors
int Maze_2D::getNumRows() const { return num_Rows; }
int Maze_2D::getNumCols() const { return num_Cols; }
int Maze_2D::getCellValue(int row, int col) const {
    return maze_Data[row][col];
}


// Checks if the point is inside within the maze grid
bool Maze_2D::is_Within_Bounds(int row, int col) const {
    return (row >= 0 && row < num_Rows && col >= 0 && col < num_Cols);
}

// Checks if path is walkable
bool Maze_2D::is_Walkable(int row, int col) const {
    return is_Within_Bounds(row, col) && (maze_Data[row][col] == 1);
}