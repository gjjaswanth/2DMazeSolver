#include "classes.h"
// removes extra spaces in start and end of a string
std::string trim_WhiteSpace(const std::string& line) {
    // finds the first non-space character
    int start = 0;
    while (start < (int)line.size() && isspace(line[start])) {
        start++;
    }

    // finds the last non-space character
    int end = (int)line.size() - 1;
    while (end >= start && isspace(line[end])) {
        end--;
    }
    //returns the trimmed portion
    return line.substr(start, end - start + 1);
}

//checks for the comment
bool comment_check(const std::string& line) {
    return line.empty() || line[0] == '#';
}

// checks for valid maze entry
bool is_Valid_Maze_Entry(int val) {
    return (val == 0 || val == 1);
}

// checks for valid path entry
bool is_Valid_Path_Entry(int val) {
    return (val >= 0 && val <= 4);
}

// converts the integer to string 
std::string move_To_String(int move) {
    switch (move) {
        case 1: return "Up";
        case 2: return "Right";
        case 3: return "Down";
        case 4: return "Left";
        default: return "Stop";
    }
}