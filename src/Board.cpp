/*******************************
 * FileName: Board.cpp
 * Author: Osvaldo Borjas
 * Created: 4/8/24
 * Updates:
 *Last Updated(4/11/2024)
 *
 *
 *
 *
 *
 *
********************************/



#include "Board.h"

#include <array>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <exception>
#include <string>

using std::string;




//overloaded operators input and output
std::ostream& operator <<(std::ostream& output, Board& playBoard)//outputs the whole board in the usual tic tac toe format
{
    int prtSize = 1 + (4*playBoard.limitSize);//find out how many dashes to put based on board size
    int lmt = playBoard.limitSize;//set a variable to limit in order to reduce the amount of getlimit calls


    for(int rows{0}; rows < lmt; ++rows)
    {

        for(int columns{0}; columns < lmt; ++columns)
        {
            if(columns == 0)
            {
                output << " ";
            }
            output << " " << (playBoard.gameBoard)[rows][columns] << " ";
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


std::istream& operator >>(std::istream& input, Board& playBoard)
{
    if(playBoard.isFull() == false)
    {
        int row{0};
        int column{0};
        string player = playBoard.player;
        string cmptr = playBoard.cmptr;

        input >> row;
        input.ignore();
        input >> column;
        if(row >= playBoard.limitSize)
        {
            std::cout << "\n\nThat is out of bounds please try again\n\n";
            return input;
        }
        else if(column >= playBoard.limitSize)
        {
            std::cout << "\n\nThat is out of bouns please try again\n\n";
            return input;
        }

        if((playBoard.inBoard)[row][column] == false)
        {

            if(playBoard.whosPlay == true)
            {
                (playBoard.gameBoard)[row][column] = player;
                (playBoard.inBoard)[row][column] = true;
                playBoard.whosPlay = false;
                ++playBoard.inputCount;
                playBoard.gameCheck();
            }
            else
            {
                (playBoard.gameBoard)[row][column] = cmptr;
                (playBoard.inBoard)[row][column] = true;
                playBoard.whosPlay = true;
                ++playBoard.inputCount;
                playBoard.gameCheck();
            }
        }

        else if((playBoard.inBoard)[row][column] == true)
        {
            std::cout << "\nThat move is already played try again.\n";
        }

        return input;

    }

    else if(playBoard.isFull() == false)
    {
        "\n\nSorry board is full please check the board, input board, or input count\n\n";
    }


}


//friend operator to boot up the game
void startMenu(Board& playBoard)
{
    int inNum{2};
    std::cout << std::endl << "+" << std::setfill('-') << std::setw(26) << "+";
    std::cout << std::endl << "| WELCOME TO TIC-TAC-TOE! |";
    std::cout << std::endl << "+" << std::setfill('-') << std::setw(26) << "+";
    std::cout << "\n\n\n\n" << "\n1. PLAY THE GAME" << "\n2. EXIT GAME" << "\n\n" << "Enter Your Option: "  ;
    std::cin >> std::setw(2) >> inNum;
    if(inNum == 1)
    {


        playBoard.setGame();


    }

    else
    {
        std::cout << "THANKS FOR PLAYING!\n\n";

    }

}


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


Board::Board()//default constructor sets the playBoard to 3
{
    setBoards(3);
    inputCount = 0;

}



//gameFunctions


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



bool Board::isFull()//checking if the board is completely full
{
    int count{0};
    for(int rows{0};  rows < limitSize; ++rows)
    {
        for(int columns{0}; columns < limitSize; ++columns)
        {
            if(inBoard[rows][columns] == true)
            {
                ++count;
            }
        }
    }
    if(count == inputCount && inputCount == (limitSize*limitSize))
    {
        return true;
    }
    else
    {
        return false;
    }



}


int Board::gameCheck()//will be called after a move and check if there is a win or tie 1: is x the winner 2: is o the winner and 3 is a tie
{
    int xCount{0};
    int oCount{0};
    int count{0};


    for(int columns{0}; columns < limitSize; ++columns)//this loops throw the columns of the arrays
    {

        xCount = 0;
        oCount = 0;
        count = 0;

        for(int rows{0}; rows < limitSize; ++rows)
        {

            if(gameBoard[rows][columns] == "X")//checks the symbol and adds to the counter
            {
                ++xCount;
            }

            if(gameBoard[rows][columns] == "O")
            {
                ++oCount;
            }




            if(count%3 == 0 && count != 0)//after looping 3 times check both symbols and return a winner
            {
                if(xCount == 3)
                {
                    return 1;
                }

                else if(oCount == 3)
                {
                    return 2;
                }

                else
                {
                    xCount = 0;
                    oCount = 0;
                    count = 0;
                }


            }
        }

    }

    //restart counter

    for(int rows{0}; rows < limitSize; ++rows)//loops through the rows now
    {
        xCount = 0;
        oCount = 0;
        count = 0;


        for(int columns{0}; columns < limitSize; ++columns)
        {

            if(gameBoard[rows][columns] == "X")
            {
                ++xCount;
            }

            if(gameBoard[rows][columns] == "O")
            {
                ++oCount;
            }




            if(count%3 == 0 && count != 0)
            {
                if(xCount == 3)
                {
                    return 1;
                }

                else if(oCount == 3)
                {
                    return 2;
                }

                else
                {
                    xCount = 0;
                    oCount = 0;
                    count = 0;
                }


            }
        }





    }




    for(int columns{limitSize-1}; columns >= 0; --columns)//this loops throw the columns of the arrays
    {

        xCount = 0;
        oCount = 0;
        count = 0;

        for(int rows{limitSize-1}; rows >= 0; --rows)
        {

            if(gameBoard[rows][columns] == "X")//checks the symbol and adds to the counter
            {
                ++xCount;
            }

            if(gameBoard[rows][columns] == "O")
            {
                ++oCount;
            }




            if(count%3 == 0 && count != 0)//after looping 3 times check both symbols and return a winner
            {
                if(xCount == 3)
                {
                    return 1;
                }

                else if(oCount == 3)
                {
                    return 2;
                }

                else
                {
                    xCount = 0;
                    oCount = 0;
                    count = 0;
                }


            }
        }

    }

    //restart counter

    for(int rows{limitSize-1}; rows < limitSize; --rows)//loops through the rows now
    {
        xCount = 0;
        oCount = 0;
        count = 0;


        for(int columns{limitSize-1}; columns >= limitSize; --columns)
        {

            if(gameBoard[rows][columns] == "X")
            {
                ++xCount;
            }

            if(gameBoard[rows][columns] == "O")
            {
                ++oCount;
            }




            if(count%3 == 0 && count != 0)
            {
                if(xCount == 3)
                {
                    return 1;
                }

                else if(oCount == 3)
                {
                    return 2;
                }

                else
                {
                    xCount = 0;
                    oCount = 0;
                    count = 0;
                }


            }
        }





    }

    if(isFull() == true && xCount != 3 && oCount != 3)
    {
        return 3;
    }

    else
    {
        return 0;
    }







}

void Board::cmptrMove()//the computer plays a move randomly (THERE IS NO CHECK TO SEE IF IT IS ACTUALLY THE COMPUTER'S MOVE THAT IS DONE IN THE MAIN PROGRAM)
{



}

