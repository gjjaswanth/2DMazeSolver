#include "classes.h"
//Implementation of 1D path

// Constructor responsible for reading path from a CSV file
Path_1D::Path_1D(const std::string& filename) {

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("-E-: Error reading path file '" + filename + "'.");
    }

    bool visited_Path = false;  
    bool zero_Found = false;         
    std::string line;

    while (std::getline(file, line)) {
        line = trim_WhiteSpace(line);
        if (comment_check(line)) continue;
        // Checks for only one data line allowed in path file
        if (visited_Path) {
            throw std::runtime_error(
                "-E-: Path has already been read. "
                "Path file can't have multiple paths or non-comment rows."
            );
        }
        // Parsing comma-separated values
        std::stringstream ss(line);
        std::string token;
        while (std::getline(ss, token, ',')) {
            token = trim_WhiteSpace(token);
            // Converts the string to an integer
            int val;
            try {
                val = std::stoi(token);
            } catch (...) {
                throw std::runtime_error("-E-: Invalid path entry '" + token + "'.");
            }

            // Checks for the valid path entries
            if (!is_Valid_Path_Entry(val)) {
                throw std::runtime_error("-E-: Invalid path entry '" + token + "'.");
            }
            // Checks once we see a 0,remaining entries must be 0
            if (zero_Found && val != 0) {
                throw std::runtime_error(
                    "-E-: Invalid path. "
                    "Path can't have a non-zero entry after a string of zeroes."
                );
            }
            if (val == 0) zero_Found = true;
            path_Data.push_back(val);
        }
        visited_Path = true;
    }
    file.close();  //closes the file
}

// Saves the path to a file in CSV format
void Path_1D::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "-E-: Cannot open file for writing: " << filename << std::endl;
        return;
    }

    file << "# Path_1D saved file" << std::endl;
    for (int i = 0; i < (int)path_Data.size(); i++) {
        file << path_Data[i];
        if (i < (int)path_Data.size() - 1) file << ",";
    }
    file << std::endl;
    file.close(); //closes the file
}

// Displays the path in human readable form
void Path_1D::display() const {
    bool first = true;
    for (int i = 0; i < (int)path_Data.size(); i++) {
        if (path_Data[i] == 0) break;   // stops at first zero
        if (!first) std::cout << "\t";
        std::cout << move_To_String(path_Data[i]);
        first = false;
    }
    std::cout << std::endl << std::endl;
}

//Accessors
int Path_1D::getSize() const {
    return (int)path_Data.size();
}
int Path_1D::getMove(int index) const {
    return path_Data[index];
}