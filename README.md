# 🧩 C++ Sudoku Solver & Generator

A fully functional command-line Sudoku Solver and Puzzle Generator built in C++ using Object-Oriented Programming and a recursive backtracking algorithm.
---

## ✨ Features

- ✅ Solve any valid Sudoku puzzle loaded from a `.txt` file
- ✅ Generate new Sudoku puzzles with 3 difficulty levels (Easy, Medium, Hard)
- ✅ Interactive CLI menu for smooth user experience
- ✅ Clean 9x9 grid display with proper row/column separators
- ✅ Robust file error handling
- ✅ Object-Oriented design using a `Sudoku` class

---

## 🛠️ Tech Stack

- **Language:** C++
- **Concepts Used:** Recursion, Backtracking Algorithm, OOP, File I/O, STL (vectors)
- **Tools:** g++ compiler, VS Code

---

## 📁 Project Structure

```
sudoku-solver/
├── main.cpp        # Entry point and interactive CLI menu
├── Sudoku.h        # Sudoku class declaration
├── Sudoku.cpp      # Sudoku class implementation
└── puzzle.txt      # Sample input puzzle file
```
## 🚀 How to Run

### Prerequisites
- g++ compiler installed
- Windows / Linux / Mac

### Compile
```bash
g++ main.cpp Sudoku.cpp -o sudoku
```

### Run
```bash
./sudoku
```

---

## 📋 Menu Options

```
=====================================
   Welcome to C++ Sudoku Solver!
=====================================

Please select an option from the menu:
  1. Solve a puzzle from a file
  2. Generate a new puzzle
  3. Exit
```

### Option 1 — Solve from file
Enter the filename (e.g., `puzzle.txt`) and the solver will display the original puzzle and then the solved solution.

### Option 2 — Generate a puzzle
Choose a difficulty level:
| Difficulty | Cells Removed |
|------------|--------------|
| Easy       | 40           |
| Medium     | 50           |
| Hard       | 55           |

---

## 📄 puzzle.txt Format

The input file should be a 9x9 grid of numbers where `0` represents an empty cell:

```
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

---

## 🧠 How the Solver Works

The solver uses a **recursive backtracking algorithm**:

1. Find the first empty cell (value = 0)
2. Try placing numbers 1–9 in that cell
3. Check validity using `isSafe()`:
   - No duplicate in the same **row**
   - No duplicate in the same **column**
   - No duplicate in the same **3x3 sub-grid**
4. If valid, place the number and recurse
5. If stuck, **backtrack** — reset the cell to 0 and try the next number
6. If no empty cell remains, the puzzle is **solved** ✅

---

## 🏗️ OOP Design

The project is structured around a `Sudoku` class:

| Member | Type | Description |
|--------|------|-------------|
| `Sudoku(filename)` | Constructor | Loads puzzle from file |
| `Sudoku(cellsToRemove)` | Constructor | Generates a new puzzle |
| `solveSudoku()` | Public method | Solves the puzzle using backtracking |
| `printGrid()` | Public method | Displays the 9x9 grid |
| `generatePuzzle()` | Public method | Generates puzzle by removing cells |
| `isSafe()` | Private method | Validates number placement |
| `board` | Private member | 2D vector storing the grid |

---

## 👩‍💻 Author

**Siddhi Lakh**  
B.Tech Computer Science & Engineering, 2nd Year  

[![GitHub](https://img.shields.io/badge/GitHub-siddhilakh-black?logo=github)](https://github.com/siddhilakh)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Siddhi-blue?logo=linkedin)](https://www.linkedin.com/in/siddhi-lakhotia-2b6138336)
