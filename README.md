# 2D Maze Path Traversal Simulator

A C++ project that simulates traversal through a 2D maze using a predefined 1D movement path. The program validates the maze structure, checks path correctness, and reports traversal success or errors during execution.

---

# Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Maze Representation](#maze-representation)
- [Path Representation](#path-representation)
- [Traversal Rules](#traversal-rules)
- [Program Flow](#program-flow)
- [Input File Format](#input-file-format)
- [Compilation Instructions](#compilation-instructions)
- [Visual Studio Setup](#visual-studio-setup)
- [Example Output](#example-output)
- [Object-Oriented Concepts Used](#object-oriented-concepts-used)
- [Error Handling](#error-handling)
- [Future Improvements](#future-improvements)
- [Technologies Used](#technologies-used)
- [Author](#author)

---

# Overview

This project implements a maze traversal system using object-oriented programming concepts in C++. The maze is represented as a 2D grid containing walkable and blocked cells, while the traversal path is represented as a sequence of directional moves.

The program:

- Loads a maze from a CSV file
- Loads a traversal path from another CSV file
- Simulates movement step-by-step
- Detects invalid moves and traversal errors
- Reports successful or failed maze completion

The project is modular and uses multiple classes for clean implementation and separation of responsibilities.

---

# Features

- Object-Oriented Design
- Maze Validation
- Path Validation
- Boundary Checking
- Illegal Cell Detection
- Revisiting Detection
- Human Readable Path Display
- CSV File Support
- Exception Handling
- Modular Code Structure

---

# Project Structure

| File Name | Description |
|------------|-------------|
| `main.cpp` | Entry point of the program |
| `classes.h` | Class declarations and helper function prototypes |
| `Maze_2D.cpp` | Maze loading and validation |
| `Path_1D.cpp` | Path loading and validation |
| `Path_Traversal.cpp` | Maze traversal simulation |
| `Point_2D.cpp` | Coordinate handling |
| `Utils.cpp` | Helper utility functions |
| `README.txt` | Build instructions |

---

# Maze Representation

The maze is stored as a 2D matrix containing:

| Value | Meaning |
|------|---------|
| `1` | Walkable Cell |
| `0` | Blocked Cell |

Example:

```txt
1,1,0,1
0,1,1,1
0,0,1,0
1,1,1,1
```

Rules:

- Maze must be square (`N x N`)
- All rows must have equal length
- Top-left cell must be `1`

---

# Path Representation

The path is stored as a 1D sequence of moves.

| Value | Direction |
|------|------------|
| `1` | Up |
| `2` | Right |
| `3` | Down |
| `4` | Left |
| `0` | Stop |

Example:

```txt
2,2,3,3,4,0
```

---

# Traversal Rules

The traversal starts from the top-left corner `(0,0)`.

During simulation, the program checks:

- Maze boundary violations
- Movement into blocked cells
- Revisiting already traversed cells
- Path ending before reaching destination
- Path continuing after reaching destination

If any invalid condition occurs, the program throws an error message.

---

# Program Flow

1. Load maze file
2. Validate maze structure
3. Load path file
4. Validate path entries
5. Display maze
6. Display traversal path
7. Simulate traversal
8. Print final result

---

# Input File Format

## Maze File

Example:

```txt
1,1,1,0
1,0,1,1
1,1,1,1
0,1,1,1
```

## Path File

Example:

```txt
2,2,3,3,4,0
```

---

# Compilation Instructions

## Using g++

Compile the project using:

```bash
g++ main.cpp Maze_2D.cpp Path_1D.cpp Path_Traversal.cpp Point_2D.cpp Utils.cpp -o maze
```

Run the executable:

```bash
./maze Maze2D.dat Path1D.dat
```

---

# Visual Studio Setup

1. Create a new **Empty C++ Project**
2. Add all `.cpp` and `.h` files to the project
3. Go to:

```txt
Project > Properties > Debugging
```

4. Set **Command Arguments**:

```txt
Maze2D.dat Path1D.dat
```

5. Set **Working Directory**:

```txt
$(OutDir)
```

6. Copy `Maze2D.dat` and `Path1D.dat` into the output folder
7. Build and run the program

---

# Example Output

## Maze Display

```txt
1   1   0
1   1   1
0   1   1
```

## Path Display

```txt
Right   Down   Right   Down
```

## Successful Traversal

```txt
-I-: Path traversal completed successfully in 4 steps.
```

## Invalid Traversal Examples

```txt
-E-: Invalid path, taking it beyond the top edge of the maze after 3 steps.
```

```txt
-E-: Invalid path, visits an illegal cell (2,1) of the maze.
```

```txt
-E-: Invalid path, revisits a traversed path at coordinates (1,2).
```

---

# Object-Oriented Concepts Used

This project demonstrates:

- Classes and Objects
- Constructors
- Encapsulation
- Accessor and Mutator Functions
- Exception Handling
- Dynamic Memory Allocation
- Modular Programming
- Vector Containers
- File Handling

---

# Error Handling

The program throws runtime errors for:

- Invalid maze file
- Invalid path file
- Non-square maze
- Unequal row lengths
- Invalid maze values
- Invalid path values
- Boundary violations
- Illegal cell visits
- Revisiting cells

---

# Future Improvements

Possible future enhancements:

- Graphical Maze Visualization
- Automatic Path Finding Algorithms
- DFS/BFS Maze Solver
- Random Maze Generator
- Animated Traversal
- Colored Terminal Output
- Interactive User Input

---

# Technologies Used

- C++
- STL Vectors
- File Streams
- Exception Handling
- CSV Parsing

---

# Author

ECE Maze Traversal Project

Developed as part of an Object-Oriented Programming and Data Structures based maze traversal simulation project.

---
