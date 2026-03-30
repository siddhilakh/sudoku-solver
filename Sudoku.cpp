#include "Sudoku.h"
#include <fstream>   
#include <iostream>  
#include <cstdlib> 
#include <algorithm> 
#include <random>

Sudoku::Sudoku(const std::string& filename)
   
    : board(9, std::vector<int>(9, 0))
    {
    
    std::ifstream inputFile(filename);

    if (inputFile.is_open()) {
        
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                inputFile >> board[r][c];
            }
        }
    } else {
std::cerr << "Error: Could not open puzzle file. Please ensure '" << filename << "' exists." << std::endl;
        exit(EXIT_FAILURE);
    }
    }
    Sudoku::Sudoku(int cellsToRemove)
    : board(9, std::vector<int>(9, 0))
{
    generatePuzzle(cellsToRemove);
}
    void Sudoku::printGrid() const {

    for (int r = 0; r < 9; ++r) {
        if (r % 3 == 0) {
            std::cout << "------+-------+------" << std::endl;
        }
        for (int c = 0; c < 9; ++c) {
            if (c % 3 == 0) {
                std::cout << "| ";
            }
            std::cout << board[r][c] << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "------+-------+------" << std::endl;
}
bool Sudoku::isSafe(int row, int col, int num) const {
    for (int c = 0; c < 9; ++c) {
        if (board[row][c] == num) {
            return false;
        }
    }

    for (int r = 0; r < 9; ++r) {
        if (board[r][col] == num) {
            return false;
        }
    }

   
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (board[startRow + r][startCol + c] == num) {
                return false;
            }
        }
    }

    return true;
}
bool Sudoku::solveSudoku() {
    int row = -1, col = -1;
    bool found_empty_cell = false;


    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (board[r][c] == 0) {
                row = r;
                col = c;
                found_empty_cell = true;
                break;
            }
        }
        if (found_empty_cell) {
            break;
        }
    }
    if (!found_empty_cell) {
        return true;
    }
    for (int num = 1; num <= 9; ++num) {
        
        if (isSafe(row, col, num)) {
            board[row][col] = num;

            if (solveSudoku()) {
                return true;
            }

            board[row][col] = 0;
        }
    }

    return false;
}

void Sudoku::generatePuzzle(int cellsToRemove) {
    this->board.assign(9, std::vector<int>(9, 0));
        solveSudoku();
            std::random_device rd;
    std::mt19937 engine(rd());
        std::uniform_int_distribution<int> distribution(0, 8);

int cells_removed = 0;
while (cells_removed < cellsToRemove) {
int row = distribution(engine);
        int col = distribution(engine);
        if (board[row][col] != 0) {
            
            board[row][col] = 0;

            cells_removed++;
        }
}

}