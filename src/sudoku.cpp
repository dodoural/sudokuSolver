#include "sudoku.hpp"


Sudoku::Sudoku(int board[][BOARDWIDTH]):sudokuBoard(board)
{
    
}
Sudoku::~Sudoku()
{

}
void Sudoku::playSudoku()
{
    if(!solveSudoku())
    std::cout<<"No known solution to this puzzle"<<std::endl;
    else
    {
         printSudokuBoard();
    }
    
}
bool Sudoku::solveSudoku()
{
    int row,column = 0;
    

    if (!findAvailableCell(&row,&column))
    {
        return true;
    }
    for(int num = 1 ; num <= BOARDWIDTH ; num++)
    {
        if(allChecker(num,row,column)) 
        {
            
            sudokuBoard[row][column] = num;
           // printSudokuBoard();
            if(solveSudoku())
            {
                return true;
            }
          
            sudokuBoard[row][column] = AVAILABLE;
        }
    }
   
    
    return false;

}

bool Sudoku::allChecker(int number,int row,int column)
{
    return  rowChecker(number,row) && columnChecker(number,column) && diameterChecker(number,row,column) && (sudokuBoard[row][column]== AVAILABLE);
}

bool Sudoku::rowChecker(int number,int row)
{
    int checkRow = row;
    for(int i=0;i<BOARDWIDTH;i++)
    {
        if(sudokuBoard[checkRow][i] == number)
        {
            return false;
        }
    }
    return true;
}

bool Sudoku::columnChecker(int number,int column)
{
    int checkColumn = column;
    for(int i=0;i<BOARDWIDTH;i++)
    {
        if(sudokuBoard[i][checkColumn] == number)
        {
            return false;
        }
    }
    return true;
}

bool Sudoku::diameterChecker(int number,int row,int column)
{
    int checkColumn = column;
    int checkRow = row;
    checkColumn = checkColumn - checkColumn%3;
    checkRow = checkRow - checkRow%3;

    for(int i = checkRow; i < checkRow+3 ; i++)
    {
        for(int j = checkColumn ;j < checkColumn+3 ; j++)
        {

            if(number == sudokuBoard[i][j])
                return false;
              
                
        }
    }
    return true;



}
bool Sudoku::findAvailableCell(int* row,int* column)
{
    for(int i = 0; i < 9 ; i++)
    {
        for(int j = 0 ;j < 9 ; j++)
        {
            if(sudokuBoard[i][j] == AVAILABLE)
            {
                *row = i;
                *column = j;
                return true;
            }    
                
        }
    }

    return false;
}

void Sudoku::printSudokuBoard()
{
     for(int i = 0; i < 9 ; i++)
    {
        for(int j = 0 ;j < 9 ; j++)
        {
            std::cout<<sudokuBoard[i][j]<<" ";           
        }

        std::cout<<""<<std::endl;
    }

    std::cout<<""<<std::endl;
    std::cout<<""<<std::endl;
}