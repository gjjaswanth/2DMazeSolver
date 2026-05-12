#include "classes.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0]
                  << " <maze_file> <path_file>" << std::endl;
        return 1;
    }
    std::string maze_File = argv[1];
    std::string path_File = argv[2];
    //Maze is being Loaded
    Maze_2D* maze = nullptr;
    try {
        maze = new Maze_2D(maze_File);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    //Path is being loaded
    Path_1D* path = nullptr;
    try {
        path = new Path_1D(path_File);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        delete maze;
        return 1;
    }

    //Displays Maze and Path
    maze->display();
    path->display();

    //Runs Path Simulation
    Path_Traversal pt(maze, path);
    try {
        pt.simulate();
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    //Deallocates maze and path
    delete maze;
    delete path;

    return 0;
}
