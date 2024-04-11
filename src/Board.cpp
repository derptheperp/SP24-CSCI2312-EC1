#include "Board.h"

#include <array>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <exception>
#include <string>

using std::string;




//overloaded operators input and output
std::ostream& operator <<(std::ostream& output, Board& gameBoard)//outputs the whole board in the usual tic tac toe format
{
    int prtSize = 1 + (4*gameBoard.getLimit());//find out how many dashes to put based on board size
    int lmt = gameBoard.getLimit();//set a variable to limit in order to reduce the amount of getlimit calls


    for(int rows{0}; rows < lmt; ++rows)
    {

        for(int columns{0}; columns < lmt; ++columns)
        {
            if(columns == 0)
            {
                output << " ";
            }
            output << " " << (gameBoard.getBoard())[rows][columns] << " ";
            if(columns != (lmt - 1))//put a | for each square except for the last one
            {
                output << "|";
            }

        }

        if(rows != (lmt - 1))//set a row for - for the bottom except the last row
        {

            output << std::endl << std::setfill('-') << std::setw(prtSize) ;
            output << "-";

        }
        output << std::endl;


    }

    return output;
}


std::istream& operator >>(std::istream& input, Board& gameBoard)
{

    int row{0};
    int column{0};
    bool whosPlay = gameBoard.getWhosPlay();
    string player = gameBoard.getPlayer();
    string cmptr = gameBoard.getCmptr();

    input >> row;
    input.ignore();
    input >> column;

    if((gameBoard.getInBoard())[row][column] == false)
    {
        if(whosPlay == true)
        {
            (gameBoard.getBoard())[row][column] = player;
            (gameBoard.getInBoard())[row][column] = true;
            whosPlay = false;
        }
        else
        {
            (gameBoard.getBoard())[row][column] = cmptr;
            (gameBoard.getInBoard())[row][column] = true;
            whosPlay = true;
        }
    }

    else if((gameBoard.getInBoard())[row][column] == true)
    {
        std::cout << "\nThat move is already played try again.";
    }

    return input;

}


//friend operator to boot up the game
void startMenu(Board& gameBoard)
{
    int inNum{2};
    std::cout << std::endl << "+" << std::setfill('-') << std::setw(26) << "+";
    std::cout << std::endl << "| WELCOME TO TIC-TAC-TOE! |";
    std::cout << std::endl << "+" << std::setfill('-') << std::setw(26) << "+";
    std::cout << "\n\n\n\n" << "\n1. PLAY THE GAME" << "\n2. EXIT GAME" << "\n\n" << "Enter Your Option: "  ;
    std::cin >> std::setw(2) >> inNum;
    if(inNum == 1)
    {
        gameBoard.setGame();
    }

    else
    {
        std::cout << "THANKS FOR PLAYING!\n\n";

    }

}




Board::Board()//default constructor
{
    setBoards(3);
}




//standard getters returning pointers and ints
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

bool Board::getWhosPlay()
{
    return whosPlay;
}

string Board::getPlayer()
{
    return player;
}

string Board::getCmptr()
{
    return cmptr;
}


//gameFunctions

void Board::setBoards(int limitSize)//sets the limit board and gameboard and their sizes
{

    gameBoard = new string*[limitSize];//assigns the string pointer pointer (gameBoard) to a new array
    inBoard = new bool*[limitSize];//same process as above but with bools
    this->limitSize = limitSize;
    for(int ndx{0}; ndx < limitSize; ++ndx)
    {
        gameBoard[ndx] = new string[limitSize];//indexe's through gameBoard's new array and fills it with another array created by new
        inBoard[ndx] = new bool[limitSize];//same process as above
    }

    for(int ndx{0}; ndx < limitSize; ++ndx)
    {
        for(int columns{0}; columns < limitSize; ++columns)
        {
            gameBoard[ndx][columns] = "-";//sets the 2d string array to - for empty slots in the board


        }

    }

}

void Board::setGame()
{
    string brdSize{"1"};
    std::cout << "\nENTER BOARD SIZE 3-10 ";
    try
    {
        std::cin >> brdSize;
        int test = stoi(brdSize);//can potentially throw invalid argument
        if(test >= 3 && test <= 10)
        {
            setBoards(test);
            std::cout << "\n\nOKAY! You Chose a " << test << "x" << test << " board!\n\n";
            setPlayers();



        }
        else
        {
            throw(test);//throws for number being out of range
        }

    }
    catch(std::invalid_argument)//catches the invalid argument and sets the starting menu again
    {
        std::cout << "\nThat is not a number try again!";
        setGame();
    }
    catch(int)//catches the custom out of range exception we set and does the function again
    {
        std::cout << "\nNumber out of range try again!";
        setGame();
    }

}


void Board::setPlayers()
{
    int playSymbol;
    std::cout << "1. X" << "\n2. O" <<"\nNow Choose Symbol:";
    std::cin >> std::setw(2) >> playSymbol;
    if(playSymbol == 1)
    {
        player = "X";
        cmptr = "O";
        std::cout << "\nYou chose X\n";
    }

    else
    {
        player = "O";
        cmptr = "X";
        std::cout << "\nYou Chose O\n";

    }
}