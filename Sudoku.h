#ifndef SUDOKU_H
#define SUDOKU_H
#include <vector>
#include <string>
using Grid = std::vector<std::vector<int>>;
class Sudoku {

public:

Sudoku(const std::string& filename);
    Sudoku(int cellsToRemove);


    
    bool solveSudoku();

    
    void printGrid() const;
        void generatePuzzle(int cellsToRemove);



private:
 bool isSafe(int row, int col, int num) const;
    
    Grid board;


};


#endif 