Build Instructions - ECE365 Maze2D Project
Files: classes.h, main.cpp, Utils.cpp, Point2D.cpp, Maze2D.cpp, Path1D.cpp, PathTraversal.cpp
Step 1: Create a new Empty C++ Project in Visual Studio
Step 2: Add all .h and .cpp files via Solution Explorer > Add > Existing Item
Step 3: Go to Project > Properties > Debugging > Command Arguments: Maze2D.dat Path1D.dat
Step 4: Go to Project > Properties > Debugging > Working Directory: $(OutDir)
Step 5: Copy Maze2D.dat and Path1D.dat into the x64\Debug\ output folder
Step 6: Press Ctrl+F5 to Build and Run the program
Step 7: Program accepts maze file and path file as command line arguments
