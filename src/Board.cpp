#include "Board.h"

#include <array>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
using std::string;



std::ostream& operator <<(std::ostream& output, Board& board)
{
    int prtSize = 4*board.getLimit();
    int lmt = board.getLimit();


    for(int rows{0}; rows < lmt; ++rows)
    {

        for(int columns{0}; columns < lmt; ++columns)
        {
            output << " " << (board.getBoard())[rows][columns] << " ";
            if(columns != (lmt - 1))
            {
                output << "|";
            }

        }

        if(rows != (lmt - 1))
        {

            output << std::endl << std::setfill('-') << std::setw(prtSize) ;
            output << "-";

        }
        output << std::endl;


    }

    return output;
}


std::istream& operator >>(std::istream&, Board&)
{

}


Board::Board()
{
    setBoards(3);
}


Board::Board(int length)
{
    setBoards(length);
}





void Board::setBoards(int limitSize)
{

    gameBoard = new string*[limitSize];
    inBoard = new bool*[limitSize];
    this->limitSize = limitSize;
    for(int ndx{0}; ndx < limitSize; ++ndx)
    {
        gameBoard[ndx] = new string[limitSize];
        inBoard[ndx] = new bool[limitSize];
    }

    for(int ndx{0}; ndx < limitSize; ++ndx)
    {
        for(int columns{0}; columns < limitSize; ++columns)
        {
            gameBoard[ndx][columns] = "-";
            

        }

    }

}



string** Board::getBoard()
{
    return gameBoard;

}

bool** Board::getInBoard()
{
    return inBoard;
}

int Board::getLimit()
{
    return limitSize;
}


