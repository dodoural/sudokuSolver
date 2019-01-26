#ifndef SUDOKU_HPP
#define SUDOKU_HPP
#include <cstdlib>
#include <iostream>

#define AVAILABLE 0
#define BOARDWIDTH 9
class Sudoku
{
    private:
    int (*sudokuBoard)[BOARDWIDTH];
    bool rowChecker(int,int);
    bool columnChecker(int,int);
    bool diameterChecker(int,int,int);
    bool allChecker(int,int,int);
    bool findAvailableCell(int*,int*);
    void boardPrinter();
    bool solveSudoku();
    public:
    Sudoku(int [][BOARDWIDTH]);
    ~Sudoku();
    void playSudoku();
    void printSudokuBoard();
};

#endif