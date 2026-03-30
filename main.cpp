#include <iostream>
#include <string>
#include <limits>
#include "Sudoku.h"


int main() {
    
    int choice = 0;

    
    do {
        
        std::cout << "=====================================\n";
        std::cout << "   Welcome to C++ Sudoku Solver!   \n";
        std::cout << "=====================================\n\n";
        std::cout << "Please select an option from the menu:\n";
        std::cout << "  1. Solve a puzzle from a file\n";
        std::cout << "  2. Generate a new puzzle\n";
        std::cout << "  3. Exit\n\n";
        std::cout << "Enter your choice (1-3): ";

        std::cin >> choice;
        std::cout << std::endl;

        switch (choice) {
            case 1: {
                std::string filename;
                std::cout << "Please enter the puzzle filename (e.g., puzzle.txt): ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, filename);

                Sudoku filePuzzle(filename);

                std::cout << "\n--- Puzzle To Solve ---\n";
                filePuzzle.printGrid();
                std::cout << std::endl;

                if (filePuzzle.solveSudoku()) {
                    std::cout << "--- Solved Puzzle ---\n";
                    filePuzzle.printGrid();
                } else {
                    std::cout << "--------------------------\n";
                    std::cout << ">>> No solution exists <<<\n";
                    std::cout << "--------------------------\n";
                }
                std::cout << "\nPress Enter to return to the menu...";
                std::cin.get(); 
                break;
            }
            case 2: {
                std::cout << "Please select a difficulty level:\n";
                std::cout << "  1. Easy\n";
                std::cout << "  2. Medium\n";
                std::cout << "  3. Hard\n\n";
                std::cout << "Enter difficulty (1-3): ";

                int difficulty_choice;
                std::cin >> difficulty_choice;
                std::cout << std::endl;

                int cellsToRemove = 0;
                switch (difficulty_choice) {
                    case 1: cellsToRemove = 40; break;
                    case 2: cellsToRemove = 50; break;
                    case 3: cellsToRemove = 55; break;
                    default:
                        std::cout << "Invalid difficulty selected. Please choose 1, 2, or 3." << std::endl;
                        break;
                }

                if (cellsToRemove > 0) {
                    std::cout << "Generating your puzzle, please wait..." << std::endl;
                    Sudoku generatedPuzzle(cellsToRemove);
                    std::cout << "\n--- Your Generated Puzzle ---\n";
                    generatedPuzzle.printGrid();
                }
                std::cout << "\nPress Enter to return to the menu...";
                
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::cin.get();
                break;
            }
            case 3: {
                
                break;
            }
            default: {
                std::cout << "Invalid choice. Please select 1, 2, or 3." << std::endl;
                std::cout << "\nPress Enter to return to the menu...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                break;
            }
        }
        
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

    } while (choice != 3); 

    std::cout << "Thank you for using the Sudoku Solver. Goodbye!" << std::endl;

    return 0;
}